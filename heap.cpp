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

/*
 * Removes the root (largest) by replacing with the last element and calling the heapify function to adjust the structure.
 */
void heap::removeAndPrintLargest() {
	std::cout << "Removed element: " << this->array[0] << std::endl;

	this->array[0] = this->array[this->size - 1];
	this->size = this->size - 1;

	this->heapify(0);
}

/*
 * Removes all elements from the heap and prints them out.
 */
void heap::removeAndPrintAll() {
	while (this->size != 0) {
		this->removeAndPrintLargest();
	}
}

/*
 * Prints the heap sideways. Starts with the right wing of the root then does the left.
 */
void heap::print(int index, int spacing) {
	if (this->size == 0) {
		std::cout << "The heap is empty!" << std::endl;
	}
	else if (index > this-> size || this->array[index] == 0) {
		return;
	}
	else {
		this->print(this->getRight(index), spacing + 3);

		std::cout << std::endl;
		for (int i = 0; i < spacing; i++) {
			std::cout << " ";
		}
		std::cout << this->array[index] << std::endl;
		
		this->print(this->getLeft(index), spacing + 3);
	}
}

/*
 * Swaps and recurses to form correct max heap structure.
 */
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

/*
 * Returns the index of the left leaf of the node at the given index.
 */
int heap::getLeft(int index) {
	return index * 2 + 1;
}

/*
 * Returns the index of the right leaf of the node at the given index.
 */
int heap::getRight(int index) {
	return index * 2 + 2;
}

/*
 * Returns the index of the parent of the node at the given index.
 */
int heap::getParent(int index) {
	return (index - 1) / 2;
}
