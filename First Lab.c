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
