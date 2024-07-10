#include "main.h"

template <typename T>
bool Buffer<T>::Iterator::operator>(const Buffer::Iterator &iter)
{
  return tmp > iter.tmp;
}
template <typename T>
bool Buffer<T>::Iterator::operator<(const Buffer::Iterator &iter)
{
  return tmp < iter.tmp;
}
template <typename T>
bool Buffer<T>::Iterator::operator==(const Buffer::Iterator &iter)
{
  return tmp == iter.tmp;
}
template <typename T>
bool Buffer<T>::Iterator::operator!=(const Buffer::Iterator &iter)
{
  return tmp != iter.tmp;
}

template <typename T>
void Buffer<T>::push_back(const T &x)
{
  if (cur_size < capacity)
  {
    if (Begin == nullptr)
    {
      cur_size++;
      *End = x;
      Begin = End;
      End++;
    }
    else
    {
      *End = x;
      End++;
      cur_size++;
    }
  }

  else
  {
    arr[pb_i] = x;
    pb_i = (pb_i + 1) % capacity;
  }
}

template <typename T>
void Buffer<T>::pop_back()
{
  if (cur_size > 0)
  {
    cur_size--;
    End--;
  }
}
template <typename T>
void Buffer<T>::push_front(const T &x)
{
  if (cur_size < capacity)
  {
    if (Begin == nullptr)
    {
      cur_size++;
      *End = x;
      Begin = End;
      End++;
    }
    else
    {
      for (Iterator i = End - 1; i >= Begin; i--)
      {
        *(i + 1) = *i;
      }
      *Begin = x;
      End++;
      cur_size++;
    }
  }
  else
  {
    arr[pf_i] = x;

    pf_i = (pf_i + capacity - 1) % capacity;
  }
}
template <typename T>
void Buffer<T>::pop_front()
{
  for (Iterator i = Begin + 1; i < End; i++)
  {
    *(i - 1) = *i;
  }
  cur_size--;
  End--;
}

template <typename T>
void Buffer<T>::show()
{
  for (size_t i = 0; i < cur_size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << '\n';
}

template <typename T>
void Buffer<T>::insert(size_t i, T x)
{
  *(Begin + (i - *Begin) % cur_size) = x;
}

template <typename T>
void Buffer<T>::Delete(size_t i)
{

  for (size_t j = i; j < cur_size - 1; j++)
  {
    arr[j] = arr[j + 1];
  }
  End--;
  cur_size--;
}
template <typename T>
void Buffer<T>::resize(size_t n)
{
  if (n == capacity)
    return;

  T *mas = new T[n];

  for (size_t i = 0; i < n; i++)
  {
    mas[i] = arr[i];
  }

  delete[] arr;
  arr = mas;
  capacity = n;
  if (cur_size > n)
  {
    cur_size = n;
    *End = cur_size;
  }
  pf_i = 0;
  pb_i = 0;
}

bool comp(int a, int b)
{
  return a>b;
}



int main()
{
  int x = 5;
  Buffer<int> cbuf(x);
  cbuf.push_back(1);
  cbuf.push_back(4);
  cbuf.push_back(2);
  cbuf.push_back(5);
  cbuf.push_back(3);
  cbuf.show();
  sort(cbuf.begin(), cbuf.end(), comp);
  cbuf.show();
}