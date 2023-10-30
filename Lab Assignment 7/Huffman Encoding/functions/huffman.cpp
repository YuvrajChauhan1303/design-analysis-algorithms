#ifndef HUFFMAN
#define HUFFMAN

class huffmanCode
{
private:
    char character;
    int frequecy;
    int size;
    bool * arr;

public:
    huffmanCode();
    void setData(char c, int f);
    int getFreq();
    char getChar();
};

huffmanCode::huffmanCode()
{
    this->character = '\0';
    this->frequecy = 0;
}

void huffmanCode::setData(char c, int f)
{
    this->character = c;
    this->frequecy = f;
}

int huffmanCode::getFreq()
{
    return this->frequecy;
}
char huffmanCode::getChar()
{
    return this->character;
}

#endif