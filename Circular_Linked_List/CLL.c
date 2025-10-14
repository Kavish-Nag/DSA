#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode;  // initially points to itself (circular)
    return newNode;
}

// Insert node at end of circular linked list
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode; // first node
    }
    struct Node* temp = head;
    // Traverse to last node
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; // maintain circularity

    return head;
}

// Insert node at beginning of circular linked list
struct Node* insertFirst(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode; // first node
    }

    struct Node* temp = head;
    // Traverse to last node
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return newNode;  // new head
}

// Insert node at custom position in circular linked list
struct Node* insertCustom(struct Node* head, int data, int pos) {
    if (pos == 1) {
        return insertFirst(head, data); // insert at beginning
    }

    if (head == NULL) {
        printf("Invalid position!\n");
        return NULL;
    }

    struct Node* temp = head;
    // Traverse to node before desired position
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
        if (temp == head) {
            printf("Position exceeds list length.\n");
            return head;
        }
    }

    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    // Traverse and print each node
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("head\n");   
}

// Delete first node of circular linked list
struct Node* deleteStart(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }

    if (head->next == head) {
        free(head); // only one node
        return NULL;
    }

    struct Node* temp = head;
    // Traverse to last node
    while (temp->next != head) {
        temp = temp->next;
    }

    struct Node* toDelete = head;
    temp->next = head->next; // last node points to new head
    head = head->next;       // update head
    free(toDelete);

    return head;
}

// Delete last node of circular linked list
struct Node* deleteEnd(struct Node* head) {
    if (head == NULL) return NULL;

    if (head->next == head) {
        free(head); // only one node
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // Traverse to last node
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head; // previous node points to head
    free(temp);

    return head;
}

// Delete node at custom position in circular linked list
struct Node* deleteNode(struct Node* head, int pos) {
    if (head == NULL) return NULL;

    if (pos == 1) {
        return deleteStart(head); // delete first node
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // Traverse to desired position
    for (int i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;

        if (temp == head) {
            printf("Invalid position!\n");
            return head;
        }
    }
    prev->next = temp->next;
    free(temp);

    return head;
}

// Reverse the circular linked list
struct Node* reverseList(struct Node* head) {
    if (head == NULL || head->next == head)
        return head;

    struct Node *prev = head, *current = head->next, *nextNode;

    while (current != head) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head->next = prev;  // old head points to last node
    head = prev;        // update head to new first node
    return head;
}


// Concatenate two circular linked lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp1 = head1;
    // Find last node of first list
    while (temp1->next != head1) {
        temp1 = temp1->next;
    }

    struct Node* temp2 = head2;
    // Find last node of second list
    while (temp2->next != head2) {
        temp2 = temp2->next;
    }

    temp1->next = head2; // link end of first to start of second
    temp2->next = head1; // link end of second to start of first

    return head1;
}

int main() {
    struct Node* head = NULL;    // original list head
    struct Node* revHead = NULL; // reversed list head
    int a, c, data, ch, n, pos;

    do {
        // Menu options
        printf("\nPick one:\n");
        printf("1. Create Linked List (multiple nodes)\n");
        printf("2. Display the Linked List\n");
        printf("3. Insert an element\n");
        printf("4. Delete a node\n");
        printf("5. Reverse the list\n");
        printf("6. Concatenate reversed list to original\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                // Create list with multiple nodes
                printf("How many nodes? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter data for node %d: ", i + 1);
                    scanf("%d", &data);
                    head = insertEnd(head, data);
                }
                printf("List created!\n");
                displayList(head);
                break;

            case 2:
                // Display list
                displayList(head);
                break;

            case 3:
                // Insert node
                printf("1. Insert at first\n2. Insert at last\n3. Insert at position\n");
                scanf("%d", &c);
                printf("Enter data: ");
                scanf("%d", &data);
                if (c == 1)
                    head = insertFirst(head, data);
                else if (c == 2)
                    head = insertEnd(head, data);
                else if (c == 3) {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    head = insertCustom(head, data, pos);
                }
                displayList(head);
                break;

            case 4:
                // Delete node
                printf("1. Delete at first\n2. Delete at last\n3. Delete at position\n");
                scanf("%d", &c);
                if (c == 1)
                    head = deleteStart(head);
                else if (c == 2)
                    head = deleteEnd(head);
                else if (c == 3) {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    head = deleteNode(head, pos);
                }
                displayList(head);
                break;

            case 5:
                // Reverse list and create a new reversed list
                revHead = NULL;
                if (head != NULL) {
                    struct Node* temp = head;
                    // Copy nodes to new list
                    do {
                        revHead = insertEnd(revHead, temp->data);
                        temp = temp->next;
                    } while (temp != head);

                    revHead = reverseList(revHead); // reverse new list
                }
                printf("Reversed list created!\n");
                displayList(revHead);
                break;

            case 6:
                if (revHead == NULL) {
                    printf("No reversed list available to concatenate!\n");
                } else {
                    head = concatenate(head, revHead);
                    revHead = NULL; // prevent double concatenation
                    printf("Concatenated list:\n");
                    displayList(head);
                }
                break;


            case 7:
                // Exit program
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

        printf("\nPress 1 to continue: ");
        scanf("%d", &ch);
    } while (ch == 1);

    return 0;
}
