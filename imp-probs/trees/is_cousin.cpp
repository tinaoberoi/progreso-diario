/*
https://www.techiedelight.com/determine-two-nodes-are-cousins/
*/

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

void bfs(node* root, unordered_map<int, pair<int, int>>& map){
	if(root == NULL)
		return;
	queue<node*>q;
	q.push(root);
	int level = 1;
	while(!q.empty()){
		int s = q.size();
		for(int i =0; i<s; i++){
			auto p = q.front();
			q.pop();
			if(p->left){
				q.push(p->left);
				map[p->left->val] = {p->val, level+1};
				cout<<"when pushing left ";
				cout<<p->left->val<<" "<<map[p->left->val].first<<" "<<map[p->left->val].second<<endl;
			}
			if(p->right){
				q.push(p->right);
				map[p->right->val] = {p->val, level+1};
				cout<<"when pushing right ";
				cout<<p->right->val<<" "<<map[p->right->val].first<<" "<<map[p->right->val].second<<endl;
			}
		}

			level++;
	}
}

bool isCousin(node* root, int n1, int n2){
	unordered_map<int, pair<int, int>> map;
	bfs(root, map);
    
    map[root->val] = {-1, 0};
    //cout<<
	auto parent1 = map[n1].first;
	//cout<<parent1<<" ";
	auto parent2  = map[n2].first;
    //cout<<parent2<<" ";
	
	auto level1 = map[n1].second;
	//cout<<level1<<" ";
	auto level2  = map[n2].second;
	//cout<<level2<<" ";
	
	if(parent2 == parent1 || level1 != level2)
		return false;
	
	return true;

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
	int n1, n2;
	cin>>n1>>n2;
	cout<<"Answer"<<endl;
	cout<<isCousin(root, n1, n2)<<endl;
	return 0;
}