#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node with the given value
struct node* createBT(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a value into the binary search tree (BST)
struct node* insert(struct node* root, int value) {
    if (root == NULL) {
        return createBT(value); // If tree is empty, create a new node
    }
    if (value < root->data) {
        root->left = insert(root->left, value); // Insert in left subtree
    } else if (value > root->data) {
        root->right = insert(root->right, value); // Insert in right subtree
    }
    return root; 
}

// Inorder traversal: Left, Root, Right
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal: Root, Left, Right
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal: Left, Right, Root
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Search for a key in the BST
struct node* Search(struct node* root, int key) {
    if (root == NULL) {
        return NULL; // Key not found
    }
    if (root->data == key) {
        return root; // Key found
    }
    if (key < root->data) {
        return Search(root->left, key); // Search in left subtree
    } else {
        return Search(root->right, key); // Search in right subtree
    }
}

int main() {
    struct node* root = NULL;   
    struct node* result = NULL;  
    int choice, value, key, cont, a;

    do {
        // Display menu options
        printf("\n--- MENU ---\n");
        printf("1. Insert a new node\n");
        printf("2. Traversal of tree\n");
        printf("3. Search for an element\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert a new node
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                // Traversal options
                printf("\nTraversal Options:\n");
                printf("1. Inorder Traversal\n");
                printf("2. Preorder Traversal\n");
                printf("3. Postorder Traversal\n");
                printf("Enter your choice: ");
                scanf("%d", &a);
                switch (a) {
                    case 1:
                        inorder(root);
                        break;
                    case 2:
                        preorder(root);
                        break;
                    case 3:
                        postorder(root);
                        break;
                    default:
                        printf("Invalid traversal choice.\n");
                }
                break;

            case 3:
                // Search for an element
                printf("Enter the element to search: ");
                scanf("%d", &key);
                result = Search(root, key);
                if (result != NULL)
                    printf("Element %d found in BST.\n", key);
                else
                    printf("Element %d not found in BST.\n", key);
                break;

            default:
                printf("Invalid choice!\n");
        }

        // Ask user if they want to continue
        printf("\nDo you want to continue? (1 = Yes / 0 = No): ");
        scanf("%d", &cont);

    } while (cont == 1);

    return 0;
}
