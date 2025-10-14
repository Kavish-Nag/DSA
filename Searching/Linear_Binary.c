#include <stdio.h> 
// Function for linear search
int linear_search(int ar[], int s, int n) {
    int j;
    for(j = 0; j < n; j++) {
        if(ar[j] == s) {  // Check if current element matches the search element
            return j;     // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}
// Function for binary search
int binary_search(int ar[], int s, int n) {
    int low = 0, high = n - 1;
    int mid;
    mid = (low + high) / 2;

    while(low <= high) {
        if(ar[mid] == s) {
            return mid;  // Element found
        }
        else if(ar[mid] > s) {
            high = mid - 1;  // Search left half
        }
        else if(ar[mid] < s) {
            low = mid + 1;   // Search right half
        }
        mid = (low + high) / 2;  // Recalculate mid
    }
    return -1;  // Return -1 if not found
}

int main() {
    int i, index, n, s, ch;
    char choice;

    do {
        // Get the number of elements in the array
        printf("Enter number of elements: ");
        scanf("%d", &n);

        int ar[n];  // Declare array of size 'n'

        // Input array elements
        for(i = 0; i < n; i++) {
            printf("Enter element %d: ", i + 1);
            scanf("%d", &ar[i]);
        }

        // Input the element to be searched
        printf("Enter an element to search: ");
        scanf("%d", &s);

        printf("Which way to search? \n");
        printf("1. Linear Search.\n");
        printf("2. Binary Search.\n");
        printf("Enter choice (1/2): ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                index = linear_search(ar, s, n);
                break;
            case 2:
                index = binary_search(ar, s, n);
                break;
            default:
                printf("Invalid choice.");
        }

        if(index == -1) {
            printf("Element not found.");
        } else {
            printf("Element at index %d", index);
        }

        // Ask user if they want to continue
        printf("\nDo you want to continue? (y/n): ");
        getchar();
        scanf("%c", &choice);

    } while(choice == 'y' || choice == 'Y');  
    // Continue if user enters 'y' or 'Y'
    return 0;
}
