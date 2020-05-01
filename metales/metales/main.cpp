#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>

using namespace std;


struct metal
{
	int id;
	int stock;
	int precio;
};
vector<metal> metales;
pair<int, int> calcular(float monto, metal a)
{
	pair<float, int> dual;
	int res = 0;
	float r = monto / a.precio;
	if (a.stock < r)
	{
		int com=a.precio*a.stock;
		res = monto - com;
		dual.first = a.stock;
		dual.second = res;
		a.stock = 0;	
		cout << dual.first << " kg usados del metal ---> " << a.id << " monto faltante " << dual.second << endl;
		return dual;
	}

	else
	{
		int com = a.precio*r;
		dual.first = r;
		dual.second = 0;
		a.stock = a.stock - r;
		cout << dual.first << " kg usados del metal --->" << a.id <<endl;
		return dual;
	}
}

void tratar(float monto)
{
	int mon=monto;
	int cont=0;
	while (mon !=0 && cont<metales.size())
	{
		//calcular(mon, metales[cont]);
		mon = calcular(mon, metales[cont]).second;
		cont++;
	}

}

void quickSort(int low, int high)
{
	//int low=0;
	//int high=vec.size()-1;
	int i = low;
	int j = high;
	int pivot = metales[(i + j) / 2].precio;
	metal temp;

	while (i <= j)
	{
		while (metales[i].precio < pivot)
			i++;
		while (metales[j].precio > pivot)
			j--;
		if (i <= j)
		{
			temp = metales[i];
			metales[i] = metales[j];
			metales[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		quickSort(low, j);
	if (i < high)
		quickSort(i, high);


}

int main()
{
	metal oro;
	oro.id=1;
	oro.precio = 20;
	oro.stock = 15;
	metal plata;
	plata.id = 2;
	plata.precio = 10;
	plata.stock = 20;
	metal bronce;
	bronce.id = 3;
	bronce.precio = 8;
	bronce.stock = 30;
	metal estalactita;
	estalactita.id = 4;
	estalactita.precio = 28;
	estalactita.stock = 5;

	metales.push_back(oro);
	metales.push_back(plata);
	metales.push_back(bronce);
	metales.push_back(estalactita);

	tratar(583);

	quickSort(0,3);
	vector<metal> tempo;
	for (int i = metales.size() - 1; i >= 0; i--)
	{
		tempo.push_back(metales[i]);
	}
	metales = tempo;
	tratar(583);
//	cout<<89 % 28;
	system("pause");
	return 1;
}