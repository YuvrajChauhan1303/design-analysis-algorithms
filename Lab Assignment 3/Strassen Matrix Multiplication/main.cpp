#include<iostream>

//Function Declaration

int * Strassen_Multiplication(int * X, int * Y, int * Z, int n);
int * Matrix_Addition(int * X, int * Y, int * Sum, int n);
int * Matrix_Subtraction(int * X, int * Y, int * Sum, int n);
void display(int * X, int n);

// Driver Code

int main()
{
    //Variable Declaration
    int i;
    int j;
    int n;

    std::cout << "Enter Size of Matrix: ";
    std::cin >> n; 
    int X[n][n];
    int Y[n][n];
    int Sum[n][n];
    int Diff[n][n];

    std::cout << "Enter Values for Matrix X:" << std::endl;

    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            std::cout << "Enter Value for " << i + 1 << " Row and " << j + 1 << " Col: " ;
            std::cin >> X[i][j];
        }
    }

    std::cout << "Enter Values for Matrix Y:" << std::endl;

    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            std::cout << "Enter Value for " << i + 1 << " Row and " << j + 1 << " Col: " ;
            std::cin >> Y[i][j];
        }
    }

    std::cout << std::endl << "Matrix 1:" << std::endl;
    display(&X[0][0], n);

    std::cout << std::endl << "Matrix 2:" << std::endl;
    display(&Y[0][0], n);

    Matrix_Addition(&X[0][0],&Y[0][0],&Sum[0][0],n);
    std::cout << std::endl << "Matrix 3:" << std::endl;
    display(&Sum[0][0], n);

    Matrix_Subtraction(&X[0][0],&Y[0][0],&Sum[0][0],n);
    std::cout << std::endl << "Matrix 4\:" << std::endl;
    display(&Sum[0][0], n);


    return 0;
}

// Function Defintion
int * Matrix_Addition(int * X, int * Y, int * Sum, int n)
{
    int i = 0;
    int j = 0; 
    int sum = 0;

    for(i = 0; i < n ; i++)
    {
        sum = 0;
        for(j = 0 ; j<n ; j++)
        {
            sum = *(X + i + j) + * (Y + i + j);
            *(Sum + i + j) = sum;
        }
        
    }

    return Sum;
}

int * Matrix_Subtraction(int * X, int * Y, int * Diff, int n)
{
    int i = 0;
    int j = 0; 
    int diff = 0;

    for(i = 0; i < n ; i++)
    {
        diff = 0;
        for(j = 0 ; j<n ; j++)
        {
            diff = *(X + i + j) - * (Y + i + j);
            *(Diff + i + j) = diff;
        }
        
    }

    return Diff;
}

void display(int * X, int n)
{
    int i = 0;
    int j = 0;

    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ;j < n; j++)
            std::cout << *(X + i + j) << " ";

        std::cout <<  std::endl;
    }
}

int * Strassen_Multiplication(int * X, int * Y, int * Z, int  n)
{
    int P1[n/2][n/2];
    int P2[n/2][n/2];
    int P3[n/2][n/2];
    int P4[n/2][n/2];
    int P5[n/2][n/2];
    int P6[n/2][n/2];
    int P7[n/2][n/2];
}