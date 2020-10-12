#pragma once
#include <iostream>
#include <initializer_list>

template <typename T>
struct Node
{
	Node* prev = nullptr;
	Node* next = nullptr;
	T     data;
};

template <typename T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	LinkedList(std::initializer_list<T> init);
	
public:
	void     push_back(T data);
	Node<T>* search(T target);
	void     remove(Node<T>*& target);
	size_t   size();
	void     print();

public:
	friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
	{
		Node<T>* itr = list.head;

		while (itr != nullptr)
		{
			os << itr->data;
			if (itr->next != nullptr)
			{
				os << ", ";
			}

			itr = itr->next;
		}

		return os;
	}
	
	LinkedList<T>&       operator+=(const LinkedList<T>& other);

private:
	Node<T>* head;
	Node<T>* tail;
};

template<typename T>
inline LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template<typename T>
LinkedList<T>::~LinkedList()
{
    while(head != nullptr)
    {
        Node<T>* delNode = head;
        remove( delNode );
    }
}

template<typename T>
inline LinkedList<T>::LinkedList(std::initializer_list<T> init) : head(nullptr), tail(nullptr)
{
	for(T elem : init)
	{
		push_back(elem);
	}
}

template<typename T>
 inline void LinkedList<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>;
		head->data = data;
		head->prev = nullptr;
		head->next = nullptr;
		tail = head;
	}
	else
	{
		Node<T>* temp = new Node<T>;
		temp->data = data;
		temp->prev = tail;
		temp->next = nullptr;

		tail->next = temp;
		tail = temp;
	}
}

 template<typename T>
 inline Node<T>* LinkedList<T>::search(T target)
 {
	 Node<T>* currentNode = head;

	while(currentNode != nullptr)
	{
		if (currentNode->data == target) { return currentNode; }
		currentNode = currentNode->next;
	}

	return nullptr;
 }

 template<typename T>
 inline void LinkedList<T>::remove(Node<T>*& target)
 {
	if(target != nullptr)
	{
		if(target->prev != nullptr)
		{
			if(target->next != nullptr)
			{
				target->prev->next = target->next;
			}

			else
			{
				target->prev->next = nullptr;
			}
		}

		if(target->next != nullptr)
		{
			if(target->prev != nullptr)
			{
				target->next->prev = target->prev;
			}

			else
			{
				target->next->prev = nullptr;
			}
		}

		if(target == head)
		{
		    head = head->next;
		}

		if(target == tail)
        {
		    tail = tail->prev;
        }

		delete target;
		target = nullptr;
	}
 }

 template<typename T>
 inline size_t LinkedList<T>::size()
 {
	size_t count = 0;
	Node<T>* itr = head;

	while(itr != nullptr)
	{
		++count;
		itr = itr->next;
	}
	
	 return count;
 }

 template<typename T>
 inline void LinkedList<T>::print()
 {
	 std::cout << *this;
 }


template<typename T>
inline LinkedList<T>& LinkedList<T>::operator+=(const LinkedList<T>& other)
{
	Node<T>* itr = other.head;

	while (itr != nullptr)
	{
		push_back(itr->data);
		itr = itr->next;
	}

	return *this;
}
