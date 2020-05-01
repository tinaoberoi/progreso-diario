/*
https://leetcode.com/problems/linked-list-in-binary-tree/
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

bool helper(ListNode* head, TreeNode* root){
	if(root==NULL && head==NULL)
		return true;
	if(root == NULL || root->val != head->val){
		return false;
	}
	auto left = helper(head->next, root->left);
	auto right = helper(head->next, root->right);

	return (left||right);
}

bool isSubPath(ListNode* head, TreeNode* root){
	if(root == NULL || head == NULL)
		return false;
	bool res = false;
	res = helper(head, root);
	if(!res)
		res = isSubPath(head, root->left);
	if(!res)
		res = isSubPath(head, root->right);
	return res;
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
	root->left = newnode(4);
	root->right = newnode(4);
	//root->left->left = newnode(4);
	root->left->right = newnode(2);
	root->right->left = newnode(2);
	//root->right->right = newnode(7);
	//root->left->left->left = newnode(8);
	//root->left->left->right = newnode(9);
	root->left->right->left = newnode(1);
	//root->left->right->right = newnode(11);
	root->right->left->left = newnode(6);
	root->right->left->right = newnode(8);
	root->right->left->right->left = newnode(1);
	root->right->left->right->right = newnode(3);
	//root->right->right->left = newnode(7);
	//root->right->right->right = newnode(8);
    inorder(pruneTree(root));
    return 0;
}