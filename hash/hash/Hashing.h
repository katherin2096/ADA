#pragma once

#ifndef HASHING_HASHING_H
#define HASHING_HASHING_H

#include <iostream>
#include "Node.h"

using namespace std;

class Hashing {
public:
	explicit Hashing(int size,
		string filepath);

	virtual bool insert(Node node) {};
	virtual bool remove(int key) {};
	virtual void read() {};
	Node search(int key);
	double time_spent();
	int time_spent(int key);
	bool previous_node(Node node, int key);
	bool empty_node(Node node, int key);
	int size;
	virtual int search_calculator(int current,
		int key,
		Node node) = 0;
	bool is_same_key(Node node, int key);
	Node get_item(int position);
	void set_item(Node node, int position);
	void delete_item(int position);
	int item_position(int key);
	tuple<int, Node, int> search_data(
		int key,
		bool (Hashing::*criteria)(Node, int) = &Hashing::is_same_key,
		int (Hashing::*position_calculator)(int, int, Node) = &Hashing::search_calculator);

private:
	void setup();
	string filepath;

};
#endif //HASHING_HASHING_H

