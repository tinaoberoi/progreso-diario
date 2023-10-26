/*
https://www.techiedelight.com/print-cousins-of-given-node-binary-tree/
cousins = different parent but same level
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



void find_level(node* root,int key,  int& level){
	if(root == NULL)
		return;
	if(root->val == key)
		leve
	level(root->left, key, level+1);
	level(root->right, key, level+1);

}

void bfs(node* root, unordered_map<int, int>>& map){
	if(root == NULL)
		return;
	queue<node*>q;
	q.push(root);
	int level = 1;
	while(!q.empty()){
		int s = q.size();
		vector<int> temp = map[level];
		for(int i =0; i<s; i++){
			auto p = q.front();
			temp.push_back(p->val);
			q.pop();
			if(p->left){
				q.push(p->left);
			}
			if(p->right){
				q.push(p->right);
			}
		}
		level++;

	}
}

void printCousinshelper(node* root, int level, int index, int key, int parent,unordered_map<int, int> map ){
	if(index == level && map[root->val] != parent)
		cout<<root->val<<" ";
	printCousinshelper(root->left, level, index+1, key, parent, map);
	printCousinshelper(root->right, level, index+1, key, parent, map);
}

void printCousins(node* root, int n1){
	int level = 1;
	find_level(root, n1, level);

	unordered_map<int, int> parent_map;
	bfs(root, parent_map);

	int parent = parent_map[n1];
    printCousinshelper(root, level, 1, n1, parent, parent_map);

    
}

int main(){
	struct node* root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->left = newnode(6);
	root->right->right = newnode(7);
	//root->left->left->left = newnode(8);
	//root->left->left->right = newnode(9);
	//root->left->right->left = newnode(10);
	//root->left->right->right = newnode(11);
	//root->right->left->left = newnode(7);
	//root->right->left->right = newnode(8);
	//root->right->right->left = newnode(7);
	//root->right->right->right = newnode(8);
	int n1;
	cin>>n1;
	cout<<"Answer"<<endl;
	printCousins(root, n1);
	return 0;
}