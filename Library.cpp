#include "Library.h"
#include <exception>

Library::Book::Book()
{
	udk_number = year_publishing = number_copies = 0;
	author = "";
}

Library::Book::~Book()
{
}

void Library::Book::input()
{
	std::cout << "Enter UDK number: ";
	std::cin >> udk_number;

	std::cout << "Enter author: ";
	std::cin >> author;

	std::cout << "Enter year publishing: ";
	std::cin >> year_publishing;

	std::cout << "Enter number copies: ";
	std::cin >> number_copies;
}

void Library::Book::print_solo()
{
	std::cout << "-----Information about the Book [UDK#" << udk_number << "]-----" << std::endl;
	std::cout << "Author of the book: " << author << std::endl;
	std::cout << "Year publishig of the book: " << year_publishing << std::endl;
	std::cout << "Number copies of the book: " << number_copies << std::endl;
	std::cout << "----------------------------------------------\n\n";
}

void Library::Book::print_more()
{
	std::cout << "-----Information about the Book [UDK#" << udk_number << "]-----" << std::endl;
	std::cout << "Author of the book: " << author << std::endl;
	std::cout << "Year publishig of the book: " << year_publishing << std::endl;
	std::cout << "Number copies of the book: " << number_copies << std::endl;

}

void Library::new_book()
{
#ifdef STL_library
	Book new_book;//��������� ������ ������ �����
	new_book.input(); //������������ ������ ��������, �������� �����

	auto check = std::find_if(begin(list_book), end(list_book), [&new_book](const auto& el)
		{
			return el.udk_number == new_book.udk_number;
		});

	if (check == list_book.end()) //���� �� ����� �� ����������� � ������, �� ��������� �� � ����� ������ 
		list_book.push_back(new_book);
	else
		throw std::exception("\nThis UDK it repited\n\n ");
#else
	Book new_book;
	new_book.input();
	link:
	for (int i = 0; i < list_book.GetSize(); i++)
	{
		if (new_book.udk_number == list_book[i].udk_number)
		{
			std::cout << "this UDK it repited\n";
			std::cout << "Enter UDK number again: ";
			std::cin >> new_book.udk_number;
			goto link;
		}
	}
	list_book.push_back(new_book);
#endif
}

void Library::take_book()
{
#ifdef STL_library
	int take_UDK;
	std::cout << "Enter book's UDK: ";
	std::cin >> take_UDK;

	auto check = std::find_if(begin(list_book), end(list_book), [take_UDK](const auto& el)
		{
			return el.udk_number == take_UDK;
		});

	if (check == list_book.end())//� ������ ���������� ������ ����� �� ���, ��������� ������ � ���, ��� �����
		throw std::exception("UDK of book did not find\n\n ");//����� ��� � ������ library
	else//���� �� ����� � ��������� ��� ������� � library
	{
		if (check->number_copies >= 1)//���������, ���� � �� � ������� ���� �� 1��.
		{
			check->number_copies--;//���� ����, �� ���������, ��� ����� ����� �� ���� ������ 
			std::cout << "The book was successfully taken\n\n";
		}
		else//���� ����� ��� (�� == 0), �� ������� ������, ��� ������ ����� ��� � �������
			throw std::exception("Number of copies of the book = 0\n\n");
	}
#else
	int take_UDK;
	bool found = false;
	std::cout << "Enter book's UDK: ";
	std::cin >> take_UDK;
	for (int i = 0; i < list_book.GetSize(); i++)
	{
		if (take_UDK == list_book[i].udk_number)
		{
			found = true;
			if (list_book[i].number_copies > 0)
			{
				list_book[i].number_copies--;
				std::cout << "The book was successfully taken\n\n";
			}
			else
			{
				throw std::exception("Number of copies of the book = 0\n\n");
				break;
			}
		}
	}
	if(!found)
		throw std::exception("UDK of book did not find\n\n");
#endif
}

void Library::return_book()
{
#ifdef STL_library
	int return_UDK;
	std::cout << "Enter book's UDK: ";
	std::cin >> return_UDK;

	auto it = std::find_if(begin(list_book), end(list_book), [return_UDK](const auto& el)
		{
			std::cout << "The book was successfully returned\n\n";
			return el.udk_number == return_UDK;
		});


	if (it == list_book.end())//� ������ ������������� ����� ��� ������������ �����
		throw std::exception("UDK of book did not find\n\n");//��������� ������
	else
		it->number_copies++;//�����, ����� ����� ������������� � ������ library �� +1
#else
	int return_UDK;
	bool found = false;
	std::cout << "Enter book's UDK: ";
	std::cin >> return_UDK;
	for (int i = 0; i < list_book.GetSize(); i++)
	{
		if (return_UDK == list_book[i].udk_number)
		{
			found = true;
			list_book[i].number_copies++;
			std::cout << "The book was successfully returned\n\n";
			break;
		}
	}
	if (!found)
		throw std::exception("UDK of book did not find\n\n");
#endif
}

void Library::print_list()
{
#ifdef STL_library
		for_each(begin(list_book), end(list_book), [](auto& el) //#include <algoritm>
		{
			el.print_more();
		});
		std::cout << "----------------------------------------------\n\n";
#else
	if (list_book.GetSize() > 0)
	{
		for (int i = 0; i < list_book.GetSize(); i++)
		{
			list_book[i].print_more();
		}
		std::cout << "----------------------------------------------\n\n";
	}
	else
		list_book[0].print_solo();
#endif
}
