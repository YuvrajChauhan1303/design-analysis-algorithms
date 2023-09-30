#include <iostream>

// Function Declaration
int merge(int arr[], int p, int q, int r);
int findInversions(int arr[], int p, int r);

// Driver Code:
int main() {
    // Variable Declaration:
    int size;
    int i = 0;

    std::cout << "Enter the number of Elements for the Array: ";
    std::cin >> size;

    int* arr = new int[size];

    for (i = 0; i < size; i++) {
        std::cout << "Enter the Element for index " << i + 1 << " : ";
        std::cin >> arr[i];
    }

    int inversions = findInversions(arr, 0, size - 1);

    std::cout << "Number of inversions: " << inversions << std::endl;


    return 0;
}

// Function Definition

int merge(int arr[], int p, int q, int r) {
    int i = 0, j = 0, k = 0;
    int inversions = 0;

    int n1 = q - p + 1;
    int n2 = r - q;

    int* leftArr = new int[n1];
    int* rightArr = new int[n2];

    for (i = 0; i < n1; i++)
        leftArr[i] = arr[p + i];

    for (j = 0; j < n2; j++)
        rightArr[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) 
            i++;
        else 
        {
            j++;
            inversions += n1 - i;
        }
        k++;
    }

    return inversions;
}

int findInversions(int arr[], int p, int r) {
    int inversions = 0;
    if (p < r) {
        int q = p + (r - p) / 2;
        inversions += findInversions(arr, p, q);
        inversions += findInversions(arr, q + 1, r);
        inversions += merge(arr, p, q, r);
    }

    return inversions;
}
