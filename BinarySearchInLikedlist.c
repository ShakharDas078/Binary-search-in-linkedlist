#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

 void display (struct Node *node)
{
    while (node != NULL)
    {
        printf ("%d ", node->data);
        node = node->next;
    }
    printf ("\n");
}
struct Node* middle(struct Node* start,struct Node* last)
{
    if (start == NULL)
        return NULL;

    struct Node* slow = start;
    struct Node* fast = start -> next;

    while (fast != last)
    {
        fast = fast -> next;
        if (fast != last)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    return slow;
}

struct Node* binarySearch(struct Node *head,int index)
{

int value;
printf("\nEnter Search Value :",&value);
 scanf("%d",&value);
    struct Node* start = head;
    struct Node* last = NULL;

    while ((last == NULL ||last != start))
    {

        struct Node* mid = middle(start, last);

        if (mid -> data == value)
            {
                return index;
            }

        else if (mid -> data < value)
           {
             start = mid -> next;
           }

        else
        {
            last = mid;
        }

      index++;
    }

    return -1;
}

// Driver Code
int main()
{
   int item;

    struct Node *head = NULL;
    struct Node *node2 = NULL;
    struct Node *node3 = NULL;
    struct Node *node4 = NULL;

    head = (struct Node *) malloc (sizeof (struct Node));
    node2 = (struct Node *) malloc (sizeof (struct Node));
    node3 = (struct Node *) malloc (sizeof (struct Node));
    node4 = (struct Node *) malloc (sizeof (struct Node));


    head->data = 10;
    head->next = node2;

    node2->data = 15;
    node2->next = node3;

    node3->data = 20;
    node3->next = node4;

    node4->data = 25;
    node4->next = NULL;

    printf ("Linked List: ");
    display (head);
    int index;
    index = binarySearch(head,1);
     if (index == -1)
        printf ("Item not found");
    else
        printf ("Item found at position: %d", index + 1);
    return 0;
}
