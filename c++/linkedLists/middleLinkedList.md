##### Middle of LinkedList

Method1: Count the full length of linked list and then return the node at count/2

Method2: Use fast_pointer and slow_pointer
Where fast_ptr = fast_ptr->next->next
      slow_ptr = slow_ptr->next
      In case of even we will have 2 mid1 and mid2, return mid2
      When fast_ptr reach null or end ptr slow_ptr will be at mid

```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        
        while(fast_ptr != NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        cout<<slow_ptr->val<<endl;
        return slow_ptr;
    }
};
```
