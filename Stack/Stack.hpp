#pragma once
#include <stdlib.h>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
    T *stack;
    int limit;

public:
    int length;
    Stack() : length(0), stack((T *)malloc(sizeof(T) * length)), limit(-1) {}
    Stack(T data) : length(0), stack((T *)malloc(sizeof(T) * length))
    {
        this->push(data);
    }
    Stack(Stack<T> *st) : length(0), stack((T *)malloc(sizeof(T) * length)), limit(-1)
    {
        this->push(st);
    }

    void setLimit(int lt)
    {
        limit = lt;
        if (limit > 0 && this->length > limit)
            stack = (T *)realloc(stack, sizeof(T) * length);
    }

    int getLimit()
    {
        return limit;
    }

    void push(T data)
    {
        if (limit > 0 && this->length >= limit)
            return;
        length++;
        stack = (T *)realloc(stack, sizeof(T) * length);
        stack[length - 1] = data;
    }

    void push(Stack<T> st)
    {
        for (int i = 0; i < st.length; i++)
            this->push(st.stack[i]);
    }

    void operator<<(T data)
    {
        this->push(data);
    }

    void operator+=(T data)
    {
        this->push(data);
    }

    void operator<<(Stack<T> st)
    {
        this->push(st);
    }

    void operator+=(Stack<T> st)
    {
        this->push(st);
    }

    void pop()
    {
        if (length <= 0)
            return;
        length--;
        stack = (T *)realloc(stack, sizeof(T) * length);
    }

    T operator[](int pos)
    {
        return stack[length - pos];
    }

    T pos(int pos)
    {
        return stack[length - pos];
    }

    bool isEmpty()
    {
        if (length == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (limit > 0 && length >= limit)
            return true;
        return false;
    }

    void empty()
    {
        length = 0;
        stack = (T *)realloc(stack, sizeof(T) * length);
    }

    T top()
    {
        return this->pos(1);
    }

    T bottom()
    {
        return this->pos(length);
    }

    Stack<T> operator+(Stack<T> st2)
    {
        Stack<T> st;

        st.push(*this);
        st.push(st2);

        return st;
    }

    string join(string concatinator)
    {
        string str;
        for (int i = 1; i < length; i++)
            str += to_string(this->pos(i)) + concatinator;
        str += to_string(this->bottom());
        return str;
    }
};

template <>
string Stack<char>::join(string concatinator)
{
    string str;
    for (int i = 1; i < length; i++)
        str += this->pos(i) + concatinator;
    str += this->bottom();

    return str;
}

template <>
string Stack<string>::join(string concatinator)
{
    string str;
    for (int i = 1; i < length; i++)
        str += this->pos(i) + concatinator;
    str += this->bottom();

    return str;
}