#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };
 int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
	int ans=-1;
	while(root){
		if(root->val==x){
			ans=root->val;
			return ans;
		}
		if(x<root->val){
			root=root->left;
		}
		else{
			ans=root->val;
			root=root->right;
		}
	}
	return ans;
}


int main(){
    
    return 0;
}