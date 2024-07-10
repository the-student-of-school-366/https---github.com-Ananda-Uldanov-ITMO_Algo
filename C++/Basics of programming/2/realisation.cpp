#include"realisation.h"
using namespace std;

SetOfTwo::SetOfTwo(int MaxSize): size(0)
{
    maxSize = MaxSize;
    array = new int[maxSize];
}

SetOfTwo::SetOfTwo(SetOfTwo &other) : size(other.size), maxSize(other.maxSize)
{
    
    array = new int[maxSize];
    copy(other.array, other.array + size, array);
}

SetOfTwo::~SetOfTwo(){
    delete[] array;
}

void SetOfTwo::Add(int element)
{
    for(int i=0; i<size;i++)
    {
        if(element==array[i])
        {
            cout<<"Element already added";
            return;
        }
    }
    if (size + 1 > maxSize)
    {
        cout << "\nSet is full - cant add element";
        return;
    }
    else
    {
        array[size] = element;
        size++;
    }
}

void SetOfTwo::Delete(int element)
{
    int indx = -1;
    if (size == 0)
    {
        cout << "\nSet is empty";
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            indx = i;
            break;
        }
    }
    if (indx != -1)
    {
        for (int i = indx; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }
    else
    {
        cout << "\nElement not in set";
    }
}

bool SetOfTwo:: Check(int element)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return true;
        }
    }
    return false;
}

SetOfTwo SetOfTwo:: Union(SetOfTwo &other)
{
    SetOfTwo result(maxSize);
    for (int i = 0; i < size; i++)
    {
        result.Add(array[i]);
    }
    for (int i = 0; i < other.size; i++)
    {
        result.Add(other.array[i]);
    }

    return result;
}

SetOfTwo SetOfTwo:: Intersection(SetOfTwo &other)
{
    SetOfTwo result(maxSize);
    for (int i = 0; i < size; i++)
    {
        if (other.Check(array[i]))
        {
            result.Add(array[i]);
        }
    }

    return result;
}

void SetOfTwo::Print()
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << ' ';
    }
};

int Start()
{
    int MaxSize;
    cout << "Enter max size of first set:";
    cin >> MaxSize;
    SetOfTwo array(MaxSize);
    cout << "\n1. Add.\n2. Delete.\n3. Check.\n4. Union.\n5. Intersection. \n6. Show. \n7. Stop.\n";
    int choice;
    char choose;
    bool exit = false;
    int element, maxsize;
    while (cin >> choice && !exit)
    {
        if (choice == 1)
        {
            cout << "\n(Add) Enter element:";
            cin >> element;
            array.Add(element);
        }
        else if (choice == 2)
        {
            cout << "\n(Delete) Enter element:";
            cin >> element;
            array.Delete(element);
        }
        else if (choice == 3)
        {
            cout << "\n(Check) Enter element:";
            cin >> element;
            if(array.Check(element))
                cout<<"\n This element was added";
            else
                cout<<"\n This element was not added";
        }
        else if (choice == 4)
        {
            cout << "\n(Union) Enter max size of second set:";
            cin >> maxsize;
            SetOfTwo array2(maxsize);
            cout << "Enter element of second set:";
            while (choose != 'n')
            {
                array2.Add(element);
                cout << "Enter another element? (y/n) :";
                cin >> choose;
            }
            SetOfTwo res_union = array.Union(array2);
            cout << "Res:\n";
            res_union.Print();
        }
        else if (choice == 5)
        {
            cout << "\n(Intersection) Enter max size of second set:";
            cin >> maxsize;
            SetOfTwo array3(maxsize);
            cout << "Enter element of second set:";
            while (choose != 'n')
            {
                array3.Add(element);
                cout << "Enter another element? (y/n) :";
                cin >> choose;
            }
            SetOfTwo res_intersection = array.Union(array3);
            cout << "Res:\n";
            res_intersection.Print();
        }
        else if (choice == 6)
        {
            array.Print();
        }
    }
};