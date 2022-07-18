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
void inorder(node *root,vector<int>&temp){
    if(root==NULL){
        return;
    }
    inorder(root->left,temp);
    temp.push_back(root->data);
    inorder(root->right,temp);
}
int valL;
int valS;
int ansLarge;
int ansSmall;
void kthlarge(node* root){
    if(root==NULL){
        return;
    }
    kthlarge(root->right);
    valL--;
    if(valL==0){
        ansLarge=root->data;
    }
    kthlarge(root->left);
}
void kthsmall(node* root){
    if(root==NULL){
        return;
    }
    kthsmall(root->left);
    valS--;
    if(valS==0){
        ansSmall=root->data;
    }
    kthsmall(root->right);
}

int main(){
    // vector<int>arr={10,40,45,20,25,30,50};
    vector<int>arr={10,9,8,7,6,5,4,3,2,1};
    node* root=NULL;
    int n=arr.size();
    for(auto &i:arr){
        root=insertBST(root,i);
    }
    vector<int>temp;
    inorder(root,temp);
    for(auto &i:temp){
        cout<<i<<" ";
    }
    int k=3;
    valL=k;
    kthlarge(root);
    cout<<"\nLargest Kth Element in BST: "<<ansLarge<<endl;
    valS=k;
    kthsmall(root);
    cout<<"Smallest Kth Element in BST: "<<ansSmall<<endl;
    return 0;
}