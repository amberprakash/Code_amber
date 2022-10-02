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
unordered_map<int,int>mp;
void solve(Node* root,int &ans,int sum,int k){
    if(root==NULL){
        return;
    }
    sum+=root->data;
    if(sum==k){
        ans++;
    }
    if(mp.find(sum-k)!=mp.end()){
        ans+=mp[sum-k];
    }
    mp[sum]++;
    solve(root->left,ans,sum,k);
    solve(root->right,ans,sum,k);
    mp[sum]--;
    if(mp[sum]==0){
        mp.erase(sum);
    }
    sum-=root->data;
    return;
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
    int k;
    cin>>k;
    int ans=0;
    solve(root,ans,0,k);
    cout<<ans;

    return 0;
}