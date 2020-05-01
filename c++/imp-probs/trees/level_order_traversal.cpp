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

void level_order_traversal(node* root){
	if(root == NULL)
		return;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		for(int i =0; i<q.size(); i++){
			auto p = q.front();
			cout<<p->val<<" ";
			q.pop();
			if(p->left)
				q.push(p->left);
			if(p->right)
				q.push(p->right);
		}
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

    level_order_traversal(root);
	return 0;
}