#pragma once
#ifndef HASHING_NODE_H
#define HASHING_NODE_H

#include <iostream>

using namespace std;

class Node {
public:
	static const char* empty;
	int key;
	char name[20];
	int age;
	int next = -1;
	bool is_empty = false;
	Node(int key, char* name, int age);
	string hashingFormat();
	static Node empty_node();
};


#endif //HASHING_NODE_H
