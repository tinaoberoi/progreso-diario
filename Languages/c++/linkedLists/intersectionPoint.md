#### given two linked list find the intersection point or common point between the two

```
int getCount(Node* head){
        Node* current = head;
        int count = 0;
        while(current != NULL){
            count++;
            current = current->next;
        }
        return count;
    }
    
    int intersectPointHelper(Node* lhead1, Node* shead2, int d){
        Node* lcurrent = lhead1;
        Node* scurrent = shead2;
        
        for(int i =0; i<d; i++){
            if(lcurrent == NULL){
                return -1;
            }
            lcurrent = lcurrent->next;
        }
        while(lcurrent != NULL && scurrent != NULL){
            if(lcurrent == scurrent){
                return lcurrent->data;
            }
            lcurrent = lcurrent->next;
            scurrent = scurrent->next;
        }
    }
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        int c1 = getCount(head1);
        //cout<<c1<<endl;
        int c2 = getCount(head2);
        //cout<<c2<<endl;
        if(c1>c2){
            int d = c1-c2;
            return intersectPointHelper(head1, head2, d);
        } else {
            int d = c2-c1;
            return intersectPointHelper(head2, head1, d);
        }
    }
```