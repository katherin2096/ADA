#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>

using namespace std;
struct Proceso 
{
	int id;
	int time;
};
vector<Proceso> vec;

void CrearProcesos(int n,int timax)
{
	for (int i = 1; i <= n; i++)
	{
		Proceso a;
		a.id = i;
		srand(time(0));
		int num = 1 + rand() % ((timax+1) - 1);
		a.time = num;
		vec.push_back(a);
	}
}

float tiempoDeRespuesta(vector<Proceso> vector)
{
	float tr=0;
	int tam = vector.size();
	int pos = 0;
	for (int i = tam; i > 0; i--)
	{
		int cal = vector[pos].time*i;
		tr = tr + cal;
		pos++;
	}
	tr = tr / tam;
	cout << "Tiempo de retorno = "<<tr<<endl;
	return tam;
}

void quickSort(int low ,int high)
{
	//int low=0;
	//int high=vec.size()-1;
	int i = low;
	int j = high;
	int pivot = vec[(i + j) / 2].time;
	Proceso temp;

	while (i <= j)
	{
		while (vec[i].time < pivot)
			i++;
		while (vec[j].time > pivot)
			j--;
		if (i <= j)
		{
			temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		quickSort( low, j);
	if (i < high)
		quickSort( i, high);
}

void print(vector<Proceso> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << "Proceso " << v[i].id << " Con tiempo " << v[i].time << endl;
	}
}
int main()
{
	CrearProcesos(8, 15);
	print(vec);
	tiempoDeRespuesta(vec);
	quickSort( 0, 7);
//	std::sort(vec.begin(), vec.end());
	print(vec);
	tiempoDeRespuesta(vec);
	/*
	Proceso p;
	p.time = 1;
	Proceso pa;
	pa.time = 2;
	Proceso pb;
	pb.time = 4;
	Proceso pc;
	pc.time = 4;
	Proceso pd;
	pd.time = 7;
	Proceso pe;
	pe.time = 8;
	Proceso pf;
	pf.time = 8;
	vector<Proceso> p1;
	p1.push_back(p);
	p1.push_back(pa);
	p1.push_back(pb);
	p1.push_back(pc);
	p1.push_back(pd);
	p1.push_back(pe);
	p1.push_back(pf);
	tiempoDeRespuesta(p1);*/
	system("pause");
	return 1;
}
