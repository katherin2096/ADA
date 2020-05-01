#include<iostream>
#include <string>
using namespace std;
void automataLPS(char* pat, int M, int* lps);

void KMPSearch(char* pal, char* txt)
{
	int M = strlen(pal);
	int N = strlen(txt);
	int a = 0;
	
	int lps[4];//sufijo del prefijo mas largo
				//resolver el problema que tengo con las matrices
	
	automataLPS(pal, M, lps);

	int i = 0; // indice para txt[] EL TEXTO 
	int j = 0; // indice para pal[] la subcadena 
	while (i < N) {
		if (pal[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout << "encontrado en la poscicion " << (i - j) << endl;
			
			j = lps[j - 1];
		}

		else if (i < N && pal[j] != txt[i]) {
		
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}


void automataLPS(char* pal, int M, int* lps)// AUTOMATA
{
	int len = 0;

	lps[0] = 0;  
	int i = 1;
	while (i < M) {
		if (pal[i] == pal[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len]) 
		{

			if (len != 0) {
				len = lps[len - 1];

			}
			else // if (len == 0) 
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
	char txt[] = "aaasdfsdfmisduamiahjemiausd";
	char pal[] = "miau";
	KMPSearch(pal, txt);
	system("pause");
	return 0;
}