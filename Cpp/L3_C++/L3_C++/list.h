#pragma once
#ifndef _LIST_H_
#define _LIST_H_


template<typename T> class Node 
{
public:
	T data;
	Node* prev;  
	Node* next;
	Node(T data);
};

template<typename T> class List 
{
private:
	Node<T>* root;
	Node<T>* end;
	int size;
public:
	List();
	void push_back(T data);
	~List();
	Node<T>* Merge(Node<T>* h1, Node<T>* h2);
	void sort(Node<T>* l = 0);
	T operator [] (int i);
};

#include "list.cpp"

#endif