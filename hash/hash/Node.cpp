#include <cstring>
#include <string>
#include "Node.h"
const char* Node::empty = "vacio";
Node::Node(int key, char name[], int age) {
	this->key = key;
	for (int i = 0; i < 20; i++) {
		this->name[i] = name[i];
	}
	this->age = age;
}

string to_string2(char* arr) {
	string str = "";
	for (int i = 0; i < 20; i++) {
		if (arr[i] == '\0') {
			break;
		}
		str += arr[i];
	}
	return str;
}

string Node::hashingFormat() {
	return to_string(this->key) + " " +
		to_string2(this->name) + " " +
		to_string(this->age);
}

Node Node::empty_node() {
	char name[20];
	strcpy(name, Node::empty);
	Node empty = Node(-1, name, -1);
	empty.is_empty = true;
	return empty;
}
