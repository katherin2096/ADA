#pragma once
#ifndef HASHING_LINKEDHASHING_H
#define HASHING_LINKEDHASHING_H

#include "Hashing.h"
#include <iostream>

#define LINKED_HASHING_FILE "linkedHashingFile.bin"

using namespace std;

class LinkedHashing : public Hashing {
public:

	explicit LinkedHashing(int size) : Hashing(size, LINKED_HASHING_FILE) {}
	bool remove(int key) override;
	void read() override;
	bool insert(Node node) override;

private:
	int search_calculator(int current, int key, Node node) override;

	int get_last_empty_position(int lastPosition);
};

#endif //HASHING_LINKEDHASHING_H
