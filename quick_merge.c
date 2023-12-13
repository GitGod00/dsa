#include<stdio.h>
#include<math.h>

void insertionSort(int arr[], int n){
    int i, key, j;
    for( i = 0;i < n; i++){
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
        
    }
}

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int n){
    for(int i = 0;i < n - 1;i++){
        int j = i;
        for (int k = i + 1 ; k < n; k++)
        {
            if(arr[k] < arr[j]){
                j = i; 
            }
        }
        swap(&arr[j] , &arr[i]);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);

    for(int j = low;j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


void quickSort(int arr[] , int low, int high){
    if(low < high){
        int pi = partition(arr , low ,high);

        quickSort(arr , low , pi - 1);
        quickSort(arr , pi + 1 , high);
    }
}


void merge(int arr[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    // int *L[] = (int *)malloc(n1 * sizeof(int));
    // int *M[] = (int *)malloc(n2 * sizeof(int));
    for(int i = 0; i < n1; i++){
        L[i] = arr[p + i];
    }
    for(int j = 0; j < n2; j++){
        M[j] = arr[q + 1 + j];
    }

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while(i < n1 && j < n2){
        if(L[i] <= M[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = M[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = l + (r - l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}



void printArray(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n,i;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    int arr[50];
    printf("\nEnter the elemnets of array: ");
    for(i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    // insertionSort(arr , n);
    // printArray(arr , n);
    // printf("\n-----------\n");
    // selectionSort(arr , n);
    // printArray(arr , n);
    // printf("\n-----------\n");
    // quickSort(arr , 0 , n - 1);
    // printArray(arr , n);
    // printf("\n-----------\n");
    mergeSort(arr , 0 , n - 1);
    printArray(arr , n);

    return 0;
}