#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
node* insertBST(node *root,int val){
    if(root==NULL){
      return new node(val);
    }
    if(val > root->data){
        root->right=insertBST(root->right,val);
    }
    else{
        root->left=insertBST(root->left,val);
    }
    return root;
}
unordered_set<int>s;
bool findTarget(node *root,int k){
    if(root==NULL){
        return false;
    }
    if(s.count(k - root->data)){
        return true;
    }
    s.insert(root->data);
    return (findTarget(root->left,k) || findTarget(root->right,k));

}
int main(){
    vector<int>arr={5,3,6,2,4,7};
    node *root=NULL;
    for(auto &i:arr){
        root=insertBST(root,i);
    }
    int k;
    cin>>k;
    cout<<findTarget(root,k);
    return 0;
}