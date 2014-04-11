/*core low-level coding*/
/*
    if (prev)
        prev->next = entry->next;
    else
        list_head = entry->next;
    了解指针的人会使用链表头的地址初始化一个指向节点指针的指针
    遍历链表的时候，就不需要任何的判断操作
    *pp = entry->next;
*/

typedef struct node
{
    struct node * next;
} node;
 
typedef bool (* remove_fn)(node const * v);
 
// Remove all nodes from the supplied list for which the
// supplied remove function returns true.
// Returns the new head of the list.
node * remove_if(node * head, remove_fn rm)
{
    for (node * prev = NULL, * curr = head; curr != NULL; )
    {
        node * const next = curr->next;
        if (rm(curr))
        {
            if (prev)
                prev->next = next;
            else
                head = next;
            free(curr);
        }
        else
            prev = curr;
        curr = next;
    }
    return head;
}

//对比更改后的代码

void remove_if(node ** head, remove_fn rm)
{
    for (node** curr = head; *curr; )
    {
        node * entry = *curr;
        if (rm(entry))
        {
            *curr = entry->next;
            free(entry);
        }
        else
            curr = &entry->next;
    }
}
