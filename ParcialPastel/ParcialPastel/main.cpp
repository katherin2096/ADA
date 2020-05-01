#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Pastel
{
	int ancho;
	int alto;
	int Top =fmax(ancho,alto);
	bool check=0;
};

vector<pair<int, Pastel>>pasteles;


bool sortbysec(const pair<int, Pastel> &a,const pair<int, Pastel> &b)
{
	return (a.first < b.first);
}


void PastelesLuciano(int cortes)
{
	int maxChantilly = 0;
	sort(pasteles.begin(),pasteles.end(), sortbysec);
	for (int i = pasteles.size()-1; i >= 0; i--)
	{
		if (cortes > 0)
		{

				maxChantilly = maxChantilly + pasteles[i].first * 2;
				cortes = cortes - 1;
		}
		else
			i = 0;
	}
	cout << "Chantilly adicional " << maxChantilly << endl;
}


int main()
{
	Pastel a = {5, 7};
	Pastel b = { 2, 8};
	Pastel c = { 5, 4};
	pasteles.push_back(std::make_pair(a.Top, a));
	pasteles.push_back(std::make_pair(b.Top, b));
	pasteles.push_back(std::make_pair(c.Top, c));

	PastelesLuciano(2);
system("pause");
	return 0;
}