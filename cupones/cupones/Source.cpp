#include <iostream>
#include <string>
#include <vector>
using namespace std;
long double calcular(int personas, int tamCupones)
{
	long double p = tamCupones;
	for (int i = 0; i<personas; i++)
	{
		p = p*(tamCupones - i) / tamCupones;
	}
	p = 100 * (1 - p); 
	return p;
}
int main()
{
	int grupo;
	long double probabilidad;
	cout << "Introduce cu�ntos cupones tiene el grupo : ";
	cin >> grupo;
	probabilidad = calcular(grupo,64);
	cout << "La probabilidad de que en un grupo de " << grupo << " personas, dos cumplan a�os el mismo d�a es de un " << probabilidad
	<< "%" << endl;
	system("pause");
	return 0;
} 