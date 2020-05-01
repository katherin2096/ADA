#include <iostream>
#include<stdio.h> 
#include<string.h> 
#define num_car_pos 256 

using namespace std;
int estadoSiguiente(char *pat, int M, int state, int x)
{
	if (state < M && x == pat[state]) //aqui si concuerda cambiamos de estado
		return state + 1;

		int ns, i; //res del next
 
	for (ns = state; ns > 0; ns--)
	{
		if (pat[ns - 1] == x)
		{
			for (i = 0; i < ns - 1; i++)
				if (pat[i] != pat[state - ns + 1 + i])
					break;
			if (i == ns - 1)
				return ns;
		}
	}

	return 0;
}


void automata(char *pat, int M, int TF[][num_car_pos])
{
	int estado, x;
	for (estado = 0; estado <= M; ++estado)
		for (x = 0; x < num_car_pos; ++x)
			TF[estado][x] = estadoSiguiente(pat, M, estado, x);
}

void busqueda(char *pal, char *txt)
{
	int M = strlen(pal);
	int N = strlen(txt);
	int AuMatriz[4 + 1][num_car_pos];
	automata(pal, M, AuMatriz);
	//aqui se procesa la subcadena en el automata 
	int i, state = 0;
	for (i = 0; i < N; i++)
	{
		state = AuMatriz[state][txt[i]];
		if (state == M)
		{
			cout << "encontrado en la poscicion " << (i - M + 1) << endl;	
		}
		}
}

int main()
{
	char txt[] = "aaasdfsdfmisduamiahjemiausd";
	char pal[] = "miau";
	busqueda(pal, txt);
	system("pause");
	return 0;
}