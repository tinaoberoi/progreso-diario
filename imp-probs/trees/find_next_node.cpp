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

int helper(int key, node* root, int &value_level){
	queue<pair<node*, int>> q;
	q.push({root, 1});

	while(!q.empty()){
		int s = q.size();
		for(int i =0; i<s;i++){
			auto p = q.front();
			int level = p.second;
			node* n = p.first;
			q.pop();

			if(n->val == key){
				value_level = level;
			}else if(value_level && value_level == level){
				return n->val;
			}

			if(n->left){
				q.push({n->left, level+1});
			}
			if(n->right){
				q.push({n->right, level+1});
			}
		}
	}
	return 0;
}

void find_next_node(int key, node* root){
	if(root == NULL)
		return;
	int value_level = 0;
	int ans = helper(key, root, value_level);
	if(ans > 0){
		cout<<ans<<" "<<endl;
	}else{
		cout<<"NULL"<<endl;
	}

}

int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	//root->right->left = newnode(5);
	root->right->right = newnode(6);
	//root->left->left->left = newnode(8);
	//root->left->left->right = newnode(9);
	//root->left->right->left = newnode(10);
	//root->left->right->right = newnode(11);
	//root->right->left->left = newnode(7);
	//root->right->left->right = newnode(8);
	//root->right->right->left = newnode(7);
	//root->right->right->right = newnode(8);
	find_next_node(5, root);
	return 0;
}