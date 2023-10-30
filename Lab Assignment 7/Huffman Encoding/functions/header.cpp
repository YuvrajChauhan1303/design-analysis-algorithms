#ifndef HEADER_CPP
#define HEADER_CPP

#define ln cout << endl

#include "header.hpp"
#include "huffman.cpp"

void huffmanSort(huffmanCode *h, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        huffmanSort(h, p, q);
        huffmanSort(h, q + 1, r);
        huffmanMerge(h, p, q, r);
    }
}
void huffmanMerge(huffmanCode *h, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    huffmanCode *leftArr = new huffmanCode[n1];
    huffmanCode *rightArr = new huffmanCode[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = h[p + i];

    for (int j = 0; j < n2; j++)
        rightArr[j] = h[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (leftArr[i].getFreq() > rightArr[j].getFreq())
        {
            h[k] = leftArr[i];
            i++;
        }
        else
        {
            h[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        h[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        h[k] = rightArr[j];
        j++;
        k++;
    }
}
void display(huffmanCode *h, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Character: " << h[i].getChar() << endl;
        cout << "Frequency: " << h[i].getFreq() << endl;
        ln;
    }
}



#endif