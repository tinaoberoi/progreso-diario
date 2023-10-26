##### Check if linkedList has cycle

Method1: hashing
Store the nodes in a set/map
If its already present(when encountered the second time) return true

```

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> s;
        while(head != NULL){
            if(s.find(head) != s.end())
                return true;
            s.insert(head);
            head = head->next;
        }
        return false;
    }
};
```
Time Complexity O(n)
Space Complexity O(n)

Method2: If I could change Node structure I can associate a flag with every node "flag", and mark it visited
Method3: Floyds cycle finding algorithm
Traverse linked list using two pointers.
Move one pointer(slow_p) by one and another pointer(fast_p) by two.
If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
```
bool hasCycle(ListNode *head) {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;
        
        while(fast_ptr != NULL && slow_ptr!= NULL && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            if(slow_ptr == fast_ptr)
                return true;
        }
        return false;
    }
```
Time complexity: O(n). 
Only one traversal of the loop is needed.
Auxiliary Space:O(1). 
There is no space required.