#include <iostream>

// Function Declaration:
void matrixAddition(int **A, int **B, int **C, int n);
void matrixSubtraction(int **A, int **B, int **C, int n);
void strassenMultiplication(int **A, int **B, int **C, int n);

// Driver Code:
int main()
{
    int n;
    std::cout << "Enter the size of matrices (power of 2): ";
    std::cin >> n;

    int **A = new int *[n];
    int **B = new int *[n];
    int **C = new int *[n];

    for (int i = 0; i < n; i++)
    {
        A[i] = new int[n];
        B[i] = new int[n];
        C[i] = new int[n];
    }

    std::cout << "Enter elements of matrix A:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Enter elements of matrix B:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> B[i][j];
        }
    }

    strassenMultiplication(A, B, C, n);

    std::cout << "Resultant matrix C:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << C[i][j] << " ";

        std::cout << std::endl;
    }

    return 0;
}

// Function Definition

void matrixAddition(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void matrixSubtraction(int **A, int **B, int **C, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassenMultiplication(int **A, int **B, int **C, int n)
{
    if (n == 2)
    {
        int P = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
        int Q = (A[1][0] + A[1][1]) * B[0][0];
        int R = A[0][0] * (B[0][1] - B[1][1]);
        int S = A[1][1] * (B[1][0] - B[0][0]);
        int T = (A[0][0] + A[0][1]) * B[1][1];
        int U = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
        int V = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

        C[0][0] = P + S - T + V;
        C[0][1] = R + T;
        C[1][0] = Q + S;
        C[1][1] = P + R - Q + U;
    }
    else
    {
        int newSize = n / 2;

        int **a = new int *[newSize];
        int **b = new int *[newSize];
        int **c = new int *[newSize];
        int **d = new int *[newSize];

        int **e = new int *[newSize];
        int **f = new int *[newSize];
        int **g = new int *[newSize];
        int **h = new int *[newSize];

        int **I = new int *[newSize];
        int **J = new int *[newSize];
        int **K = new int *[newSize];
        int **L = new int *[newSize];

        for (int i = 0; i < newSize; i++)
        {
            a[i] = new int[newSize];
            b[i] = new int[newSize];
            c[i] = new int[newSize];
            d[i] = new int[newSize];

            e[i] = new int[newSize];
            f[i] = new int[newSize];
            g[i] = new int[newSize];
            h[i] = new int[newSize];

            I[i] = new int[newSize];
            J[i] = new int[newSize];
            K[i] = new int[newSize];
            L[i] = new int[newSize];

            for (int j = 0; j < newSize; j++)
            {
                a[i][j] = A[i][j];
                b[i][j] = A[i][j + newSize];
                c[i][j] = A[i + newSize][j];
                d[i][j] = A[i + newSize][j + newSize];

                e[i][j] = B[i][j];
                f[i][j] = B[i][j + newSize];
                g[i][j] = B[i + newSize][j];
                h[i][j] = B[i + newSize][j + newSize];
            }
        }

        int **P1 = new int *[newSize];
        int **P2 = new int *[newSize];
        int **P3 = new int *[newSize];
        int **P4 = new int *[newSize];
        int **P5 = new int *[newSize];
        int **P6 = new int *[newSize];
        int **P7 = new int *[newSize];

        for (int i = 0; i < newSize; i++)
        {
            P1[i] = new int[newSize];
            P2[i] = new int[newSize];
            P3[i] = new int[newSize];
            P4[i] = new int[newSize];
            P5[i] = new int[newSize];
            P6[i] = new int[newSize];
            P7[i] = new int[newSize];
        }

        int **result1 = new int * [newSize];
        int **result2 = new int * [newSize];
        int **result3 = new int * [newSize];
        int **result4 = new int * [newSize];
        int **result5 = new int * [newSize];
        int **result6 = new int * [newSize];
        int **result7 = new int * [newSize];
        int **result8 = new int * [newSize];
        int **result9 = new int * [newSize];
        int **result10 = new int * [newSize];
        int **result11 = new int * [newSize];
        int **result12 = new int * [newSize];
        int **result13 = new int * [newSize];
        int **result14 = new int * [newSize];
        int **result15 = new int * [newSize];
        int **result16 = new int * [newSize];
        int **result17 = new int * [newSize];
        int **result18 = new int * [newSize];

        for (int i = 0; i < newSize; i++)
        {
            result1[i] =  new int[newSize];
            result2[i] =  new int[newSize];
            result3[i] =  new int[newSize];
            result4[i] =  new int[newSize];
            result5[i] =  new int[newSize];
            result6[i] =  new int[newSize];
            result7[i] =  new int[newSize];
            result8[i] =  new int[newSize];
            result9[i] =  new int[newSize];
            result10[i] = new int[newSize];
            result11[i] = new int[newSize];
            result12[i] = new int[newSize];
            result13[i] = new int[newSize];
            result14[i] = new int[newSize];
            result15[i] = new int[newSize];
            result16[i] = new int[newSize];
            result17[i] = new int[newSize];
            result18[i] = new int[newSize];
        }

        //P1 = A * (F - H)
        matrixSubtraction(f,h, result1, newSize);
        strassenMultiplication(a, result1, P1, newSize);

        //P2 = (A + B) * H
        matrixAddition(a, b, result2, newSize);
        strassenMultiplication(result2, h, P2, newSize);
        
        //P3 = (C + D) * E
        matrixAddition(c, d, result3, newSize);
        strassenMultiplication(result3, e, P3, newSize);

        //P4 = D * (G - E)
        matrixSubtraction(g, e, result4, newSize);
        strassenMultiplication(d, result4, P4, newSize);
        
        //P5 = (A + D) * (E + H)
        matrixAddition(a, d, result5, newSize);
        matrixAddition(e, h, result6, newSize);
        strassenMultiplication(result5, result6, P5, newSize);

        //P6 = (B - D) * (G + H)
        matrixSubtraction(b,d, result7, newSize);
        matrixAddition(g, h, result8, newSize);
        strassenMultiplication(result7, result8, P6, newSize);

        //P7 = (A - C) * (E + F)
        matrixSubtraction(a, c, result9, newSize);
        matrixAddition(e, f, result10, newSize);

        // I = P5 + P4 - P2 + P6
        matrixAddition(P5, P4, result11, newSize);
        matrixSubtraction(result11, P2, result12, newSize);
        matrixAddition(result12, P6, result13, newSize);

        for(int i = 0 ; i < newSize; i++)
            for(int j = 0 ; j < newSize ; j++)
                I[i][j] = result13[i][j];

        // J = P1 + P2
        matrixAddition(P1, P2, result14, newSize);
        
        for(int i = 0 ; i < newSize; i++)
            for(int j = 0 ; j < newSize ; j++)
                J[i][j] = result14[i][j];

        // K = P3 + P4
        matrixAddition(P3, P4, result15, newSize);

        for(int i = 0 ; i < newSize; i++)
            for(int j = 0 ; j < newSize ; j++)
                K[i][j] = result15[i][j];

        // L = P1 + P5 - (P3 + P7)
        matrixAddition(P1, P5, result16, newSize);
        matrixAddition(P3, P7, result17, newSize);
        matrixSubtraction(result16, result17, result18, newSize);
        

        for(int i = 0 ; i < newSize; i++)
            for(int j = 0 ; j < newSize ; j++)
                L[i][j] = result18[i][j];
        


        for (int i = 0; i < newSize; i++)
        {
            for (int j = 0; j < newSize; j++)
            {
                C[i][j] = I[i][j];
                C[i][j + newSize] = J[i][j];
                C[i + newSize][j] = K[i][j];
                C[i + newSize][j + newSize] = L[i][j];
            }
        }
    }
}
