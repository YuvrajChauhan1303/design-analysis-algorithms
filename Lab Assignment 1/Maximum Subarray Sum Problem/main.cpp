#include<iostream>

//Struct Declaration
struct result
{
    int startIndex;
    int endIndex;
    int maxSum;
};

// Function Declarations
int max_subarray_sum(int A[], int p, int r , struct result * var);
int max_crossing_subarray_sum(int A[], int p, int q, int r, struct result * var);
int max(int L, int R, int C);

// Driver Code
int main()
{
    struct result * var1;
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

    int result = max_subarray_sum(arr, 0 , size-1, var1);

    std::cout << "Max Sum: " << result << std::endl;
    std::cout << "Start Index : " << var1->startIndex << std::endl;
    std::cout << "End Index : " << var1->endIndex << std::endl;

    return 0;
}

// Function Definitions

int max_subarray_sum(int A[], int p, int r , struct result * var)
{
    if(p > r)
        return -1; 

    int q = (p+r)/2;

    int L = max_subarray_sum(A, p, q, var);
    int R = max_subarray_sum(A, q+1, r, var);
    int C = max_crossing_subarray_sum(A, p, q ,r , var);

    return max(L, R, C);
}

int max_crossing_subarray_sum(int A[], int p, int q, int r, struct result * var)
{
    int leftSum = -99999;
    
    int sum = 0;
    int i = 0; int j = 0;

    for(i = q ; i>=p ; i--)
    {
        sum = sum + A[i];

        if(sum > leftSum)
        {
            leftSum = sum;
            var->startIndex = i;
        }
    }

    int rightSum = -99999;
    sum = 0;

    for(j = q+1 ; j<=r ; j++)
    {
        sum = sum + A[j];

        if(sum > rightSum)
        {
            rightSum = sum;
            var->endIndex = j;
        }
    }
    var->maxSum = leftSum+rightSum;

    return (leftSum + rightSum);
}

int max(int L, int R, int C)
{
    int max;

    max = (L > R) ? (L > C ? L : C) : (R > C ? R : C);

    return max;
}
