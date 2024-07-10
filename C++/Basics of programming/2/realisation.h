#pragma one
#include <iostream>
using namespace std;
class SetOfTwo
{
private:
    int *array;
    int size;
    int maxSize;

public:
    SetOfTwo() = default;
    SetOfTwo(int MaxSize);
    SetOfTwo(SetOfTwo &other);
    ~SetOfTwo();
    void Add(int element);
    void Delete(int element);
    bool Check(int element);
    SetOfTwo Union(SetOfTwo &other);
    SetOfTwo Intersection(SetOfTwo &other);
    void Print();
};
