#include <stdio.h>

void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int low, int high, int ch) {
    int pivot_ind;
    switch(ch){
        case 1:
        pivot_ind = (low + high) / 2;
        break;
        case 2:
        pivot_ind = low;
        break;
        case 3:
        pivot_ind = high;
        break;
        default:
        printf("Invalid choice");
    }
    int pivot = arr[pivot_ind];
    swap(arr, pivot_ind, high);  
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high); 
    return i + 1;
}

void quickSort(int arr[], int low, int high, int ch) {
    if (low < high) {
        int pi = partition(arr, low, high,ch);
        quickSort(arr, low, pi - 1,ch);
        quickSort(arr, pi + 1, high,ch);
    }
}
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
    }
    i = 0; 
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n,ch,pivot,pivot_ind,c,choice;
    do{
    printf("Enter number of elements of array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int size = n;
    printf("Original array: ");
    printArray(arr, size);
    printf("Select one: \n");
    printf("1. Quick Sort. \n");
    printf("2. Merge Sort. \n");
    printf("Choose (1/2): ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        printf("Select one: \n");
        printf("1. Mid element approach. \n");
        printf("2. Hoare's approach. \n");
        printf("3. Lomuto's approach \n");
        printf("Choose (1/2/3):");
        scanf("%d",&c);
        switch(c){
            case 1:
            pivot_ind = (0 + (size-1)) / 2;
            pivot = arr[pivot_ind];
            printf("Starting pivot for this case is %d \n", pivot);
            quickSort(arr, 0, size - 1,ch);
            break;
            case 2:
            pivot_ind = 0;
            pivot = arr[pivot_ind];
            printf("Starting pivot for this case is %d \n", pivot);
            quickSort(arr, 0, size - 1,ch);
            break;
            
            case 3:
            pivot_ind = size-1;
            pivot = arr[pivot_ind];
            printf("Starting pivot for this case is %d \n", pivot);
            quickSort(arr, 0, size - 1,ch);
            break;
            
            default:
            printf("Invalid choice. \n");
        break;
        }
        case 2:
        
        mergesort(arr, 0, n - 1);
        break;

        default:
        printf("Invalid Choice.");
    }
    printf("Sorted array: ");
    printArray(arr, size);
    printf("Would you like to continue? \n");
    printf("To continue, press 1. \n");
    scanf("%d", &choice);
    }while(choice == 1);
    return 0;
