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

void left_view(node* root){
	if(root == NULL)
		return;

	queue<node*> q;
	q.push(root);
	bool level = 0;

	while(!q.empty()){
		
		int z = q.size();
		for(int i =0; i<z; i++){
			auto p = q.front();
			if(!level){
				cout<<p->val<<" ";
				level= !level;
			}
			q.pop();

			if(p->left != NULL){
				q.push(p->left);
			}
			if(p->right != NULL)
				q.push(p->right);
		}

		level = !level;
	}
}

void right_view(node* root){
	if(root == NULL)
		return;
	queue<node *>q;
	q.push(root);
	bool level = 0;

	while(!q.empty()){
		int z = q.size();
		for(int i =0; i<z; i++){
			auto p = q.front();
			if(!level){
				cout<<p->val<<" ";
				level=!level;
			}
			q.pop();

			if(p->right != NULL)
				q.push(p->right);
			if(p->left != NULL){
				q.push(p->left);
			}
		}
		level = !level;
	}
}

void bottom_view(node* root){
	
}

int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	//root->left->left = newnode(4);
	root->left->right = newnode(4);
	root->right->left = newnode(5);
	root->right->right = newnode(6);
	//root->left->left->left = newnode(8);
	//root->left->left->right = newnode(9);
	//root->left->right->left = newnode(10);
	//root->left->right->right = newnode(11);
	root->right->left->left = newnode(7);
	root->right->left->right = newnode(8);
	//root->right->right->left = newnode(14);
	//root->right->right->right = newnode(15);
	cout<<"Left View of Tree"<<endl;
	left_view(root);
	cout<<"Right View of Tree"<<endl;
	right_view(root)	;
    return 0;
}