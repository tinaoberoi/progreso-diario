/*
https://www.techiedelight.com/reverse-level-order-traversal-binary-tree/
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

void reverselevel_order_traversal(node* root){
	if(root == NULL)
		return;
	stack<int> s;
	queue<node*> q;
	q.push(root);
	bool dir = false;

	while(!q.empty()){
		int z = q.size();
		for(int i =0; i<z; i++){
			auto p = q.front();
			s.push(p->val);
			q.pop();

			if(p->right != NULL){
				q.push(p->right);
			}
			if(p->left != NULL){
				q.push(p->left);
			}
		}
	}

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
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

    reverselevel_order_traversal(root);
	return 0;
}