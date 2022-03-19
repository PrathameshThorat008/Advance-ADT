#pragma once
#include <stdlib.h>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>
class Array
{
private:
    T *arr;

public:
    int length;
    Array() : length(0), arr((T *)malloc(sizeof(T) * length)){};
    Array(Array<T> *arr2)
        : length(0), arr((T *)malloc(sizeof(T) * length))
    {
        for (int i = 0; i < arr2->length; i++)
            this->add(arr2->operator[](i));
    };

    void add(T el)
    {
        length++;
        arr = (T *)realloc(arr, sizeof(T) * length);

        arr[length - 1] = el;
    }

    void add(T el, int index)
    {
        length++;
        arr = (T *)realloc(arr, sizeof(T) * length);

        for (int i = length - 1; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = el;
    }

    void operator<<(T el)
    {
        add(el);
    }

    void remove()
    {
        length--;
        arr = (T *)realloc(arr, sizeof(T) * length);
    }

    void remove(int index)
    {
        length--;

        for (int i = index; i < length; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr = (T *)realloc(arr, sizeof(T) * length);
    }

    void update(T el, int index)
    {
        arr[index] = el;
    }

    int linearSearch(T el)
    {
        int index = -1;
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == el)
            {
                index = i;
                break;
            }
        }
        return index;
    }

    int binarySearch(T el)
    {
        int index = -1;

        int s = 0, e = length;

        while (1)
        {
            int mid = (s + e) / 2;
            if (arr[mid] == el)
            {
                index = mid;
                break;
            }
            else if (arr[s] == el)
            {
                index = s;
                break;
            }
            else if (arr[e] == el)
            {
                index = e;
                break;
            }
            else if (arr[mid] < el)
                s = mid + 1;
            else if (arr[mid] > el)
                e = mid - 1;
        }
        return index;
    }

    void rotate(int noOfElements)
    {
        noOfElements %= length;
        int gcd = __gcd(length, noOfElements);

        for (int i = 0; i < gcd; i++)
        {
            T temp = arr[i];
            int j = i;
            while (1)
            {
                int k = j + noOfElements;

                if (k >= length)
                    k = k - length;

                if (k == i)
                    break;

                arr[j] = arr[k];
                j = k;
            }
            arr[j] = temp;
        }
    }

    void sort()
    {
        for (int i = 0; i < length; i++)
        {
            for (int j = i; j < length; j++)
            {
                if (arr[j] < arr[i])
                {
                    T temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }

    T &get(int index)
    {
        return arr[index];
    }

    T &operator[](int index)
    {
        return arr[index];
    }

    string join(string connector)
    {
        string str;
        for (int i = 0; i < length; i++)
        {
            if (i < length - 1)
                str += to_string(arr[i]) + connector;
            else
                str += to_string(arr[i]);
        }

        return str;
    }

    Array<T> operator+(Array<T> arr2)
    {
        Array<T> x(this);

        for (int i = 0; i < arr2.length; i++)
            x.add(arr2[i]);

        return x;
    }

    void operator+=(Array<T> arr2)
    {
        for (int i = 0; i < arr2.length; i++)
            add(arr2[i]);
    }

    Array<T> map(T (*callback)(T))
    {
        Array<T> newArr;
        for (int i = 0; i < this->length; i++)
        {
            T data = callback(arr[i]);
            newArr.add(data);
        }

        return newArr;
    }

    Array<T> map(T (*callback)(T, int))
    {
        Array<T> newArr;
        for (int i = 0; i < this->length; i++)
        {
            T data = callback(arr[i], i);
            newArr.add(data);
        }

        return newArr;
    }

    Array<T> map(T (*callback)(T, int, Array<T> *))
    {
        Array<T> newArr;
        for (int i = 0; i < this->length; i++)
        {
            T data = callback(arr[i], i, this);
            newArr.add(data);
        }

        return newArr;
    }

    ~Array()
    {
        free(arr);
    }
};

template <>
string Array<char>::join(string connector)
{
    string str;
    for (int i = 0; i < length; i++)
    {
        if (i < length - 1)
            str += arr[i] + connector;
        else
            str += arr[i];
    }

    return str;
}

template <>
string Array<string>::join(string connector)
{
    string str;
    for (int i = 0; i < length; i++)
    {
        if (i < length - 1)
            str += arr[i] + connector;
        else
            str += arr[i];
    }

    return str;
}