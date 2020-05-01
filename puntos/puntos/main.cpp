#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include<fstream>
using namespace std;


struct point {
	pair<int,int> coordenada;
	int rango=0;
	vector<pair<int, int>> puntos;
};

int tam = 18;
vector<pair<int, int>> par;
vector<point> puntosx;

void hallarRango(point a)
{
	pair<int, int> rango;
	rango.first = a.coordenada.first, rango.second = a.coordenada.second;
	for (int i = 0; i < puntosx.size() ; i++)
	{
		if ((puntosx[i].coordenada.first < a.coordenada.first) && (puntosx[i].coordenada.second < a.coordenada.second))
		{
			a.puntos.push_back(std::make_pair(puntosx[i].coordenada.first, puntosx[i].coordenada.second));
			a.rango = +1;
		}
	}
}

void rangoTotal()
{
	for (int i = 0; i < puntosx.size(); i++)
	{
		hallarRango(puntosx[i]);
	}
}

int main() {
	int n = 20;
	for (int i = 0; i < n; i++)
	{
		int rx = (rand() % n) + 3;
		int ry = (rand() % n) + 5;
		point temp;
		temp.coordenada.first = rx;
		temp.coordenada.second = ry;
		puntosx.push_back(temp);

		/*
		vector<point> puntosx;



		vector<pair<int, int>> par;
		int n;
		n = 50;

		string fichero("lista.txt");
		ofstream f_lista(fichero.c_str());
		if (!f_lista) {
			cout << "El fichero  no existe.";
			exit(0);
		}
	//	f_lista << "Lo que quieras meter aqui";

		for (int i = 0; i < n; i++)
		{
			int rx = (rand() % n) + 3;
			int ry = (rand() % n) + 5;
			par.push_back(std::make_pair(rx,ry));
			//cout << par[i].first<<" "<<par[i].second<<endl;
			f_lista << par[i].first << " " << par[i].second << endl;
		}



		for(int i=0 ;i<n ;i++)
		{
		pair<int,int> rango;
		rango.first=par[i].first , rango.second=par[i].second;
		vector<pair<int, int>> bran;
		string var = "0";

		string fichero1("listaRango.txt");
		var = var + fichero1;
		ofstream f_lista1(var.c_str());
		if (!f_lista) {
			cout << "El fichero  no existe.";
			exit(0);
		}

		for (int i = 0; i < n; i++)
		{
			if (par[i].first < rango.first && par[i].second < rango.second)
			{
				bran.push_back(std::make_pair(par[i].first, par[i].second));
			}
		}

		for (int i = 0; i < bran.size(); i++)
		{
			f_lista1 << bran[i].first << " " << bran[i].second << endl;
		}
		var = var + "1";
		}*/
		system("pause");
		return 0;
	}
}