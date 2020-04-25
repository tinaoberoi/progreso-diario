/*
https://leetcode.com/problems/delete-nodes-and-return-forest/
*/

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* newnode(int elem){
	struct TreeNode* temp;
	temp = (TreeNode*)malloc(sizeof(TreeNode));

	temp->val = elem;
	temp->left = temp->right = NULL;

	return temp;
}

void delnodeshelper(TreeNode*& root, unordered_set<int>& del_set, std::vector<TreeNode*>& ans){
	if(!root)
		return;
	delnodeshelper(root->left, del_set, ans);
	delnodeshelper(root->right, del_set, ans);
	if(del_set.count(root->val)){
		if(root->left) ans.push_back(root->left);
		if(root->right) ans.push_back(root->right);
		root = NULL;
	}
}

vector<TreeNode*> delnodes(TreeNode* root, vector<int>& to_delete){
	unordered_set<int> del_set(to_delete.begin(), to_delete.end());
	std::vector<TreeNode*> ans;
	delnodeshelper(root, del_set, ans);
	if(root)
		ans.push_back(root);
	return ans;

}

void inorder(TreeNode* root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int main(){
	struct TreeNode* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	vector<int> v = {3, 5};
	vector<TreeNode*> ans = delnodes(root, v);
	for(auto i : ans){
		inorder(i);
		cout<<endl;
	}
	return 0;
}