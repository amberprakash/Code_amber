#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left,*right;
    Node(int x){
        data=x;
        left=right=NULL;
    }
};
Node* LCA(Node* root,int a,int b){
    if(root==NULL){
        return NULL;
    }
    if(root->data==a){
        return root;
    }
    if(root->data==b){
        return root;
    }
    Node* l=LCA(root->left,a,b);
    Node* r=LCA(root->right,a,b);
    if(l!=NULL && r!=NULL){
        return root;
    }
    else if(l==NULL && r!=NULL){
        return r;
    }else if(l!=NULL && r==NULL){
        return l;
    }
    return NULL;
}
void printInorder(Node* root){
    if(root==NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
    return;
}
int main(){
    Node* root = new Node(5);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right=new Node(6);
    // auto x=LCA(root,3,6);
    // cout<<x->data;
    printInorder(root);
    return 0;
}