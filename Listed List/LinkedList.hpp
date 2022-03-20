#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class LinkedList
{

private:
    class Node;
    Node *head;

public:
    int length;
    LinkedList() : length(0) {}
    LinkedList(T data) : length(1)
    {
        head = new Node(data);
    }

    LinkedList(LinkedList<T> *ll2) : length(0)
    {
        for (int i = 0; i < ll2->length; i++)
            this->insert(ll2->operator[](i));
    }

    void insert_head(T data)
    {
        if (length != 0)
        {
            Node *newHead = new Node(data);

            newHead->next = head;
            head = newHead;
        }
        else
            head = new Node(data);
        length++;
    }

    void insert(T data)
    {
        if (length != 0)
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }

            curr->next = new Node(data);
        }
        else
            head = new Node(data);

        length++;
    }

    void insert(T data, int index)
    {
        if (index == 0)
            this->insert_head(data);
        else if (index <= length)
        {
            int i = 0;
            Node *curr = head;
            while (i < index - 1)
            {
                curr = curr->next;
                i++;
            }
            Node *next = curr->next;
            curr->next = new Node(data);
            curr->next->next = next;
        }
        else
            return;
        length++;
    }

    void del(int index)
    {
        if (index >= length)
            return;
        else if (index == 0)
        {
            Node *curr = head->next;
            delete head;
            head = curr;
        }
        else
        {
            Node *curr = head;
            int i = 0;
            while (i < index - 1)
            {
                curr = curr->next;
                i++;
            }
            Node *next = curr->next->next;
            delete curr->next;
            curr->next = next;
        }
        length--;
    }

    void update(T data, int index)
    {
        if (index >= length)
            return;

        if (index == 0)
        {
            head->data = data;
            return;
        }

        Node *curr = head;
        int i = 0;
        while (i <= index)
        {
            curr = curr->next;
            i++;
        }
        curr->data = data;
    }

    T operator[](int index)
    {
        if (index >= length || index == 0)
        {
            return head->data;
        }

        Node *curr = head;
        int i = 0;
        while (i < index)
        {
            curr = curr->next;
            i++;
        }
        return curr->data;
    }

    int search(T data)
    {
        int is = -1;
        int i = 0;
        Node *curr = head;
        while (i < length)
        {
            if (curr->data == data)
            {
                is = i;
                break;
            }
            curr = curr->next;
            i++;
        }

        return is;
    }

    string join(string connector)
    {
        string str;
        Node *curr = head;
        while (curr->next != NULL)
        {
            str += to_string(curr->data) + connector;
            curr = curr->next;
        }
        str += to_string(curr->data);

        return str;
    }

    LinkedList<T> operator+(LinkedList<T> ll2)
    {
        LinkedList<T> ll(this);

        for (int i = 0; i < ll2.length; i++)
            ll.insert(ll2[i]);

        return ll;
    }

    void operator+=(LinkedList<T> ll2)
    {
        for (int i = 0; i < ll2.length; i++)
            this->insert(ll2[i]);
    }

    LinkedList<T> map(T (*callback)(T))
    {
        LinkedList<T> newll;
        for (int i = 0; i < this->length; i++)
        {
            T data = callback(this->operator[](i));
            newll.insert(data);
        }

        return newll;
    }

    LinkedList<T> map(T (*callback)(T, int))
    {
        LinkedList<T> newll;
        for (int i = 0; i < this->length; i++)
        {
            T data = callback(this->operator[](i), i);
            newll.insert(data);
        }

        return newll;
    }

    LinkedList<T> map(T (*callback)(T, int, LinkedList<T> *))
    {
        LinkedList<T> newll;
        for (int i = 0; i < this->length; i++)
        {
            T data = callback(this->operator[](i), i, this);
            newll.insert(data);
        }

        return newll;
    }
};

template <class T>
class LinkedList<T>::Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <>
string LinkedList<char>::join(string connector)
{
    string str;
    Node *curr = head;
    while (curr->next != NULL)
    {
        str += curr->data + connector;
        curr = curr->next;
    }
    str += curr->data;

    return str;
}

template <>
string LinkedList<string>::join(string connector)
{
    string str;
    Node *curr = head;
    while (curr->next != NULL)
    {
        str += curr->data + connector;
        curr = curr->next;
    }
    str += curr->data;

    return str;
}