#include <iostream>

// Function Declaration
int findMax(int A[], int p, int r);

// Driver Code
int main() {
    
    int size;
    int i = 0;

    std::cout << "Enter the number of Elements for the Array: ";
    std::cin >> size;

    int* arr = new int[size];

    for (i = 0; i < size; i++) {
        std::cout << "Enter the Element for index " << i + 1 << " : ";
        std::cin >> arr[i];
    }

    int max = findMax(arr, 0, size - 1);

    if (max != -1) {
        std::cout << "The maximum element in the array is: " << arr[max] << std::endl;
    } else {
        std::cout << "No such pattern found in the array." << std::endl;
    }

    return 0;
}

// Function Definition
int findMax(int A[], int p, int r) {
    if (p <= r) 
    {
        int q = (p + r) / 2;

        if (A[q] > A[q - 1] && A[q] > A[q + 1])
            return q; 

        else if (A[q] < A[q + 1])
            return findMax(A, q + 1, r);

        else
            return findMax(A, p, q - 1);
    }

    return -1;
}