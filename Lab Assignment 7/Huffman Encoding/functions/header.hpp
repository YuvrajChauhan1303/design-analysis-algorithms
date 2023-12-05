#ifndef HEADER_HPP
#define HEADER_HPP
#define ln cout << endl

#include <iostream>
using namespace std;

class huffmanCode;
class huffmanTree;

void huffmanSort(huffmanCode *h, int p, int r);
void huffmanMerge(huffmanCode *h, int p, int q, int r);
void display(huffmanCode *h, int size);

#endif