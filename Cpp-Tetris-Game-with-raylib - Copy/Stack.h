#ifndef __STACK__
#define __STACK__

#include <iostream>

template <class T>
class Stack{
    private:
        T* arr;
        int top;
        int size;
    public:
        Stack(int size);
        void push(T val);
        void pop();
        T peek();
        bool isEmpty();
        bool isFull();
};

template <typename T>
Stack<T>::Stack(int size){
    this->size = size;
    arr = new T[size];
    top = -1;
}

template <typename T>
void Stack<T>::push(T val){
    if(isFull()){
        std::cout << "Stack is full" << std::endl;
        return;
    }
    arr[++top] = val;
}

template <typename T>
void Stack<T>::pop(){
    if(isEmpty()){
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    top--;
}

template <typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return nullptr; // Return nullptr instead of -1 for pointer types
    }
    return arr[top];
}


template <typename T>
bool Stack<T>::isEmpty(){
    return top == -1;
}

template <typename T>
bool Stack<T>::isFull(){
    return top == size - 1;
}
#endif