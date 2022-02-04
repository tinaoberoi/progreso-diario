### Check for loop and count length of the loop
Approach: Use Floyd's algorithm and once the loop is detected, store that pointer in temp,Initialize a counter count = 0. Increase count until temp again reaches the loop pointer.
```
int countNodes(struct Node *n)
{
    int res = 1;
    struct Node *temp = n;
    while (temp->next != n)
    {
        res++;
        temp = temp->next;
    }
    return res;
}
 
/* This function detects and counts loop
nodes in the list. If loop is not there
in then returns 0 */
int countNodesinLoop(struct Node *list)
{
    struct Node *slow_p = list, *fast_p = list;
 
    while (slow_p && fast_p &&
                     fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
 
        /* If slow_p and fast_p meet at
        some point then there is a loop */
        if (slow_p == fast_p)
            return countNodes(slow_p);
    }
 
    /* Return 0 to indicate that
       there is no loop*/
    return 0;
}
```