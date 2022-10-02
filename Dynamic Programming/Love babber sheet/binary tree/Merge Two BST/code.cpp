#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int x){
        data=x;
        right=left=NULL;
    }
};
Node* createBST(vector<int>arr,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);
    root->left=createBST(arr,start,mid-1);
    root->right=createBST(arr,mid+1,end);
    return root;
}
void inorder(Node* root,vector<int>&temp){
    if(root==NULL){
        return;
    }
    inorder(root->left,temp);
    temp.push_back(root->data);
    inorder(root->right,temp);
    return;
}
Node* solve(Node* root1,Node* root2){
    vector<int>arr1;
    inorder(root1,arr1);
    vector<int>arr2;
    inorder(root2,arr2);
    int n=arr1.size();
    int m=arr2.size();
    vector<int>arr(n+m);
    int i=0,j=0,k=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            arr[k++]=arr1[i++];
        }else{
            arr[k++]=arr2[j++];
        }
    }
    while(i<n){
        arr[k++]=arr1[i++];
    }
    while(j<m){
        arr[k++]=arr2[j++];
    }
    
    auto ans=createBST(arr,0,arr.size()-1);
    return ans;
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
    Node* root1= new Node(100);
    root1->left= new Node(50);
    root1->right= new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    Node* root2=new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    auto root=solve(root1,root2);
    printInorder(root);
    return 0;
}