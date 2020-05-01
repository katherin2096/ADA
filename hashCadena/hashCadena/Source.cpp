#include<iostream> 
#include <list> 
#include <stdlib.h>

using namespace std;

class Hash
{
	int casilleros;
	list<int> *tabla;
public:
	Hash(int V);
	void insertarItem(int x);

	void eliminarItem(int key);
	void insertarRan(int n,int m)
	{
		for (int i = 0; i < n; i++)
		{
			int rx = (rand() % m);
			insertarItem(rx);
		}
		
	}


	int funcionHash(int x) {
		return (x % casilleros);
	}

	int expo_modular(int num, int pot, int n)
	{
		int a = num;
		int b = 1;
		while (pot > 0) {
			if ((pot % 2) == 1)
				b = (b * a) % n;
			a = (a * a) % n;
			pot /= 2;
		}
		return b;
	}

	void mostrarHash();
};

Hash::Hash(int b)
{
	this->casilleros = b;
	tabla = new list<int>[casilleros];
}

void Hash::insertarItem(int key)
{
	int index = expo_modular(key, 2, 13);// funcionHash(key);
	tabla[index].push_back(key);
}

void Hash::eliminarItem(int key)
{
	// hallamos la clave
	int index = funcionHash(key);

	// buscamos la clave
	list <int> ::iterator i;
	for (i = tabla[index].begin();
		i != tabla[index].end(); i++) {
		if (*i == key)
			break;
	}


	if (i != tabla[index].end())
		tabla[index].erase(i);
}

void Hash::mostrarHash() {
	for (int i = 0; i < casilleros; i++) {
		cout << i;
		for (auto x : tabla[i])
			cout << " --> " << x;
		cout << endl;
	}

}




int main()
{
	/*int a[] = { 1,5,23,45,15, 11, 27, 8, 12 };
	int n = sizeof(a) / sizeof(a[0]);// determinamos el tamaño del array dividiendo cuanta memoria tiene / cuanto necesita cada tipo de dato
	Hash h(13);
	for (int i = 0; i < n; i++)
		h.insertarItem(a[i]);
		*/
	Hash h(13);
	h.insertarRan(20,13);

	h.mostrarHash();
	//h.eliminarItem(12);
//	h.mostrarHash();
	system("pause");
	return 0;

}