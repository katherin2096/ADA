#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

#define tabla_Tamanio 13 
#define primo 11

class DoubleHash
{
	
	int *hashTable;
	int curr_size;

public:
	bool isFull()
	{
		return (curr_size == tabla_Tamanio);// si el tamaño ya esta a tope 
	}

	int hash1(int key)
	{
		return (key % tabla_Tamanio);
	}

	int hash2(int key)
	{
		return (primo - (key % primo));
	}

	DoubleHash()
	{
		hashTable = new int[tabla_Tamanio];
		curr_size = 0;
		for (int i = 0; i<tabla_Tamanio; i++)
			hashTable[i] = -1;
	}

	//funcion de exponenciacion modular alternativa para las funciones
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

	bool search(int key)
	{
		hash1(key);
		if (hashTable[hash1(key)] == key)
		{
			cout << "encontrado pos --->" << hash1(key) << endl;
			return 1;
		}
		else if (hashTable[hash2(key)] == key)
		{
			hash2(key);
			cout << hashTable[hash2(key)] << endl;
			cout << "encontrado"<< hash2(key) << endl;
			return 1;
		}
		else
			cout << "no hay" << endl;
		return 0;
	}

	void insertarHash(int key)
	{
		// si la hash esta llena
		if (isFull())
			return;

		int index = hash1(key);

		// si se chocan elementos
		if (hashTable[index] != -1)
		{
			int index2 = hash2(key);
			int i = 1;
			while (1)
			{
				int newIndex = (index + i * index2) %
					tabla_Tamanio;
				if (hashTable[newIndex] == -1)
				{
					hashTable[newIndex] = key;
					break;
				}
				i++;
			}
		}

		// si nadie se choca
		else
			hashTable[index] = key;
		curr_size++;
	}

	void buscarHash(int key)
	{
		int index = hash1(key);
		if (hashTable[index] != -1)
		{
			int index2 = hash2(key);
		}

	}

	void mostrarHash()
	{
		for (int i = 0; i < tabla_Tamanio; i++)
		{
			if (hashTable[i] != -1)
				cout << i << " --> "
				<< hashTable[i] << endl;
			else
				cout << i << endl;
		}
	}
};

int main()
{
	int a[] = { 7,19, 27, 36, 10, 64,45,11,20,12,14 };
	int n = sizeof(a) / sizeof(a[0]);

	DoubleHash h;
	for (int i = 0; i < n; i++)
		h.insertarHash(a[i]);

	h.search(45);
	h.mostrarHash();
	system("pause");
	return 0;
}

