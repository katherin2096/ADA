#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
# define num_max_car 256  

void sinCoincidencia(string str, int size, int badchar[num_max_car])
{
	int i;

	for (i = 0; i < num_max_car; i++)
		badchar[i] = -1;

	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}


void search(string txt, string pal)
{
	int m = pal.size();
	int n = txt.size();

	int noCaracter[num_max_car];

	sinCoincidencia(pal, m, noCaracter);

	int s = 0; 
	while (s <= (n - m))
	{
		int j = m - 1;
	while (j >= 0 && pal[j] == txt[s + j])
			j--;
	//
		if (j < 0)
		{
			cout << "encontrado en la poscicion " << s << endl;
			s += (s + m < n) ? m - noCaracter[txt[s + m]] : 1;

		}

		else
			s += max(1, j - noCaracter[txt[s + j]]);
	}
}

int main()
{
	char txt[] = "aaasdfsdfmisduamiahjemiausd";
	char pal[] = "miau";
	search(txt, pal);
	system("pause");
	return 0;
}
