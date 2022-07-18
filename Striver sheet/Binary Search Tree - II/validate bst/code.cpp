#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
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
bool validateBST(node *root,int l,int h){
    if(root==NULL){
        return 1;
    }
    if(root->data<=l || root->data >= h){
        return false;
    }
    return (validateBST(root->left,l,root->data) && validateBST(root->right,root->data,h));

}
int main(){
    vector<int>arr={10,40,45,20,25,30,50};
    int n=arr.size();
    node *root=NULL;
    for(auto &i:arr){
        root=insertBST(root,i);
    }
    cout<<validateBST(root,INT_MIN,INT_MAX);
    return 0;
}