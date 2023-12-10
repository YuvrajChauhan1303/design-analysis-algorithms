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

    char getLabel() const;
    int getFromIndex() const;
    int getToIndex() const;
    int getWeight() const;
};


char edge::getLabel() const
{
    return label;
}

int edge::getFromIndex() const
{
    return fromIndex;
}

int edge::getToIndex() const
{
    return toIndex;
}

int edge::getWeight() const
{
    return weight;
}
