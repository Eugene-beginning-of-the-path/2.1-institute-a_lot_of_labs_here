#include <iostream>
#include "CList.h"
#include "Library.h"

void logic_libary()
{
	Library library;
	int first_flag = true;
	bool second_flag = true;
	std::cout << "Enter information about book:\n" 
		<< "-----------------------------\n";
	while (first_flag)
	{
		library.new_book();
		std::cout << "-----------------------------\n";
		std::cout << "Enter 0 if you have finished writing information"
			<< "about the book: ";
		std::cin >> first_flag;
		std::cout << "-----------------------------\n";
	}
	while (second_flag)
	{
		char choise;
		std::cout << "Choise and enter:\n"
			<< "'1' - Take the book\n"
			<< "'2' - Return the book\n"
			<< "'3' - Show informatioin about books\n"
			<< "'4' - Press for exit\n"
			<< "--->";
		std::cin >> choise;

		switch (choise)
		{
		case '1':
			try 
			{
				library.take_book();
			}
			catch (const std::exception& exception)
			{
				std::cout << exception.what() << std::endl;
			}
			break;

		case '2':
			try 
			{
				library.return_book();
			}
			catch (std::exception& exception)
			{
				std::cout << exception.what() << std::endl;
			}
			break;

		case '3':
			library.print_list();
			break;

		case '4':
		{
			std::cout << "        *   **   \n"
				<< "      *   * **   \n"
				<< "    *       **   \n"
				<< "  *           *  \n"
				<< "* * * * * * * * *\n"
				<< "  *           *  \n"
				<< "  *   ***     *  \n"
				<< "  *   ***     *  \n"
				<< "  * * *** * * *  ";
			second_flag = false;
		}
			
		}
	}
}