#include <iostream>

//Function Declaration
void merge(int arr[], int p, int q, int r);
void mergeSort(int arr[], int p, int r);

//Driver Code:
int main() 
{
    //Variable Declaration:
    
    int size;
    int i = 0;

    std::cout << "Enter the number of Elements for the Array: ";
    std::cin >> size;

    int arr[size];
    
    for(i = 0 ; i<size ; i++)
    {
        std::cout << "Enter the Element for index " << i+1 <<" : ";
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, size-1);

    for(i = 0 ; i<size ; i++)
        std::cout << arr[i] << " ";

    std::cout<< std::endl;

    return 0;
}

//Function Definition

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (int i = 0; i < n1; i++) 
        leftArr[i] = arr[p + i];
    
    for (int j = 0; j < n2; j++) 
        rightArr[j] = arr[q + 1 + j];
    

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) 
        {
            arr[k] = leftArr[i];
            i++;
        } 
        else 
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int p, int r) 
{
    if (p < r) 
    {
        int q = p + (r - p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

