#### Flatten Linked List

```
Node* merge(Node* a, Node* b){
        if(a == NULL){
            return b;
        }
        if(b == NULL){
            return a;
        }
        Node* res;
        if(a->data < b->data){
            res = a;
            res->bottom = merge(a->bottom, b);
        }
        else {
            res = b;
            res->bottom = merge(a, b->bottom);
        }
        res->next = NULL;
        return res;
    }
    Node *flatten(Node *root)
    {
        // Your code here
        if(root == NULL || root-> next == NULL){
            return root;
        }
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
```