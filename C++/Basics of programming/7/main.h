#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
template <typename T>
class Buffer
{
private:
    T *arr;
    size_t cur_size;
    size_t capacity;

public:
    class Iterator : public iterator<random_access_iterator_tag, T>
    {
    private:
        T *tmp;

    public:
        Iterator() {}
        Iterator(T *pointer) : tmp(pointer) {}
        ~Iterator() = default;

        T &operator*()
        {
            return *tmp;
        }

        T *operator->()
        {
            return tmp;
        }

        Iterator &operator+=(size_t x)
        {
            tmp += x;
            return *this;
        }

        Iterator &operator-=(size_t x)
        {
            tmp -= x;
            return *this;
        }

        Iterator operator+(size_t x)
        {
            return Iterator(x + tmp);
        }

        Iterator operator-(size_t x)
        {
            return Iterator(tmp - x);
        }

        Iterator operator++()
        {
            tmp++;
            return *this;
        }

        Iterator operator++(T)
        {
            Iterator iterator(*this);
            ++tmp;
            return iterator;
        }

        Iterator operator--()
        {
            tmp--;
            return *this;
        }

        Iterator operator--(T)
        {
            Iterator iterator(*this);
            --tmp;
            return iterator;
        }

        bool operator>(const Iterator &iter);
        bool operator<(const Iterator &iter);
        bool operator==(const Iterator &iter);
        bool operator!=(const Iterator &iter);

        bool operator<=(Iterator &iter)
        {
            return tmp <= iter.tmp;
        }

        bool operator>=(Iterator &iter)
        {
            return tmp >= iter.tmp;
        }

        using difference_type = typename iterator<random_access_iterator_tag, T>::difference_type;

        difference_type operator-(Iterator &iterator)
        {
            return (tmp - iterator.tmp);
        }
    };

    T &operator[](size_t x) const
    {
        return arr[x % capacity];
    }

    Iterator Begin = nullptr;
    Iterator End = nullptr;

    size_t pb_i = 0;
    size_t pf_i = 0;

    void init(int begin_i, int end_i)
    {
        arr = new T[capacity];

        if (begin_i > -1)
        {
            Begin = &arr[begin_i];
        }

        End = &arr[end_i];
    }

public:
    Buffer(size_t n)
    {
        capacity = n;
        arr = new T[n];
        cur_size = 0;
        init(-1, 0);
    }

    Buffer(const Buffer &buf)
    {
        capacity = buf.capacity;
        cur_size = buf.size;
        arr = new T[capacity];
        init(0, capacity);

        for (size_t i = 0; i < cur_size; i++)
        {
            arr[i] = buf.arr[i];
        }
    }

    ~Buffer()
    {
        delete[] arr;
    }

    Iterator begin() { return Begin; }

    Iterator end() { return End; }

    void push_back(const T &x);

    void pop_back();

    void push_front(const T &x);

    void pop_front();

    void show();

    void insert(size_t i, T x);

    void Delete(size_t i);

    void resize(size_t n);
};
