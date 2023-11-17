/*5.1 Write a program to create a double linked list and perform the following menu based operations on it:
i. insert an element at specific position
ii. delete an element from specific position
iii. Traverse the list*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertNode(struct Node **head, int element, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 1) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        printf("Node inserted\n");
        return;
    }

    struct Node *temp = *head;
    for (int i = 0; i < position - 2; i++) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;

    printf("Node inserted\n");
}

void deleteNode(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = *head;

    if (position == 1) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Node deleted\n");
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
    printf("Node deleted\n");
}

void traverseList(struct Node *head) {
    printf("The list is: ");
    while (head != NULL) {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int nodes, choice, element, position;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);
    printf("Enter the elements: ");
    for (int i = 0; i < nodes; i++) {
        scanf("%d", &element);
        insertNode(&head, element, i + 1);
    }

    do {
        printf("MENU:\n");
        printf("1. Insert the node at a position\n");
        printf("2. Delete a node from specific position\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter position: ");
                scanf("%d", &position);
                insertNode(&head, element, position);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteNode(&head, position);
                break;
            case 3:
                traverseList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}

//5.2 Write a program to create a circular linked list and display the elements of the list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("Clinkedlist: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int nodes, data;
    printf("Enter no. of nodes: ");
    scanf("%d", &nodes);

    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode = NULL;

    for (int i = 0; i < nodes; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter info of node %d: ", i + 1);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    displayList(head);

    return 0;
}

//5.3 Write a program to represent the given sparse matrix using header single linked list and display it
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int row, col, val;
    struct Node *right, *down;
};

void displaySparseMatrix(struct Node *header) {
    struct Node *temp_row = header->down;

    while (temp_row != header) {
        struct Node *temp = temp_row->right;
        while (temp != temp_row) {
            printf("%d %d %d\n", temp->row, temp->col, temp->val);
            temp = temp->right;
        }
        temp_row = temp_row->down;
    }
}

int main() {
    int rows, cols, val;
    printf("Enter size of the sparse matrix: ");
    scanf("%d %d", &rows, &cols);

    struct Node *header = (struct Node *)malloc(sizeof(struct Node));
    header->row = rows;
    header->col = cols;
    header->val = 0;
    header->right = header;
    header->down = header;

    struct Node *lastInRow[cols];
    for (int i = 0; i < cols; i++) {
        lastInRow[i] = header;
    }

    for (int i = 0; i < rows; i++) {
        struct Node *newRow = (struct Node *)malloc(sizeof(struct Node));
        newRow->row = i;
        newRow->col = -1;  // To mark the start of a row
        newRow->val = 0;
        newRow->right = newRow;
        newRow->down = header;

        for (int j = 0; j < cols; j++) {
            scanf("%d", &val);
            if (val != 0) {
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->row = i;
                newNode->col = j;
                newNode->val = val;
                newNode->right = newRow;
                newNode->down = NULL;

                lastInRow[j]->down = newNode;
                lastInRow[j] = newNode;
                lastInRow[j] = lastInRow[j]->down;
            }
        }
    }

    for (int i = 0; i < cols; i++) {
        lastInRow[i]->down = header;
    }

    displaySparseMatrix(header);

    return 0;
}

