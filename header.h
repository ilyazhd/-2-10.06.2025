#define _CRT_SECURE_NO_WARNINGS
#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>


struct Student {
	char name[30];
	int group;
	double grade;
};


void checkInputFIle(std::ifstream& fin);
void CheckOutputFile(std::ofstream& fout);

int32_t CountLinesFromFile(std::ifstream& fin);
void FillStudentsFromFile(std::ifstream& fin, Student*& students, int32_t size);
void SortArrayBySurname(Student*& students, int32_t size);
void FillSortArrayInFile(std::ofstream& fout, Student*& students, int32_t size);





#endif _HEADER_H_