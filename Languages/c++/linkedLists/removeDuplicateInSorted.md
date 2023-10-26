###### Remove duplicates in sorted linked list

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        ListNode* next_next = NULL;
        if(curr == NULL)
            return head;
        while(curr->next != NULL){
            if(curr->val == curr->next->val){
                next_next = curr->next->next;
                delete(curr->next);
                curr->next = next_next;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
```
Time Complexity : O(n)