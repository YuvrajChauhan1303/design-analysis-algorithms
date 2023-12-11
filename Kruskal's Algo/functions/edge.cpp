class edge
{
private:
    char label;
    int fromIndex;
    int toIndex;
    int weight;

public:
    edge(char label, int fromIndex, int toIndex, int weight)
    {
        this->label = label;
        this->fromIndex = fromIndex;
        this->toIndex = toIndex;
        this->weight = weight;
    }

    char getLabel();
    int getFromIndex();
    int getToIndex();
    int getWeight();
};


char edge::getLabel()
{
    return label;
}

int edge::getFromIndex()
{
    return fromIndex;
}

int edge::getToIndex()
{
    return toIndex;
}

int edge::getWeight()
{
    return weight;
}
