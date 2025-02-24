//Reverse List
struct ListNode* reverseList(struct ListNode* head) 
{
    struct ListNode *previous = NULL, *current = head, *next = NULL;

    while (current)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    return previous;
}

//Remove Linked List Element
struct ListNode* removeElements(struct ListNode* head, int val) 
{
    struct ListNode temp;
    temp.next = head;
    struct ListNode *previous = &temp, *current = head;

    while(current)
    {
        struct ListNode *nxt = current->next;

        if (current->val == val)
        {
            previous->next = nxt;
            free(current);

        }
        else
        {
            previous = current;
        }

        current = nxt;
    }

    return temp.next;
}
