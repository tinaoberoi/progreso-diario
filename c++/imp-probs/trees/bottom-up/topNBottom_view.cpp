/*
https://www.techiedelight.com/print-top-view-binary-tree/
https://www.techiedelight.com/print-bottom-view-of-binary-tree/
*/
#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	struct node * left;
	struct node * right;
};

struct node * newnode(int element){
	struct node* temp;
	temp = (node*)malloc(sizeof(node));

	temp->val = element;
	temp->right=temp->left=NULL;

	return temp;
}

void helper(node* root, int dist, int level, map<int, pair<int, int>>& m){
	if(root == NULL)
		return;

	if(level >= m[dist].second){
		m[dist] = {root->val, level};
	}

	helper(root->left, dist-1, level+1, m);
	helper(root->right, dist+1, level+1, m);
}

void bottom_view(node * root){
	if(root == NULL)
		return;

	map<int, pair<int, int>> m;

	helper(root, 0, 0, m);

	for(auto it: m){
		cout<<it.second.first<<" ";
	}
}

void helpertop(node* root, int dist, int level, map<int, pair<int, int>>& m){
	if(root == NULL)
		return;
	if(m.find(dist) == m.end() || level <= m[dist].second){
		m[dist] = {root->val, level};
	}

	helpertop(root->left, dist-1, level+1, m);
	helpertop(root->right, dist+1, level+1, m);
}

void top_view(node* root){
	if(root == NULL)
		return;
	map<int, pair<int, int>> map;
	helpertop(root, 0, 0, map);

	for(auto it: map){
		cout<<it.second.first<<" ";
	}
}

int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	//root->left->left = newnode(4);
	//root->left->right = newnode(4);
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
	//bottom_view(root);
	top_view(root);
	return 0;
}