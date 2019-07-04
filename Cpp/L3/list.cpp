#include "list.h"

template<typename T> Node<T>::Node(T data) : data(data)
{
    prev = 0;
    next = 0;
}

template<typename T> List<T>::List() : root(0), end(0), size(0) {}

template<typename T> void List<T>::push_back(T data)
{
    if (root == 0)
    {
        root = new Node<T>(data);
        end = root;
    }
    else
    {
        Node<T> * current = root;
        while (current->next != 0)
        {
            current = current->next;
        }
        current->next = new Node<T>(data);
        end = current->next;
        current->next->prev = current;
    }
    size++;
}

template<typename T> List<T>::~List()
{
    Node<T>* current = root;
    while (current->next != 0)
    {
        current = current->next;
        delete current->prev;
    }
    delete current;
}

template<typename T> Node<T>* List<T>::Merge(Node<T>* h1, Node<T>* h2)
{
    Node<T> *t1;
    Node<T> *t2;
    Node<T> *temp;

    if (h1 == NULL)
        return h2;

    if (h2 == NULL)
        return h1;

    t1 = h1;

    while (h2 != NULL)
    {
        t2 = h2;
        h2 = h2->next;
        t2->next = NULL;
        if (t2->data < h1->data)
        {
            t2->next = h1;
            h1->prev = t2;
            h1 = t2;
            t1 = h1;
            continue;
        }

        flag:
        if (t1->next == NULL)
        {
            t1->next = t2;
            t2->prev = t1;
            t1 = t1->next;
        }
        else if ((t1->next)->data <= t2->data)
        {
            t1 = t1->next;
            goto flag;
        }
        else
        {
            temp = t1->next;
            temp->prev = t1;
            t1->next = t2;
            t2->prev = t1;
            t2->next = temp;
            temp->prev = t2;
        }
    }

    return h1;
}

template<typename T>
void List<T>::sort(Node<T>* l)
{
    Node<T>* head = root;
    Node<T> *first;
    Node<T> *second;
    Node<T> *temp;
    first = head;
    temp = head;

    if (first == NULL || first->next == NULL)
    {
        return;
    }
    else
    {
        while (first->next != NULL)
        {
            first = first->next;
            if (first->next != NULL)
            {
                temp = temp->next;
                first = first->next;
            }
        }
        second = temp->next;
        temp->next = NULL;
        first = head;
    }

    sort(first);
    sort(second);

    head = Merge(first, second);
}

template<typename T>
T List<T>::operator [] (int i)
{
    Node<T>* current = root;
    int c = 0;
    while (current->next != 0)
    {
        if (c == i) {
            return current->data;
        }
        c++;
    }
    return current->data;
}