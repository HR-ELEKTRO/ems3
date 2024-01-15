#include <stdio.h>
#include <stdlib.h>

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
    ListNode *head = NULL, *tail = NULL;
    int aantalNodes;

    printf("Hoeveel nodes wenst u? ");
    scanf("%d", &aantalNodes);

    for (int n = 0; n < aantalNodes; n++)
    {
        ListNode *newNode = malloc(sizeof(ListNode));
        newNode->value = n;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    printList(head);

    // free the list
    while (head != NULL)
    {
        ListNode *node = head;
        head = head -> next;
        free(node);
    }
    tail = NULL;

    return 0;
}
