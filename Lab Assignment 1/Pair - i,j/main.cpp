#include<iostream>

//Function Declarations:
int result(int A[], int size);


// Driver Code

int main()
{
    //Variable Declaration
    int size;
    int i;

    std::cout << "Enter the size of the Array: ";
    std::cin >> size;

    int arr[size];

    for(i = 0 ; i < size ; i++)
    {
        std::cout << "Enter Element " << i+1 << " : " ;
        std::cin >> arr[i];
    }

    std::cout << "Number of Pairs : " << result(arr, size) << std::endl;

    return 0;
}

// Function Defintion
int result(int A[], int size)
{
    int i;
    int j;
    int pairs = 0;

    for(i = 0 ; i < size ; i++)
    {
        for(j = i+1 ; j<size ; j++)
        {
            if(A[i] > A[j])
                pairs++;
        }
    }

    return pairs;
}