
#include <iostream>
#include <tuple>
#include "DoubleHashing.h"

using namespace std;

bool DoubleHashing::insert(Node node) {
	// Verifies if key already exists
	if (!search(node.key).is_empty) {
		return false;
	}
	// Looks for appropriate position
	int position = get<0>(search_data(node.key,
		&Hashing::empty_node,
		&Hashing::search_calculator));
	if (position != -1) {
		set_item(node, position);
		return true;
	}
	return false;
}

void DoubleHashing::read() {
	for (int i = 0; i < this->size; i++) {
		cout << i << ": ";
		Node node = this->get_item(i);
		if (node.is_empty) {
			cout << Node::empty << endl;
		}
		else {
			cout <<node.hashingFormat() << endl;
		}
	}
}

bool DoubleHashing::remove(int key) {
	int position = item_position(key);
	if (position == -1) return false;
	delete_item(position);
	return true;
}

int DoubleHashing::search_calculator(int current, int key, Node node) {
	if (current == -1) {
		return h1(key);
	}
	else {
		if (node.key == key) {
			return -1;
		}
		return (current + h2(key)) % size;
	}
}

int DoubleHashing::h1(int key) {
	return key % size;
}

int DoubleHashing::h2(int key) {
	int answer = (key / size) % size;
	if (answer == 0) {
		return 1;
	}
	return answer;
}
