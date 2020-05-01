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

void specific_order(struct node* root){
	if(root == NULL)
		return;
	cout<<root->val<<" ";

	queue<node *>q1, q2;
	if(root->left != NULL){
		q1.push(root->left);
	}
	if(root->right != NULL){
		q2.push(root->right);
	}

	while(!q1.empty() && !q2.empty()){
		auto p1 = q1.front();
		cout<<p1->val<<" ";
		q1.pop();

		if(p1->left != NULL)
			q1.push(p1->left);
		if(p1->right != NULL)
			q1.push(p1->right);

		auto p2 = q2.front();
		cout<<p2->val<<" ";
		q2.pop();

		if(p2->left != NULL)
			q2.push(p2->right);
		if(p2->right != NULL)
			q2.push(p2->left);

	}
}

int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	root->left->left->left = newnode(8);
	root->left->left->right = newnode(9);
	root->left->right->left = newnode(10);
	root->left->right->right = newnode(11);
	root->right->left->left = newnode(12);
	root->right->left->right = newnode(13);
	root->right->right->left = newnode(14);
	root->right->right->right = newnode(15);
	
	specific_order(root);
    return 0;
}