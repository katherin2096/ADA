#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>

using namespace std;



vector<int> metro { 1,2,3,4,5,6,7,8,9,10 };
vector<int>precio {1,5,8,9,10,17,17,20,24,30};
vector<int> ganancia = precio;
int c1 = 0;
int c2 = 0;

void mayorganaciaN(int n)
{
	for (int i = 1; i < n; i++)
	{
		//int dis = metro[i];
		for(int j= metro[i]-1;j>0;j--){
			int corte = metro[i] - j;
			int comple = metro[i] - corte;
			
			int gan = ganancia[corte-1] + ganancia[comple-1];

			if (gan == ganancia[i])
			{
				c1 = corte;
				c2 = comple;
			}

		}
    }

	cout <<"un corte de "<< c1 << " --  y un corte de " << c2 << endl;
}
void mayorganacia()
{
	for (int i = 1; i < ganancia.size(); i++)
	{
		//int dis = metro[i];
		for (int j = metro[i] - 1; j>0; j--) {
			int corte = metro[i] - j;
			int comple = metro[i] - corte;

			int gan = ganancia[corte - 1] + ganancia[comple - 1];

			if (gan > ganancia[i])
			{
				ganancia[i] = gan;

			}

		}
	}
}


void consultar(int m)
{

	int g = ganancia[m - 1];
	cout << "maxima ganancia posible ---> " << g << endl;
}

void print(vector<int> mit)
{
	//cout << "ganancias--> ";
	for (int i = 0; i < mit.size(); i++)
	{
		cout << mit[i] << "-";
	}
}
/*
int cortes(int n, vector<int> p, int max)
{
	if (n == 1)
	{
		return p[0];
	}

	for (int i = 1; i >= n; i++)
	{
		max(cortes(n - 1, p,));
	}

}
*/


int main()
{
	mayorganacia();

	int a;
	cout << "numero de metros comprado" << endl;
	cin >> a;
	consultar(a);
	mayorganaciaN(a);
	cout << "Metros---->";
	print(metro);
	cout << endl;
	cout << "Precios--->";
	print(precio);
	cout << endl;
	cout << "Ganancia-->";
	print(ganancia);
	cout << endl;
	system("pause");
	return 1;
}
