#pragma once

#include <iostream>

template<typename T>
class CList
{
private:
	template<typename T>
	class Element
	{
	public:
		Element* ptr_next;
		T data;

		Element(T data = T(), Element* ptr_next = nullptr)
		{
			this->data = data;
			this->ptr_next = ptr_next;
		}

		~Element() { }
	};

	int Size;
	Element<T>* first;

public:
	CList();
	int GetSize() { return Size; }
	void push_back(T data);
	void pop_front();//
	void clear();//
	void push_front(T data);//
	void pop_back();//
	T& operator[](int index);
};

template<typename T>
inline CList<T>::CList()
{
	Size = 0;
	first = nullptr;
}

template<typename T>
void CList<T>::push_back(T data)//Добавляем эл. в конец списка
{
	if (first == nullptr)
	{
		first = new Element<T>(data);
	}
	else
	{
		Element<T>* current = first;
		while (current->ptr_next != nullptr)
		{
			current = current->ptr_next;
		}
		current->ptr_next = new Element<T>(data);
	}
	Size++;
}

/*template<typename T>
void CList<T>::push_back(T data)
{
	if (first == nullptr)
		first = new Element<T>(data);
	else
	{
		Element<T>* current = this->first;

		while (current->ptr_next != nullptr)
		{
			current = current->ptr_next;
		}
		current->ptr_next = new Element<T>(data);
	}

	Size++;
}*/

template<typename T>
inline void CList<T>::pop_front()
{
	Element<T>* temp = first;
	first = first->ptr_next;
	delete temp;
	Size--;
}

template<typename T>
inline void CList<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
inline void CList<T>::push_front(T data)
{
	first = new Element<T>(data, first);
	Size++;

	//Element<T>* current = first;
	//first = new Element<T>(data, current);
	//Size++;
}

template<typename T>
inline void CList<T>::pop_back()
{
	Element<T>* current = first;
	for (int i = 0; i < Size - 2; i++)//Доходим до указания на предпоследний контейнер
	{
		current = current->ptr_next;
	}
	Element<T>* temp = current->ptr_next;//И через его переменную на указ. след. контейнера-удаляем последний контейнер
	delete temp;
	Size--;
}

template<typename T>
inline T& CList<T>::operator[](const int index)
{
	int counter = 0;
	Element<T>* current = first;
	while (true)
	{
		if (counter == index)
		{
			return current->data;
		}
		counter++;
		current = current->ptr_next;
	}
}
