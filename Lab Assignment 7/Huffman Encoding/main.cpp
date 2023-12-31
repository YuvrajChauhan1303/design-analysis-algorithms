#include "functions/header.hpp"
#include "functions/header.cpp"
#include "functions/huffman.cpp"

#define ln cout << endl

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

    ln;
    cout << "Before Sort: ";
    ln;
    display(h, size);

    huffmanSort(h, 0, size - 1);

    cout << "After Sort: ";
    ln;
    display(h, size);

    return 0;
}