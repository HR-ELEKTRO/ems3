#include <stdio.h>
#include <stdlib.h>

#define ERROR

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
    int aantalNodes = 1;

    while (aantalNodes > 0)
    {
		printf("Hoeveel nodes wenst u (0 stopt het programma)? ");
		scanf("%d", &aantalNodes);

		for (int n = 0; n < aantalNodes; n++)
		{
			ListNode *newNode = malloc(sizeof(ListNode));
			newNode->value = n;
			newNode->next = NULL;
			if (head == NULL)
			{
				head = tail = newNode;
			}
			else
			{
				tail = tail->next = newNode;
			}
		}

		printList(head);

		// free the list
		while (head != NULL)
		{
#ifdef ERROR
			// wrong
			// main while loop does not work anymore!
			free(head);
			head = head -> next;
#else
			ListNode *node = head;
			head = head -> next;
			free(node);
#endif
		}
		tail = NULL;
    }
    return 0;
}
