#include <stdio.h>

typedef struct ListNodeTag {
	int value;
	struct ListNodeTag *next;
} ListNode;

void printList(ListNode* n)
{
    while (n != NULL)
    {
        printf("%d", n->value);
        if (n->next != NULL)
        {
            printf(" --> ");
        }
        n = n->next;
    }
    printf("\n");
}

int main(void)
{
    ListNode a, b, c;
    a.next = b.next = c.next = NULL;
    a.value = 1; b.value = 2; c.value = 3;

    ListNode* head = &a;
    a.next = &b;
    b.next = &c;

    printList(head);

    return 0;
}
