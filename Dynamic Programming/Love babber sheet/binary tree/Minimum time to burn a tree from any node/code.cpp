#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left,*right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};

int solve(map<Node*,Node*>mpp,Node* target){
    int maxi=0;
    queue<Node*>q;
    q.push(target);
    map<Node*,int>visit;
    visit[target]=1;
    while(!q.empty()){
        int n=q.size();
        int fl=0;
        for(int i=0;i<n;i++){
            auto x=q.front();
            q.pop();
            if(x->left && !visit[x->left]){
                visit[x->left]=1;
                fl=1;
                q.push(x->left);
            }
            if(x->right && !visit[x->right]){
                visit[x->right]=1;
                fl=1;
                q.push(x->right);
            }
            if(mpp[x] && !visit[mpp[x]]){
                visit[mpp[x]]=1;
                fl=1;
                q.push(mpp[x]);
            }
            
        }
        if(fl==1){
            maxi++;
        }
    }
    return maxi;
}

Node* BFS(Node* root,map<Node*,Node*>&mpp,int target){
    queue<Node*>q;
    q.push(root);
    Node* ans;
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            auto x=q.front();
            q.pop();
            if(x->data==target){
                ans=x;
            }
            if(x->left){
                q.push(x->left);
                mpp[x->left]=x;
            }
            if(x->right){
                q.push(x->right);
                mpp[x->right]=x;
            }
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    int B=4;
    map<Node*,Node*>mpp;// To store child to parent pointer for moving upward int tree
    auto target=BFS(root,mpp,B);
    int ans=solve(mpp,target);
    cout<<ans;
    return 0;
}