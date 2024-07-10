#include <iostream>

template<class T>
class Stack {
 private:
  int top;
  T *arr;
  T max = -1;
  int size;
 public:

  Stack(int n); 

  void push(T x);
  T pop();
  T getMax();
};

template<class T>
Stack<T>::Stack(int n) {
  arr = new T[n];
  size  = n;
  top = -1;
}

class StackOverflow{};
class EmptyStack{};

template<class T>
void Stack<T>::push(T x) {
  top++;
  if(top + 1 > size){
    throw StackOverflow();
  }
  arr[top] = x;

  if (top == 0) {
    max = x;
  }
  else if (x >= max) {
    max = x;
  }
}

template<class T>
T Stack<T>::pop() {
  if(top == -1){
    throw EmptyStack();
  }
  T element = arr[top];
  top--;
  return element;
}

template<class T>
T Stack<T>::getMax() {
  return max;
}

int main() {
  int N;
  int x;
  std::string command;
  std::cin >> N;
  Stack<int> stack(N);

  while(std::cin >> command) {
    if (command == "push") {
      try {
          std::cin >> x;
          stack.push(x);
      }
      catch (StackOverflow) {
        std::cout << "Stack overflow" << '\n';
      }
    }

    else if (command == "Max") {
      std::cout << "Max element = " << stack.getMax() << '\n';
    }

    else if (command == "pop") {
      try {
        std::cout << stack.pop();
      }
      catch (EmptyStack) {
        std::cout << "Stack is empty" << '\n';
      }
    }
  }
}