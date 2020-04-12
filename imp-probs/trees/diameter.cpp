/*
Why lheight+rheight+1 does not work for all ?

It is also possible that the farthest nodes are present in left subtree only.

Reference Video:
https://www.youtube.com/watch?v=rrXAISjtbAA
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node* right;
};

struct node* newnode(int elem){
	struct node* temp;
	temp = (node*)malloc(sizeof(node));

	temp->data = elem;
	temp->left = temp->right = NULL;

	return temp;
}

void print_tree(struct node* root){
	if(root == NULL)
		return;
	
	cout<<root->data<<endl;
	print_tree(root->left);
	print_tree(root->right);
}

int height(struct node* node){
	if(node == NULL)
		return 0;
	else
	{
		int lheight = height(node->left);
		int rheight = height(node->right);
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;
    }

}

int diameter(struct node* node){
	if(node == NULL)
		return 0;

	int lheight = height(node->left);
	int rheight = height(node->right);
	
	int lDiam = diameter(node->left);
	int rDiam = diameter(node->right);
	
	return (max(lheight+rheight+1, max(lDiam, rDiam)));
}

void printPreorder(struct node* node) 
{ 
    if (node == NULL) 
        return; 
  
    if (node == NULL) 
        return; 
  
    /* first print data of node */
    cout << node->data << " "; 
  
    /* then recur on left sutree */
    printPreorder(node->left); 
  
    /* now recur on right subtree */
    printPreorder(node->right);  
}

int main(){
	int t,x;
	cin>>t>>x;
	struct node * root = newnode(x);
	string s;
	int val;
	t--;
	while(t--){
		struct node * temp = root;
		cin>>s;
		cin>>val;
		int i;
		for(i =0; i<s.length()-1; i++){
			if(s[i] == 'L'){
				temp = temp->left;
			}else{
				temp = temp->right;
			}
		}
		cout<<temp->data<<" "<<s[i]<<endl;
		if(s[i] == 'L'){
			temp->left = newnode(val);
		}else{
			temp->right = newnode(val);
		}
	}
	//printPreorder(root);
	//print_tree(root);
	cout<<diameter(root)<<endl;
	return 0;
}