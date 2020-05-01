
#include <fstream>
#include "Hashing.h"
#include "DoubleHashing.h"
#include "LinkedHashing.h"

using namespace std;

#define TAMANHO_ARQUIVO 11

#define DOUBLE_HASHING 'd'

#define INSERT 'i'
#define SEARCH 'c'
#define REMOVE 'r'
#define PRINT 'p'
#define TIME_SPENT 'm'
#define END 'e'

void operate(Hashing *hash) {
	Node node = Node::empty_node();
	int key;
	string name;
	int age;

	char operation;
	cin >> operation;
	while (operation != END) {
		switch (operation) {
		case INSERT:
			cin >> key;
			cin.ignore();
			getline(cin, name);
			cin >> age;
			if (!hash->insert(
				Node(key,
				(char*)name.c_str(),
					age))) {
				cout << "chave já existente: "
					<< key << endl;
			}
			break;
		case SEARCH:
			cin >> key;
			node = hash->search(key);
			if (node.is_empty) {
				cout << "chave não encontrada: "
					<< key << endl;
			}
			else {
				cout << "chave: " << key << endl;
				cout << node.name << endl;
				cout << node.age << endl;
			}
			break;
		case REMOVE:
			cin >> key;
			if (!hash->remove(key)) {
				cout << "chave não encontrada: "
					<< key << endl;
			}
			break;
		case TIME_SPENT:
			printf("%.1f", hash->time_spent());
			break;
		default: // Print
			hash->read();
			break;
		}
		cin >> operation;
	}
}

int main() {
	char type;
	cin >> type;
	if (type == DOUBLE_HASHING) {
		DoubleHashing hash = DoubleHashing(TAMANHO_ARQUIVO);
		operate(&hash);
	}
	else {
		LinkedHashing hash = LinkedHashing(TAMANHO_ARQUIVO);
		operate(&hash);
	}
	system("pause");
	return 0;
}