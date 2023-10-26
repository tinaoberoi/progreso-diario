#include<bits/stdc++.h>
using namespace std;

bool isIdentical(node* p, node* q){
	if(p==NULL && q==NULL)
		return true;
	if(p==NULL || q==NULL)
		return false;
	return((p->val == q->val) && isIdentical(p->left, q->left) && isIdentical(p->right, q->right));
}

int main(){
	int n, q;
	cin>>n>>q;

	return 0;
}