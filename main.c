#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node* prev;
    struct Node* next;
};

struct Node* head;

void addNode(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node* currentOne = head;
        while (currentOne->next != NULL)
        {
            currentOne = currentOne->next;
        }

        currentOne->next = newNode;
        newNode->prev = currentOne;
    }
}

void removeNode(int index)
{
    if (index == 0)
    {
        head->next->prev = NULL;
        head->next = NULL;
        head = NULL;
    }
    else
    {
        int currentIndex = 0;
        struct Node* currentOne = head;

        while (currentOne != NULL)
        {
            if (currentIndex == index)
            {
                if (currentOne->next != NULL)
                {
                    currentOne->next->prev = currentOne->prev;
                }

                if (currentOne->prev != NULL)
                {
                    currentOne->prev->next = currentOne->next;
                }

                return;
            }

            currentIndex++;
            currentOne = currentOne->next;
        }
    }
}

struct Node* findNode(int value)
{
    if (head->value == value)
    {
        return head;
    }
    else
    {
        struct Node* currentOne = head;
        while (currentOne != NULL)
        {
            if (currentOne-> value == value)
            {
                return currentOne;
            }
            currentOne = currentOne->next;
        }

        return NULL;
    }
}

void printList()
{
    struct Node* currentOne = head;
    while (currentOne != NULL)
    {
        printf("%d \n", currentOne->value);
        currentOne = currentOne->next;
    }
}

int main()
{
    printf("Doubly-linked list\n");
    addNode(1);
    addNode(2);
    addNode(3);
    printList();

    removeNode(1);

    printf("\n");
    printList();

    return 0;
}
