#include <iostream>
#include "heap.h"

heap::heap(int * array, int size) {
	this->array = array;
	this->size = size;

	// Build the heap by starting from the last node that isn't a leaf
	for (int i = (this->size / 2) - 1; i >= 0; i--) {
       		this->heapify(i);
    	}
}

void heap::removeAndPrintLargest() {
	int largest = 123;

	std::cout << "Removed largest element: " << largest << std::endl;
}

void heap::removeAndPrintAll() {

}

void heap::print() {
	std::cout << "Your max heap:" << std::endl;
	for (int i = 0; i < this->size; i++) {
		std::cout << this->array[i] << std::endl;
	}
}

void heap::heapify(int index) {
	int temp = index;

	int left = this->getLeft(index);
	int right = this->getRight(index);

	if (left < this->size && this->array[left] > this->array[temp])
		temp = left;

	if (right < this->size && this->array[right] > this->array[temp])
		temp = right;

	if (temp != index) {
		std::swap(this->array[index], this->array[temp]);
		heapify(temp);
	}
}

int heap::getRoot() {
	return this->array[0];
}

int heap::getLeft(int index) {
	return index * 2 + 1;
}

int heap::getRight(int index) {
	return index * 2 + 2;
}

int heap::getParent(int index) {
	return (index - 1) / 2;
}


