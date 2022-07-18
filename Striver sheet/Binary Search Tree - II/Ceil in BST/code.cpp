#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };
int findCeil(BinaryTreeNode<int> *root, int key){
    // Write your code here.
	int ans=-1;
	while(root){
		if(root->data==key){
			ans=root->data;
			return ans;
		}
		if(key>root->data){
			root=root->right;
		}
		else{
			ans=root->data;
			root=root->left;
		}
	}
	return ans;
}
int main(){
    
    return 0;
}