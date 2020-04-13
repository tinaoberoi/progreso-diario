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

void spiral_order_traversal(node* root){
	if(root == NULL)
		return;
	stack<node*> s;
	s.push(root);
	bool dir = false;

	while(!s.empty()){
		stack<node*> temps;
		int z = s.size();
		for(int i =0; i<z; i++){
			auto p = s.top();
			cout<<p->val<<" ";
			s.pop();

			if(!dir){
				if(p->left != NULL){
					temps.push(p->left);
				}
				if(p->right != NULL){
					temps.push(p->right);
				}
			}else if(dir){
				if(p->right != NULL){
					temps.push(p->right);
				}
				if(p->left != NULL){
					temps.push(p->left);
				}
			}
		}
		dir = !dir;
		s = temps;
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

    spiral_order_traversal(root);
	return 0;
}