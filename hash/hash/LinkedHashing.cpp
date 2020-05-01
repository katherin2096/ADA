#include <tuple>
#include "LinkedHashing.h"

using namespace std;

void LinkedHashing::read() {
	for (int i = 0; i < this->size; i++) {
		cout << i << ": ";
		Node node = this->get_item(i);
		if (node.is_empty) {
			cout << Node::empty << endl;
		}
		else {
			//cout << node.hashingFormat() << " ";
			if (node.next == -1) {
				cout << "nulo";
			}
			else {
				cout << node.next;
			}
			cout << endl;
		}
	}
}

bool LinkedHashing::remove(int key) {
	int nodeClass = key % size;
	tuple<int, Node, int> search = search_data(key);
	int position = get<0>(search);
	if (position < 0) {
		return false;
	}
	Node node = get<1>(search);
	// First element
	if (nodeClass == position) {
		if (node.next != -1) {
			// Moves the next node
			Node realocted = get_item(node.next);
			set_item(realocted, nodeClass);
			delete_item(node.next);
		}
	}
	else {
		// Previous element points now to the
		// same value that the current element
		// used to point
		tuple<int, Node, int> search_previous =
			search_data(key,
				&Hashing::previous_node);
		int previous_position = get<0>(search_previous);
		Node previous = get<1>(search_previous);
		previous.next = node.next;
		set_item(previous, previous_position);
		delete_item(position);
	}
	return true;
}

int LinkedHashing::get_last_empty_position(int lastPosition) {
	while (!get_item(lastPosition).is_empty) {
		lastPosition--;
		if (lastPosition < 0) {
			// Not valid insertion
			return -1;
		}
	}
	return lastPosition;
}

bool LinkedHashing::insert(Node node) {
	int position = node.key % size;
	Node searched = get_item(position);

	if (searched.is_empty) {
		set_item(node, position);
		return true;
	}

	// Node at position is not of the same class
	// and needs to be moved
	if (searched.key % size != node.key % size) {
		tuple<int, Node, int> search_previous =
			search_data(searched.key,
				&Hashing::previous_node);
		int previous_position = get<0>(search_previous);
		Node previous = get<1>(search_previous);

		int searched_new_position =
			get_last_empty_position(size - 1);
		previous.next = searched_new_position;
		// Updates previous item that points to searched
		set_item(previous, previous_position);
		// Moves searched
		set_item(searched, searched_new_position);
		// Inserts
		set_item(node, position);
		return true;
	}

	if (searched.key == node.key) {
		return false;
	}
	while (searched.next != -1) {
		position = searched.next;
		searched = get_item(position);
		if (searched.key == node.key) {
			return false;
		}
	}
	int last_position = get_last_empty_position(size - 1);
	searched.next = last_position;
	// Updates previous node
	set_item(searched, position);
	// Inserts
	set_item(node, last_position);
	return true;
}

int LinkedHashing::search_calculator(int current, int key, Node node) {
	if (current == -1) {
		return key % size;
	}
	return node.next;
}
