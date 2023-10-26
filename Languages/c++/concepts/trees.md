```c++
struct node{
	int data;
	struct node * left;
	struct node * right;
};

// creating simple nodes
struct node root;

//creating pointer to nodes

struct node * root;
root = (node *)malloc(sizeof(node));

// newnode functiom

struct node* newnode(element){
	struct node * temp;
	temp = (node *)malloc(sizeof(node));
	node->data = element;
	node->left = node->right = NULL;
	return node;
};

```
**Maximum Depth of a Tree**
complexity = O(n)

```c++
int maxDepth(struct node* root){
	if(node == NULL)
		return 0;
	else{
		int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        if(lDepth>rDepth)
        	return lDepth+1;
        else 
        	return rDepth+1;
	}
	
}
```