#define _CRT_SECURE_NO_WARNINGS
#include "header.h"


void checkInputFIle(std::ifstream& fin) {

	if (!fin.good()) {
		throw "file doesnt exist";//существование файла
	}
	if (!fin) {
		throw "input file error";//на открытие файла
	}
	if (fin.peek() == EOF) {
		throw "this file is empty";//пустота
	}
}

void CheckOutputFile(std::ofstream& fout) {
	if (!fout) {
		throw "output file error";
	}
}

int32_t CountLinesFromFile(std::ifstream& fin) {
	int32_t counter{};
	std::string line;
	while (std::getline(fin, line)) {
		++counter;
	}

	fin.clear();
	fin.seekg(0);
	return counter;
}

void FillStudentsFromFile(std::ifstream& fin, Student*& students, int32_t size) {

	char line[200];
	int32_t i = 0;
	while (fin.getline(line, sizeof(line)) && i < size) {
		char* name = strtok(line, ";");
		char* group = strtok(nullptr, ";");
		char* grade = strtok(nullptr, ";");

		strncpy(students[i].name, name, sizeof(students[i].name));
		students[i].group = std::atoi(group);
		students[i].grade = std::atof(grade);
		++i;
	}
}

void SortArrayBySurname(Student*& students, int32_t size) {
	for (int32_t i = 0; i < size - 1; ++i) {
		for (int32_t j = i + 1; j < size; ++j) {
			if (strcmp(students[i].name, students[j].name) > 0) {
				std::swap(students[i], students[j]);
			}	
		}
	}
}

void FillSortArrayInFile(std::ofstream& fout, Student*& students, int32_t size) {
	fout.open("in.txt", std::ios::trunc);
	for (size_t i = 0; i < size; ++i)
	{
		fout << students[i].name << ";";
		fout << students[i].group << ";";
		fout << students[i].grade;
		fout << "\n";
	}

}





