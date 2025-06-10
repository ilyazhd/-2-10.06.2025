#define _CRT_SECURE_NO_WARNINGS
#include "header.h"


int main() {
	std::ifstream fin("in.txt");
	std::ofstream fout;
    Student* students = nullptr;
	try
	{
		checkInputFIle(fin);
		int32_t amountOfLines{CountLinesFromFile(fin)};
        students = new Student[amountOfLines];

        FillStudentsFromFile(fin, students, amountOfLines);

		
		int32_t choise{-1};

		while (choise != 0) {
			std::cout << "choise what you want to do: \n";
			std::cout << "[1] - sort array by surname\n";
			std::cout << "[2] - find in array notes about student\n";
			std::cout << "[3] - sort array by droup and in group by surname\n";
			std::cout << "[4] - output grade about group\n";
			std::cout << "[0] - out\n";
			std::cin >> choise;


			switch (choise)
			{
			case 1:
				SortArrayBySurname(students, amountOfLines);
				FillSortArrayInFile(fout, students, amountOfLines);
				break;
			case 0:

				break;
			default:
				break;
			}
		}
	}
	catch (const char * m)
	{
		std::cout << m;
	}
	



	fin.close();
	return 0;
}
