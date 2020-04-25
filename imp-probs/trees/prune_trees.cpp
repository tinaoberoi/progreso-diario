/*
https://leetcode.com/problems/binary-tree-pruning/
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	struct node* left;
	struct node* right;
};

struct node* newnode(int elem){
	struct node* temp;
	temp = (node*)malloc(sizeof(node));

	temp->val = elem;
	temp->left = temp->right = NULL;

	return temp;
}

node* pruneTree(node* root){
	if(root == NULL)
		return NULL;
	root->left = pruneTree(root->left);
	root->right = pruneTree(root->right);

	if(root->val == 0 && root->right == NULL && root->left == NULL)
		return NULL;

	return root;
}

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    struct node* root = newnode(1);
    root->right = newnode(0);
    root->right->left = newnode(0);
    root->right->right = newnode(1);

    inorder(pruneTree(root));
    return 0;
}