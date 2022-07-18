#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//  MAKING BINARY TREE STRUCTURE
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
//INORDER TRAVERSAL AND RETURNING VECTOR OF INORDER
void inorder(node *root,vector<int>&temp){
        if(root==NULL){
            return;
        }
        inorder(root->left,temp);
        temp.push_back(root->data);
        inorder(root->right,temp);
}
// INSERTING BINARY TREE
node* insertBSt(node *root,int val){
    if(root==NULL){
        return new node(val);
    }
    if(root->data > val){
        root->left=insertBSt(root->left,val);
    }
    else{
        root->right=insertBSt(root->right,val);
    }
    return root;
}
// CONVERTING BINARY TREE INTO LINKED LIST
node *head=NULL;
void flatten(node* root){
    if(root==NULL){
        return;
    }
    flatten(root->right);
    flatten(root->left);
    root->right=head;
    root->left=NULL;
    head=root;
}
// PRINTING FLATTENED LINKED LIST
void printlist(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printlist(root->right);
}
int main(){
    vector<int>arr={1,2,5,3,4,6};
    node *root=NULL;
    for(auto &i:arr){
        root=insertBSt(root,i);
    }
    vector<int>temp;
    flatten(root);
    // inorder(root,temp);
    // for(auto &t:temp){
    //     cout<<t<<" ";
    // }
    printlist(root);
    return 0;
}