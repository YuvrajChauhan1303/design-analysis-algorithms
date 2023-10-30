#include "functions/header.hpp"
#include "functions/huffman.cpp"

/*
    1. input characters from user
    2. input frequency of character from user
    3. sort accordingly -> descending order
*/

int main()
{
    int size;
    char c;
    int f;

    cout << "Enter the Number of elements: ";
    cin >> size;

    huffmanCode *h = new huffmanCode[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter Character: ";
        cin >> c;
        cout << "Enter Frequency of " << c << " : ";
        cin >> f;

        h[i].setData(c, f);
    }

    return 0;
}