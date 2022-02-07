###### Check if Linked List has a palindrome or not
Approach 1: Push all the elements of linked list in the stack.
Then iterate again through the linked list with the elects in the stack 

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        stack<int> s;
        
        while(slow != NULL){
            s.push(slow->val);
        }
        slow=slow->next;
        
        while(head != NULL){
            int i = s.top();
            s.pop();
            if(head->val != i)
                return false;
            head = head->next;
        }
        return true;
    }
};
```
Time Complexity: O(n)
Space Complexity: O(n)

Approach2: In the above case we needed extra space, to avoid taking extra space, we can reverse the second half of the linked list and then compare

Step1: Find the mid node using slow and fast ptr approach. Also store the prev of slow ptr in order to break the linked list into two
Step2: In case of even linked list the slow ptr is the  other half, but in case of odd (fast ptr != NULL) then you need to store the mid node and reverse the remaining to check
Step3: reverse the other half and

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
    void reverse (ListNode** head){
        ListNode* current = *head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head = prev;
    }
    bool check(ListNode* first, ListNode* sec){
        while(first != NULL && sec != NULL){
            if(first->val != sec->val)
                return false;
            first = first->next;
            sec = sec->next;
        }
        if(first == NULL && sec == NULL)
            return true;
        
        return false;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        ListNode* slow_ptr = head;
        ListNode* secondhalf;
        ListNode* fast_ptr = head;
        ListNode* prev_slow_ptr = head;
        ListNode* midnode = NULL;
        while( fast_ptr != NULL  && fast_ptr->next != NULL){
            fast_ptr = fast_ptr->next->next;
            prev_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        //when odd
        if(fast_ptr != NULL){
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        secondhalf = slow_ptr;
        prev_slow_ptr->next = NULL;
        reverse(&secondhalf);
        return check(head, secondhalf);
    }
};
```
Time Complexity: O(n)
Space Complexity: O(1)