#include <iostream>
#include <cstring>
#include <fstream>
#include "heap.h"

int main() {
	int input;

	std::cout << "\nHow would you like to enter your numbers?" << std::endl;
	std::cout << "[-] 1 for console\n[-] 2 for text file" << std::endl;

	std::cin >> input;

	int * numbers = new int[100];

	if (input == 1) { // Console

	}
	else if (input == 2) { // Text file
		char file_name[50];
		std::cout << "\nEnter the file name!" << std::endl;
		std::cin >> file_name;

		std::ifstream file;
		file.open(file_name);

		if (file.is_open()) {
			
		}

		file.close();
	}

	heap * max_heap = new heap(numbers);

	std::cout << "\nUse any of the following commands:" << std::endl;
	std::cout << "[-] 1 to remove the largest element\n[-] 2 to remove all elements[-] 3 to print the heap" << std::endl;


	return 0;
}
