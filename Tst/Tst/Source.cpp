#include <iostream>
#include <string>
using namespace std;


class nodo {
public:
	int value;
	nodo *izquierda, *medio, *derecha;
	char data;
	nodo(char _data) {
		data = _data;
		izquierda = NULL;
		medio = NULL;
		derecha = NULL;
		value = -1;

	}
	~nodo() {

	}
};

class tst {
private:
	nodo* raiz;
public:
	tst() {
		raiz = NULL;
	}
	~tst() {
		delete raiz;
	}

nodo *insertion(nodo *node, const string &str, int index, int value) {
		if (!node) {
			node = new nodo(str[index]);
		}

		if (node->data > str[index])
		{
			node->izquierda = insertion(node->izquierda, str, index, value);
		}
		else if (node->data < str[index])
		{
			node->derecha = insertion(node->derecha, str, index, value);
		}
		else if (index < str.size() - 1) 
		{
			node->medio = insertion(node->medio, str, index + 1, value);
		}
		else
			node->value = value;

		return node;
	}
	
void insert(string word, int value) 
{
		raiz = insertion(raiz, word, 0, value);
}

void print()
{
	char word[10];
	imprimir(raiz, word, 0);
}
void imprimir(nodo* root, char* palabra, int piso)
{
		if (root)
		{
			imprimir(root->izquierda, palabra, piso);
			palabra[piso] = root->data;
			if (root->value >= 0)
			{
				palabra[piso + 1] = '\0';
				cout << palabra << endl;
			}
			imprimir(root->medio, palabra, piso + 1);
			imprimir(root->derecha, palabra, piso);
		}
}



int cont = 0;
string t;
void maxPrefijo(nodo* root)
{
	string temi="";
	
	//nodo* temp= root->izquierda;
	if (root)
	{
	//	nodo* tmp = root;
		
		while (root->medio)
		{
			temi = temi + root->data;
			if (root->derecha)
			{
				maxPrefijo(root->derecha);
			}
			if (root->izquierda)
			{
				maxPrefijo(root->izquierda);
			}
			root = root->medio;
			if (root->value != -1 && root->medio)
			{
				temi = temi + root->data;
				t = temi;
				if (t.size() > cont)
				{
					cont = t.size();
				}
			}
			
		}
	//	root = tmp;

		
	}

	
}
void prefijoMax()
{
	maxPrefijo(raiz);
	cout << "palabra --->" << t << "  tamanio --->" << cont;
}

void buscar(string pali)
{
	findprefix( pali, raiz );
}

void findprefix(string pal, nodo* root)
{
	char ini = pal[0];
	char fin = pal[pal.size() - 1];
	string temi = "";
	if (root)
	{
		while (root->medio && root->data == ini)
		{
			temi = temi + root->data;
			root = root->medio;
			if (root->data == fin && root->medio)
			{
				temi = temi + root->data;

			}
			nodo* tmp = root;
			while (root->medio)
			{
				temi = temi + root->data;
				root = root->medio;
			}
			cout << temi << endl;
			root = tmp;
			while (root->izquierda)
			{
				temi = temi + root->data;
			}
			cout << temi << endl;
			root = tmp;
			while (root->derecha)
			{
				temi = temi + root->data;
			}

		}
	}
}
};

int main() 
{
	tst w;
	string str[] = { "abra","abrazo","abrir","abrelatas","abs","abierto","arsenico","arisco","alibaba","the" };
	//string str[] = { "by","are","sea","sells","shells","she","shore","surely","sur","the" };
	for (int i = 0; i < 10; ++i)
	{
		w.insert(str[i], i);
	}
	w.print();
	cout << endl;
	w.prefijoMax();
	//w.buscar("abra");
	system("pause");
	return 1;
}