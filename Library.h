#pragma once
//#define STL_library

#include <iostream>
#include <string>
#include<list>
#include<algorithm>
#include "CList.h"

class Library
{
private:
	class Book 
	{
	public:
		int udk_number; //����� ���
		std::string author; //������� � �������� ������
		int  year_publishing; //��� �������
		int number_copies; //���������� ����������� ������ ����� � ���������� 

		void input();
		void print_solo();
		void print_more();
		Book();
		~Book();
	};

public:
	void new_book();
	void take_book();
	void return_book();
	void print_list();

#ifdef STL_library
	std::list<Book> list_book;
#else
	CList<Book> list_book;
#endif
};
