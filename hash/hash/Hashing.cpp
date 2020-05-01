#include "Hashing.h"

#include <cstdio>
#include <string>
#include <fstream>
#include "Hashing.h"
#include <iostream>
//#include <bits/types/FILE.h>
#include <cstring>
#include <tuple>
#include <functional>

using namespace std;

Hashing::Hashing(int size, string filepath) {
	this->size = size;
	this->filepath = filepath;
	setup();
}

// Main Functions
Node Hashing::search(int key) {
	return get<1>(search_data(key, &Hashing::is_same_key));
}

double Hashing::time_spent() {
	int amount = 0;
	Node node = Node::empty_node();
	int items_count = 0;
	for (int i = 0; i < size; i++) {
		node = get_item(i);
		if (!node.is_empty) {
			items_count++;
			amount += time_spent(node.key);
		}
	}
	return amount / (double)items_count;
}


// Search type functions
bool Hashing::is_same_key(Node node, int key) {
	return !node.is_empty && node.key == key;
}

bool Hashing::empty_node(Node node, int key) {
	return node.is_empty;
}

bool Hashing::previous_node(Node node, int key) {
	return get_item(node.next).key == key;
}

// Advanced
void Hashing::delete_item(int position) {
	set_item(Node::empty_node(), position);
}

int Hashing::item_position(int key) {
	return get<0>(search_data(key, &Hashing::is_same_key));
}

int Hashing::time_spent(int key) {
	return get<2>(search_data(key, &Hashing::is_same_key));
}
// Receives key to be used to find positions, and criteria
// that will identify proper position, if exists

// Returns position, node at position and amount of iterations to find
tuple<int, Node, int> Hashing::search_data(
	int key,
	bool(Hashing::* criteria)(Node, int),
	int(Hashing::* position_calculator)(int, int, Node)) {

	int position = (this->*position_calculator)(-1, key, Node::empty_node());
	Node node = get_item(position);
	int counter = 1;
	while (!(this->*criteria)(node, key)) {
		position = (this->*position_calculator)(position, key, node);
		// Has searched entire file
		if (counter > this->size || position == -1) {
			return make_tuple(-1, Node::empty_node(), counter);
		}
		node = get_item(position);
		counter++;
	}
	return make_tuple(position, node, counter);
}

// Config
void Hashing::setup() {
	// Check if file exists
	if (!ifstream(filepath)) {
		fstream file(filepath, ios::binary | ios::app);
		if (file.is_open()) {
			// Fills file with empty nodes
			for (int i = 0; i < this->size; i++) {
				Node node = Node::empty_node();
				file.write((char*)&node, sizeof(Node));
			}
			file.close();
		}
	}
}

// File manipulation
Node Hashing::get_item(int position) {
	ifstream file(filepath, ios::binary);
	Node* searched = (Node*)malloc(sizeof(Node));
	if (file.is_open()) {
		file.seekg(sizeof(Node) * position, ios_base::beg);
		file.read((char*)searched, sizeof(Node));
		file.close();
	}
	return *searched;
}

void Hashing::set_item(Node node, int position) {
	fstream file(filepath, ios::binary | ios::in | ios::out);
	if (file.is_open()) {
		file.seekp(sizeof(Node) * position, ios_base::beg);
		file.write((char*)&node, sizeof(Node));
		file.close();
	}
}