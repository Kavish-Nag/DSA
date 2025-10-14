#include <stdio.h>
int bubble_sort(int ar[],int n){
	int i,j;
	int temp;
	for (i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(ar[j]>ar[j+1]){
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;
			}
		}
	}
	return 0;
}

int bubble_ptr(int *ar, int n){
	int i,j, temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i;j++){
			if(*(ar+j)> *(ar+j+1)){
				temp=*(ar+j);
                *(ar+j)= *(ar+j+1);
                *(ar+j+1)=temp;
			}
		}
	}
	return 0;
}

int selection_sort(int ar[], int n) {
    int i, j, min_idx, temp;
    for(i = 0; i < n - 1; i++) {
        min_idx = i;
        for(j = i + 1; j < n; j++) {
            if(ar[j] < ar[min_idx]) {
                min_idx = j;
            }
        }
        temp = ar[i];
        ar[i] = ar[min_idx];
        ar[min_idx] = temp;
    }return 0;
}
int selection_ptr(int *ar, int n) {
    int i, j;
    int *min_ptr, temp;
    for(i = 0; i < n - 1; i++) {
        min_ptr = ar + i; 
        for(j = i + 1; j < n; j++) {
            if(*(ar + j) < *min_ptr) {
                min_ptr = ar + j;
            }
        }
        if(min_ptr != ar + i) {
            temp = *(ar + i);
            *(ar + i) = *min_ptr;
            *min_ptr = temp;
        }
    }return 0;
}

int insertion_sort(int ar[],int n){
	int i,j,key;
	for(i=0;i<n;i++){
		key = ar[i];
		j=i-1;
		while(j>=0 && ar[j]>key){
			ar[j+1]=ar[j];
			j--;
		}
		ar[j+1]=key;
	}
	return 0;
}

int insertion_ptr(int *ar, int n) {
    int i, j, key;
    for (i=1; i<n; i++) {
        key = *(ar+i);      
        j = i - 1;
        while (j>=0 && *(ar + j)>key) {
            *(ar+j+1) = *(ar+j); 
            j--;
        }
        *(ar+j+1) = *(ar+j);    
    }
    return 0;
}


int main(){
	int i,n,result,ch;
	char choice;
	do{
	printf("Enter number of elements of array:");
	scanf("%d",&n);
	int ar[n];
	for(i=0;i<n;i++){
		printf("Enter %d element: ", i+1);
		scanf("%d",&ar[i]);
	}
	
	printf("\n Select a way (1/2/3/4/5/6) \n");
	printf("1. Bubble sort. \n");
	printf("2. Selection sort. \n");
	printf("3. Bubble sort with pointer. \n");
	printf("4. Selection sort with pointer. \n");
	printf("5. Insertion sort. \n");
	printf("6. Insertion sort with pointer. \n");
	scanf("%d",&ch);

	printf("Unsorted array is:");
	for(i=0;i<n;i++){
		printf("%d ", ar[i]);
	}
	switch(ch){
		case 1:
			bubble_sort(ar,n);
			printf("\n Sorted array: ");
			for(i=0;i<n;i++){
			printf("%d ", ar[i]);
			}
			break;
		case 2:
			selection_sort(ar,n);
			printf("\n Sorted array: ");
			for(i=0;i<n;i++){
			printf("%d ", ar[i]);
			}
			break;
		case 3:
			bubble_ptr(ar,n);
			printf("\n Sorted array: ");
			for(i=0;i<n;i++){
			printf("%d ", ar[i]);
			}
			break;
		case 4:
			selection_sort(ar,n);
			printf("\n Sorted array: ");
			for(i=0;i<n;i++){
				printf("%d ", ar[i]);
			}
			break;
		case 5:
			insertion_sort(ar,n);
			printf("\n Sorted array: ");
			for(i=0;i<n;i++){
				printf("%d ", ar[i]);
			}
			break;
		case 6:
			insertion_sort(ar,n);
			printf("\n Sorted array: ");
			for(i=0;i<n;i++){
				printf("%d ", ar[i]);
			}
			break;
		default:
			printf("Not a valid option. \n ");	
	}
	printf("\n Do you want to continue? (y/n) ");
	scanf(" %c",&choice);
} while(choice == 'Y' || choice == 'y');
	return 0;
}
