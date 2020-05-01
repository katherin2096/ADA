#include<iostream>
#include<vector>
#include<string>
#include <fstream>
using namespace std;
vector<pair<string,vector<string>>>lineas1;
vector<pair<string, vector<string>>>lineas2;
vector<string> segmentar(const string& s, const char& c)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c) buff += n; else
			if (n == c && buff != "") {
				v.push_back(buff); 
				//myhash->insertMiss(buff, texto);
				buff = "";
			}
	}
	if (buff != "")
			v.push_back(buff);
		//myhash->insertMiss(buff, texto);
	return v;
}

vector<pair<string, vector<string>>> leerFicherofast(string ruta, vector<pair<string, vector<string>>>&lineas)
{

	std::ifstream in;

	in.open(ruta);

	std::string line;

	while (in.good())
	{
		std::getline(in, line);
		vector<string> pal = segmentar(line, ' ');
		lineas.push_back(std::make_pair(line,pal));
	}
	return lineas;
}

void interseccion(string ruta1, string ruta2)
{
	int cont = 0;
	leerFicherofast(ruta1, lineas1);
	leerFicherofast(ruta2, lineas2);

	for (int i = 0; i<lineas1.size() ;i++)
	{
		for(int j=0;j<lineas2.size();j++)
		{ 
			if (lineas1[i].first.size() == lineas2[j].first.size())
			{
				if (lineas1[i].second == lineas2[j].second)
				{
					cont = cont + 1;
					cout << "linea repetida ====>  " << lineas1[i].first<<endl;
					lineas1.erase(lineas1.begin() + i );
					lineas2.erase(lineas2.begin() + j );
					j = -1;
				}
		    }
		}
	}
	cout << "numero total de lineas repetida ====> " << cont<<endl;
	
}


int max = 0;

vector<string>line1;
void interseccion1(string ruta1, string ruta2,int ini)
{
	vector<string>line;
	int pos=0;
	int cont = 0;
	leerFicherofast(ruta1, lineas1);
	leerFicherofast(ruta2, lineas2);
	for (ini; ini<lineas1.size(); ini++)
	{
		for (int j = pos; j < lineas2.size(); j++)
		{
			if (lineas1[ini].first.size() == lineas2[j].first.size())
			{
				if (lineas1[ini].second == lineas2[j].second)
				{
					cont = cont + 1;
//					cout << "linea repetida ====>  " << lineas1[ini].first << endl;
					line.push_back(lineas1[ini].first);
					pos = j;
					j = lineas2.size();
					break;
				}
			}
			
		}
	}
	line.pop_back();
	if (line.size() > line1.size())
	{
		line1 = line;
	}
	while(ini < lineas1.size())
		{
		interseccion1(ruta1, ruta2, ini + 1);
	}
	cout << "numero total de lineas repetida ====> " << line1.size() << endl;
	for (int k = 0; k < line1.size(); k++)
	{
		cout<<line1[k]<<endl;
	}
}

int main()
{
	string rutas2 = "C:/Users/Daniela/Documents/Visual Studio 2017/Projects/Palabras/Palabras/text2.txt";
	string rutas1 = "C:/Users/Daniela/Documents/Visual Studio 2017/Projects/Palabras/Palabras/text1.txt";
	
	//leerFicherofast(ruta1);
	interseccion1(rutas1, rutas2,0);// rutas1 debe tener mas lineas que rutas 2 poner el if que falta aqui :3
	system("pause");
	return 0;
}