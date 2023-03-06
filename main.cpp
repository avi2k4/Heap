#include <iostream>
#include <cstring>
#include <fstream>
#include "heap.h"

int main() {
	std::cout << "\nHow would you like to enter your numbers?" << std::endl;
	std::cout << "[-] 1 for console\n[-] 2 for text file" << std::endl;

	int input;
	std::cin >> input;

	int length = 0;
	int * numbers = new int[100];

	if (input == 1) { // Console
		std::cout << "\nYou can enter up to 100 numbers in between 1-1000. If you want to end early, type -123." << std::endl;
		
		int number_input = 0;	
		while (length < 100) {
			std::cin >> number_input;

			if (number_input == -123) {
				std::cout << "gear" << std::endl;
				break;
			}
			
			numbers[length] = number_input;
			length++;
		}
	}
	else if (input == 2) { // Text file
		char file_name[50];
		std::cout << "\nEnter the file name!" << std::endl;
		std::cin >> file_name;

		std::ifstream file;
		file.open(file_name);

		if (file.is_open()) {
			while (length < 100 && file >> numbers[length]) {
				length++;
			}
		}

		file.close();
	}

	heap * max_heap = new heap(numbers, length);

	std::cout << "\nUse any of the following commands:" << std::endl;
	std::cout << "[-] 1 to remove the largest element\n[-] 2 to remove all elements\n[-] 3 to print the heap\n[-] 4 to quit" << std::endl;

	int input2;

	while (true) {
		std::cin >> input2;

		if (input2 == 1) { // Remove largest element
			max_heap->removeAndPrintLargest();
		}
		else if (input2 == 2) { // Remove all elements
			max_heap->removeAndPrintAll();	
		}
		else if (input2 == 3) { // Print the heap
			max_heap->print();
		}
		else {
			break;
		}
	}

	return 0;
}
