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

void delete_binary_tree(node* root){
	if(root == NULL)
		return;
	delete_binary_tree(root->left);
	delete_binary_tree(root->right);

	delete root;
	root = NULL;
}

int main(){
	struct node* root = newnode(15);
	root->left = newnode(10);
	root->right = newnode(20);
	root->left->left = newnode(8);
	root->left->right = newnode(12);
	root->right->left = newnode(16);
	root->right->right = newnode(25);
	cout<<root->val<<endl;
	delete_binary_tree(root);
	cout<<root->val;
	return 0;
}