#include <iostream>

// Function Declaration
int findCondition(int A[], int p, int r);

// Driver Code
int main() {
    // Example usage:
    int A[] = {0, 1, 2, 3, 5, 6, 7};
    int size = sizeof(A) / sizeof(A[0]);

    int result = findCondition(A, 0, size - 1);

    if (result != -1) 
        std::cout << "The condition A[" << result << "] = " << result << " is satisfied." << std::endl;
    
    else
        std::cout << "No such condition found in the array." << std::endl;

    return 0;
}

// Function Definition
int findCondition(int A[], int p, int r) 
{
    if (p <= r) 
    {
        int q = (p + r) / 2;

        if (A[q] == q) 
            return q; 
        
        else if (A[q] < q) 
            return findCondition(A, q + 1, r);
        
        else
            return findCondition(A, p, q - 1);
    }

    return -1;
}
