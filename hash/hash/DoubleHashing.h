#pragma once

#ifndef HASHING_DOUBLEHASHING_H
#define HASHING_DOUBLEHASHING_H


#include "Hashing.h"

const string DOUBLE_HASHING_FILE = "doubleHashingFile.bin";

class DoubleHashing : public Hashing {
public:
	explicit DoubleHashing(int size) : Hashing(size,
		DOUBLE_HASHING_FILE) {}
	void read() override;
	bool remove(int key) override;
	bool insert(Node node) override;

private:
	int h1(int key);
	int h2(int key);
	int search_calculator(int current, int key, Node node) override;

};

#endif //HASHING_DOUBLEHASHING_H

