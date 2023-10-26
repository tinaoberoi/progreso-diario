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

int height(node* root){
	if(root == NULL)
		return 0;
	else{
		int lH = height(root->left);
		int rH = height(root->right);

		if(lH > rH )
			return lH+1;
		else
			return rH+1;
	}
}

int main(){
	struct node* root = newnode(15);
	root->left = newnode(10);
	root->right = newnode(20);
	root->left->left = newnode(8);
	root->left->right = newnode(12);
	root->right->left = newnode(16);
	root->right->right = newnode(25);

	cout << height(root)<<endl;
	return 0;
}