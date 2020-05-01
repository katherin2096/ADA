#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

void sumaEspiral(int n)
{
	vector<int>sumitas;
	int total = 0;
	int cont = 0;
	if (n % 2 == 0)
	{
		int num = 2;
		while (cont <= n / 2)
		{
			if (cont == 0)
			{
				sumitas.push_back(0);
				total = sumitas[cont];
			}
			else
			{
				int temp = sumitas[cont - 1] + (pow((num-1),2)+1) + pow(num,2);
				sumitas.push_back(temp);
				total = sumitas[cont];
				num = num + 2;
			}
			cont++;
		}

	}
	else
	{
		int num = 3;
		while (cont <= n / 2)
		{
			if (cont == 0)
			{
				sumitas.push_back(1);
				total = sumitas[cont];
			}
			else
			{
				int temp = sumitas[cont - 1] + (pow((num - 1), 2) + 1) + pow(num, 2);
				sumitas.push_back(temp);
				total = sumitas[cont];
				num = num + 2;
			}
			cont++;
		}
	}

	cout << "la suma de la espiral es -----> "<<total<<endl;
}

int main()
{
	int b = 0.5;
	cout << b << endl;
	int a = 0;
	cin >> a;
	sumaEspiral(a);
	system("pause");
	return 0;
}