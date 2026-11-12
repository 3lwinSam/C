
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// INSERTION AT BEGINNING
void insert_begin()
{
    struct Node *newnode;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// INSERTION AT END
void insert_end()
{
    struct Node *newnode, *curr;

    newnode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
    }
    else
    {
        curr = head;

        while(curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = newnode;
    }
}

// INSERTION AT SPECIFIC POSITION
void insert_pos()
{
    struct Node *newnode, *curr;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct Node*)malloc(sizeof(struct Node));

    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        curr = head;

        for(i = 1; i < pos-1 && curr != NULL; i++)
        {
            curr = curr->next;
        }

        if(curr == NULL)
        {
            printf("Invalid position\n");
            free(newnode);
        }
        else
        {
            newnode->next = curr->next;
            curr->next = newnode;
        }
    }
}

// DELETION AT BEGINNING
void delete_begin()
{
    struct Node *curr;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        curr = head;
        head = head->next;
        free(curr);
    }
}

// DELETION AT END
void delete_end()
{
    struct Node *prev, *curr;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else if(head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        prev = head;
        curr = head->next;

        while(curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = NULL;
        free(curr);
    }
}

// DELETION AT SPECIFIC POSITION
void delete_pos()
{
    struct Node *prev, *curr;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || head == NULL)
    {
        printf("Invalid position or empty list\n");
    }
    else if(pos == 1)
    {
        curr = head;
        head = head->next;
        free(curr);
    }
    else
    {
        prev = head;
        curr = head->next;

        for(i = 2; i < pos && curr != NULL; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        if(curr == NULL)
        {
            printf("Invalid position\n");
        }
        else
        {
            prev->next = curr->next;
            free(curr);
        }
    }
}

// TRAVERSAL
void traverse()
{
    struct Node *curr;

    if(head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        curr = head;

        while(curr != NULL)
        {
            printf("%d -> ", curr->data);
            curr = curr->next;
        }

        printf("NULL\n");
    }
}

// MAIN FUNCTION
int main()
{
    int choice;

    while(1)
    {
        printf("\n--- SINGLY LINKED LIST ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Traverse\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert_begin();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                insert_pos();
                break;

            case 4:
                delete_begin();
                break;

            case 5:
                delete_end();
                break;

            case 6:
                delete_pos();
                break;

            case 7:
                traverse();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
