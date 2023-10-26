/*
https://www.techiedelight.com/find-next-node-in-same-level-binary-tree/
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

/*
Method1
bool checkCompleteBinaryTree(node* root){
	if(root == NULL)
		return true;
	bool flag = false;
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		int s = q.size();
		for(int i =0; i<s; i++){
			auto p = q.front();
			q.pop();
			if(flag && (p->left || p->right))
				return false;
			if(p->left == NULL && p->right)
				return false;
			if(p->left)
				q.push(p->left)
			else
				flag = true;

			if(front->right)
				q.push(p->right);
			else
				flag = true;
		}
	}

	return true;
}
*/

int size(node* root){
	if(root == NULL)
		return 0;
	return 1+size(root->left)+size(root->right);
}

void inorderTraversal(node* root, int i, vector<bool>& arr){
	if(root == NULL){
		return;
	}

	inorderTraversal(root->left, 2*i+1, arr);
	arr[i] = true;
	inorderTraversal(root->right, 2*i+2, arr);

}

bool checkCompleteBinaryTree(node* root, int n){

	vector<bool> v(n, false);

	inorderTraversal(root, 0, v);

	for(auto it : v){
		if(!it){
			return false;
		}
	}
	return true;
}
int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	//root->right->left = newnode(6);
	root->right->right = newnode(6);
	//root->left->left->left = newnode(8);
	//root->left->left->right = newnode(9);
	//root->left->right->left = newnode(10);
	//root->left->right->right = newnode(11);
	//root->right->left->left = newnode(7);
	//root->right->left->right = newnode(8);
	//root->right->right->left = newnode(7);
	//root->right->right->right = newnode(8);
	cout<<checkCompleteBinaryTree(root, size(root))<<endl;
	return 0;
}