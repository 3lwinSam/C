
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char word[30];
    char meaning[100];
    struct Node *left, *right;
};

struct Node* insert(struct Node *root, char w[], char m[])
{
    if(root == NULL)
    {
        struct Node *newnode;
        newnode = (struct Node*)malloc(sizeof(struct Node));

        strcpy(newnode->word, w);
        strcpy(newnode->meaning, m);

        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if(strcmp(w, root->word) < 0)
        root->left = insert(root->left, w, m);

    else if(strcmp(w, root->word) > 0)
        root->right = insert(root->right, w, m);

    return root;
}

void search(struct Node *root, char w[])
{
    if(root == NULL)
    {
        printf("Word not found\n");
        return;
    }

    if(strcmp(w, root->word) == 0)
        printf("Meaning: %s\n", root->meaning);

    else if(strcmp(w, root->word) < 0)
        search(root->left, w);

    else
        search(root->right, w);
}

void display(struct Node *root)
{
    if(root != NULL)
    {
        display(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        display(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice;
    char w[30], m[100];

    while(1)
    {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter word: ");
                scanf("%s", w);

                printf("Enter meaning: ");
                scanf(" %[^\n]", m);

                root = insert(root, w, m);
                break;

            case 2:
                printf("Enter word to search: ");
                scanf("%s", w);

                search(root, w);
                break;

            case 3:
                printf("Dictionary:\n");
                display(root);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
