#include <iostream>
#include <cstring>
#pragma once

class heap {
	public:
		heap(int * array, int size);

		void removeAndPrintLargest();
		void removeAndPrintAll();
		void print();
		
	private:
		int * array;
		int size;

		void heapify(int index);
		int getLeft(int index);
		int getRight(int index);
		int getParent(int index);
};
