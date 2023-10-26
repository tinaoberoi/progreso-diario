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

void inorder(node* root){
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void postorder(node* root){
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
}

void preorder(node* root){
	if(root == NULL)
		return;

	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

int main(){
	struct node* root = newnode(15);
	root->left = newnode(10);
	root->right = newnode(20);
	root->left->left = newnode(8);
	root->left->right = newnode(12);
	root->right->left = newnode(16);
	root->right->right = newnode(25);

    cout<<"Inorder"<<endl;
    inorder(root);
    cout<<"Preorder"<<endl;
    preorder(root);
    cout<<"Postorder"<<endl;
    postorder(root);

	return 0;
}