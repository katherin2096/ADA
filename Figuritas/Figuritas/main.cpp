#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int tamF = 6;
int tamC = 7;
char salida[6] = { ' ','+','R', 'T', 'L','C' };  // secuencia que queremos generar
char entrada[7] = { ' ','+','E', 'T','C','L','N'}; //secuencia que debemos modificar

int matriz[6][7] = { {0,1,2,3,4,5,6},
					 {1,0,0,0,0,0,0},
					 {2,0,0,0,0,0,0},
					 {3,0,0,0,0,0,0}, 
					 {4,0,0,0,0,0,0},
					 {5,0,0,0,0,0,0 }};

void replica()
{
	for (int i = 1; i < tamF; i++)
	{
		for (int j = 1; j < tamC; j++)
		{
			if(entrada[j]==salida[i])
			{
				matriz[i][j] = matriz[i - 1][j - 1];
			}
			else
			{
				int a = matriz[i-1][j];
				int b = matriz[i][j - 1];
				int c = matriz[i - 1][j - 1];
				matriz[i][j] = (fmin(c,fmin(a,b)))+1;
			}
		}
	}
	cout <<"la cantidad minima de cambios a realizar sera "<< matriz[5][6]<<endl;
}

int main()
{
	replica();
	system("pause");
	return 0;
}








