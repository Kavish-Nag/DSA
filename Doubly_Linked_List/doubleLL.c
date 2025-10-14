#include <stdio.h>
#include <stdlib.h>

// ================== Function Prototypes ==================
struct Node* createNode(int data);
struct Node* insertFirst(struct Node* head, int data);
struct Node* insertEnd(struct Node* head, int data);
struct Node* insertCustom(struct Node* head, int data, int pos);
struct Node* deleteStart(struct Node* head);
struct Node* deleteEnd(struct Node* head);
struct Node* deleteNode(struct Node* head, int p);
struct Node* reverseList(struct Node* head);
struct Node* concatenate(struct Node* head1, struct Node* head2);
void displayList(struct Node* head);

// ================== Structure Definition ==================
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at the beginning
struct Node* insertFirst(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

// Insert at the end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert at a given position
struct Node* insertCustom(struct Node* head, int data, int pos) {
    struct Node* newNode = createNode(data);
    if (pos == 1) {
        newNode->next = head;
        if (head != NULL) head->prev = newNode;
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
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp->next = newNode;
    return head;
}

// Delete from beginning
struct Node* deleteStart(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Delete at End
struct Node* deleteEnd(struct Node* head){
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    if (head->next == NULL) { // only one node
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete at specific position
struct Node* deleteNode(struct Node* head, int p) {
    struct Node* temp = head;

    if (temp == NULL) return head;

    if (p == 1) {
        head = temp->next;
        if (head != NULL) head->prev = NULL;
        free(temp);
        return head;
    }
    for (int i = 1; temp != NULL && i < p; i++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        free(temp);
    } else {
        printf("Invalid position\n");
    }
    return head;
}

// Reverse the list
struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    return prev;  // new head of reversed list
}
struct Node* cloneList(struct Node* head) {
    if (head == NULL) return NULL;

    struct Node* newHead = NULL;
    struct Node* temp = head;
    while (temp != NULL) {
        newHead = insertEnd(newHead, temp->data);
        temp = temp->next;
    }
    return newHead;
}

// Concatenate two lists
struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    head2->prev = temp;
    return head1;
}

// Display list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// ---------------- MAIN ----------------
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

            case 5:
            {
            struct Node* copy = cloneList(head);
            revHead = reverseList(copy);
            printf("Reversed List:\n");
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
