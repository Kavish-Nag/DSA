#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL) {
        return newNode;   // first node
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to insert at beginning
struct Node* insertFirst(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert at custom position
struct Node* insertCustom(struct Node* head, int data, int pos) {
    struct Node* newNode = createNode(data);

    if (pos == 1) {
        newNode->next = head;
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// Function to display linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete start
struct Node* deleteStart(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete end
struct Node* deleteEnd(struct Node* head){
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* prev = head;
    while (prev->next->next != NULL) {
        prev = prev->next;
    }
    free(prev->next);
    prev->next = NULL;
    return head;
}

// Delete at custom position
struct Node* deleteNode(struct Node* head, int p) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp == NULL) return head;

    if (p == 1) {
        head = temp->next;
        free(temp);
        return head;
    }
    for (int i = 1; temp != NULL && i < p; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Invalid position\n");
    }
    return head;
}

// Reverse a list and return new head
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;  // new head of reversed list
}

// Concatenate two lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

int main() {
    struct Node* head = NULL;
    struct Node* revHead = NULL;

    int a, c, data, ch, n, pos, key;

    do {
        printf("\nPick one of the following:\n");
        printf("1. Create Linked List (multiple nodes)\n");
        printf("2. Display the whole Linked list\n");
        printf("3. Insert an element in the list\n");
        printf("4. Deletion of a node from List\n");
        printf("5. Reverse the Linked List (and save separately)\n");
        printf("6. Concatenate reversed list to normal list\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &a);

        switch (a) {
            case 1:
                printf("How many nodes do you want to create? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Enter data for node %d: ", i + 1);
                    scanf("%d", &data);
                    head = insertEnd(head, data);
                }
                printf("Nodes created successfully!\n");
                displayList(head);
                break;

            case 2:
                displayList(head);
                break;

            case 3:
                printf("Pick one:\n");
                printf("1. Insert element at first position\n");
                printf("2. Insert element at last position\n");
                printf("3. Insert at specific position\n");
                scanf("%d", &c);
                switch (c) {
                    case 1:
                        printf("Enter data for the node: ");
                        scanf("%d", &data);
                        head = insertFirst(head, data);
                        displayList(head);
                        break;

                    case 2:
                        printf("Enter data for the node: ");
                        scanf("%d", &data);
                        head = insertEnd(head, data);
                        displayList(head);
                        break;

                    case 3:
                        printf("Enter data for the node: ");
                        scanf("%d", &data);
                        printf("Enter position: ");
                        scanf("%d", &pos);
                        head = insertCustom(head, data, pos);
                        displayList(head);
                        break;
                }
                break;

            case 4:
                printf("Pick one:\n");
                printf("1. Delete element at first position\n");
                printf("2. Delete element at last position\n");
                printf("3. Delete at specific position\n");
                scanf("%d", &c);
                switch (c) {
                    case 1:
                        head = deleteStart(head);
                        break;
                    
                    case 2:
                        head = deleteEnd(head);
                        break;

                    case 3:
                        printf("Enter position to delete: ");
                        scanf("%d", &key);
                        head = deleteNode(head, key);
                        break;
                }
                displayList(head);
                break;

            case 5: {
                // First, create a copy of head into revHead
                revHead = NULL;
                struct Node* temp = head;
                while (temp != NULL) {
                    revHead = insertEnd(revHead, temp->data);  // reuse insertEnd()
                    temp = temp->next;
                }
                // Now reverse the copy
                revHead = reverseList(revHead);

                printf("Reversed Linked List stored successfully!\n");
                displayList(revHead);
                break;
}

            case 6:
                head = concatenate(head, revHead);
                printf("Concatenated List:\n");
                displayList(head);
                break;

            case 7:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }

        printf("\nDo you want to continue? (press 1 to continue): ");
        scanf("%d", &ch);
    } while (ch == 1);
    return 0;
}