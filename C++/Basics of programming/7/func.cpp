#include "main.h"

template<typename T>
bool Cbuffer<T>::Iterator::operator>(const Cbuffer::Iterator &iter) {
  return ptr > iter.ptr;
}
template<typename T>
bool Cbuffer<T>::Iterator::operator<(const Cbuffer::Iterator &iter) {
  return ptr < iter.ptr;
}
template<typename T>
bool Cbuffer<T>::Iterator::operator==(const Cbuffer::Iterator &iter) {
  return ptr == iter.ptr;
}
template<typename T>
bool Cbuffer<T>::Iterator::operator!=(const Cbuffer::Iterator &iter) {
  return ptr != iter.ptr;
}

template<typename T>
void Cbuffer<T>::push_back(const T& x) {
  if(cur_size < capacity) {
    if (Begin == nullptr) {
      cur_size++;
      *End = x;
      Begin = End;
      End++;
    } else {
      *End = x;
      End++;
      cur_size++;
    }
  }

  else{
    arr[pb_i] = x;
    pb_i = (pb_i + 1) % capacity;
  }
}

template<typename T>
void Cbuffer<T>::pop_back() {
  if(cur_size > 0){
    cur_size--;
    End--;
  }
}
template<typename T>
void Cbuffer<T>::push_front(const T &x) {
  if(cur_size < capacity) {
    if (Begin == nullptr) {
      cur_size++;
      *End = x;
      Begin = End;
      End++;
    } else {
      for(Iterator i = End - 1; i >= Begin; i--) {
        * (i + 1) = *i;
      }
      *Begin = x;
      End++;
      cur_size++;
    }
  }
  else {
    arr[pf_i] = x;

    pf_i = (pf_i + capacity - 1) % capacity;
  }
}
template<typename T>
void Cbuffer<T>::pop_front() {
  for(Iterator i = Begin + 1; i < End; i++){
    * (i - 1) = *i;
  }
  cur_size--;
  End--;
}

template<typename T>
void Cbuffer<T>::show() {
  for(size_t i = 0; i < cur_size;i++){
    cout << arr[i] << " ";
  }
  cout << '\n';
}

template<typename T>
void Cbuffer<T>::insert(size_t i,T x) {
  *(Begin + (i - *Begin) % cur_size) = x;
}

template<typename T>
void Cbuffer<T>::Delete(size_t i) {
  if (i = *Begin) {
    pop_front();
  } else if (i = *End) {
    pop_back();
  } else {
    for (size_t j = i; j < cur_size - 1; j++) {
      arr[j] = arr[j + 1];
    }
    End--;
    cur_size--;
  }
}
template<typename T>
void Cbuffer<T>::resize(size_t n) {
  if (n == capacity) return;

  T *mas = new T[n];

  for (size_t i = 0; i < n; i++) {
    mas[i] = arr[i];
  }

  delete[] arr;
  arr = mas;
  capacity = n;
  if(cur_size > n){
    cur_size = n;
    *End = cur_size;
  }
  pf_i = 0;
  pb_i = 0;
}

int main() {
  int ew = 5;
  Cbuffer<int> meow(ew);
  meow.push_front(1);
  meow.show();
  meow.push_front(3);
  meow.push_back(4);
  meow.show();
  sort(meow.begin(), meow.end());
  meow.show();
  meow.pop_back();
  meow.show();
  meow.push_back(9);
  meow.insert(5,4);
  meow.show();
  meow.Delete(1);
  meow.show();
  meow.resize(1);
  meow.show();
  return 0;
}