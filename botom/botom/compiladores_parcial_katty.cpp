#include<iostream>
#include<string>
#include<vector>
#include <stack>
#include <sstream>
using namespace std;

vector<vector<string>> mat = { { " ", "(", ")", "+", "*", "int", "$" },
								{ "E", "TX", "-", "-", "-", "TX", "-" },
								{"T", "(E)", "-", "-", "-", "int Y", "-" },
								{ "X", "-", "0", "+E", "-", "-", "0" },
								{ "Y", "-", "0", "0", "*T", "-", "0" } };

stack<string> secuencia;
struct Terminal
{
	vector<string> first;
	vector<string> follows;
};

void adde(int x, int y)
{
	string pal = mat[x][y];
	for (int i = pal.size()-1; i >= 0; i--)
	{
		if (pal == "int Y")
		{
			secuencia.push("Y");
			secuencia.push("int");
			i = i - 4;
		}
		else if (pal == "int")
		{
			secuencia.push("int");
			i = i - 2;
		}
		else
		{
			stringstream ss;
			string target;
			char mychar = pal[i];
			ss << mychar;
			ss >> target;
			secuencia.push(target);
		}
		
	}
}

int findNT(string a)
{
	for (int i = 0; i < mat[0].size(); i++)
	{
		if (mat[0][i] == a)
		{
			return i;
		}
	}
}

int findT(string a)
{
	for (int i = 0; i < mat.size(); i++)
	{
		if (mat[i][0] == a)
		{
			return i;
		}
	}
	return 0;
}

bool evaluar1(string cadena)
{
	int cont = secuencia.size();

		for(int i=0;i<=cadena.size();i++)
		{
			int posx = findT(secuencia.top());
			if (cadena[i] == 'i'&&cadena[i + 1] == 'n'&&cadena[i + 2] == 't')
			{
				int posy = findNT("int");
				if (mat[posx][posy] != "-"&& mat[posx][posy] != "0")
				{
					secuencia.pop();
					adde(posx, posy);
				}
				else if (mat[posx][posy] == "0")
				{
					secuencia.pop();
				}
				else if (mat[posx][posy] == "-")
				{
					cout << "error" << endl;
					return 0;
				}

				if (secuencia.top() == "int")
				{
					secuencia.pop();
					i = i + 2;
				}
				else
					evaluar1(cadena);

			}
			else if (cadena[i] == '(')
			{
				int posy = findNT("(");
				if (mat[posx][posy] != "-"&& mat[posx][posy] != "0")
				{
					secuencia.pop();
					adde(posx, posy);
				}
				else if (mat[posx][posy] == "0")
				{
					secuencia.pop();
				}
				else if (mat[posx][posy] == "-")
				{
					cout << "error" << endl;
					return 0;
				}

				if (secuencia.top() == "(")
					secuencia.pop();
				else
					evaluar1(cadena);
				}

			else if (cadena[i] == ')')
			{
				int posy = findNT(")");
				if (mat[posx][posy] != "-"&& mat[posx][posy] != "0")
				{
					secuencia.pop();
					adde(posx, posy);
				}
				else if (mat[posx][posy] == "0")
				{
					secuencia.pop();
				}
				else if (mat[posx][posy] == "-")
				{
					cout << "error" << endl;
					return 0;
				}
				if (secuencia.top() == ")")
					secuencia.pop();
				else
					evaluar1(cadena);

			}
			else if (cadena[i] == '+')
			{
				int posy = findNT("+");
				if (mat[posx][posy] != "-"&& mat[posx][posy] != "0")
				{
					secuencia.pop();
					adde(posx, posy);
				}
				else if (mat[posx][posy] == "0")
				{
					secuencia.pop();
				}
				else if (mat[posx][posy] == "-")
				{
					cout << "error" << endl;
					return 0;
				}
				if (secuencia.top() == "+")
					secuencia.pop();
				else
					evaluar1(cadena);

			}
			else if (cadena[i] == '*')
			{
				int posy = findNT("*");
				if (mat[posx][posy] != "-"&& mat[posx][posy] != "0")
				{
					secuencia.pop();
					adde(posx, posy);
				}
				else if (mat[posx][posy] == "0")
				{
					secuencia.pop();
				}
				else if (mat[posx][posy] == "-")
				{
					cout << "error" << endl;
					return 0;
				}
				if (secuencia.top() == "*")
					secuencia.pop();
				else
					evaluar1(cadena);
			}
			else if (cadena[i] == '$')
			{
				int posy = findNT("$");
				
				if (secuencia.top() == "$")
				{
					secuencia.pop();
					cout << "done" << endl;
					break;
					return 1;
				}
				else if (mat[posx][posy] == "0")
				{
					secuencia.pop();
				}				
				else if(mat[posx][posy] == "-")
				{
					cout << "error" << endl;
					return 0;
				}
				else
				evaluar1(cadena);
					
				
			}
		}
	}

/*
bool evaluar(string cadena)
{

	int x ;
	int y;

	if (secuencia.size() > 0)
	{

		for (int i = 0; i <= cadena.size() + 1; i++)
		{
			int posy = findT(secuencia.top());

			if (cadena[i] == 'i'&&cadena[i + 1] == 'n'&&cadena[i + 2] == 't')
			{
				int pos = findNT("int");
				if (mat[posy][pos] == "-")
				{
					cout << "error" << endl;
					return false;
				}
				else if (mat[posy][pos] == "0")
				{
					secuencia.pop();
				}
				else
				{
					secuencia.pop();
					adde(posy, pos);
					//secuencia.push(mat[posy][pos]);

				}if (secuencia.top() == "int")
				{
					secuencia.pop();
					i = i + 2;
				}
				else
					evaluar(cadena);

			}
			else if (cadena[i] == '(')
			{
				int pos = findNT("(");
				if (mat[posy][pos] == "-")
				{
					cout << "error" << endl;
					return false;
				}
				else if (mat[posy][pos] == "0")
				{
					secuencia.pop();
				}
				else
				{
					secuencia.pop();
					adde(posy, pos);

				}if (secuencia.top() == "(")
					secuencia.pop();
				else
					evaluar(cadena);
			}
			else if (cadena[i] == ')')
			{
				int pos = findNT(")");
				if (mat[posy][pos] == "-")
				{
					cout << "error" << endl;
					return false;
				}
				else if (mat[posy][pos] == "0")
				{
					secuencia.pop();
				}
				else
				{
					secuencia.pop();
					adde(posy, pos);

				}if (secuencia.top() == ")")
					secuencia.pop();
				else
					evaluar(cadena);

			}
			else if (cadena[i] == '+')
			{
				int pos = findNT("+");

				if (mat[posy][pos] == "-")
				{
					cout << "error" << endl;
					return false;
				}
				else if (mat[posy][pos] == "0")
				{
					secuencia.pop();
				}
				else
				{
					secuencia.pop();
					adde(posy, pos);

				}if (secuencia.top() == "+")
					secuencia.pop();
				else
					evaluar(cadena);

			}
			else if (cadena[i] == '*')
			{
				int pos = findNT("*");
				if (mat[posy][pos] == "-")
				{
					cout << "error" << endl;
					return false;
				}
				else if (mat[posy][pos] == "0")
				{
					secuencia.pop();
				}
				else
				{
					secuencia.pop();
					adde(posy, pos);

				}
				if (secuencia.top() == "*")
					secuencia.pop();
				else
					evaluar(cadena);
			}
			else if (cadena[i] == '$')
			{
				int pos = findNT("$");
				if (secuencia.top() == "$")
				{
					cout << "done" << endl;
					return 1;
				}
				else if (mat[posy][pos] == "-")
				{
					cout << "error" << endl;
					return false;
				}
				else if (mat[posy][pos] == "0")
				{
					secuencia.pop();
				}
				else
				{
					secuencia.pop();
					adde(posy, pos);

				}
				if (secuencia.top() == "$")
					secuencia.pop();
				else
					evaluar(cadena);
			}
		}
	}
	return 0;
}
*/
int main()
{
	secuencia.push("$");
	secuencia.push("E");

	Terminal suma;
	suma.first = {"+"};
	suma.follows = { "(","int" };
	Terminal multi;
	multi.first = { "*" };
	multi.follows = { "(","int" };
	Terminal ipar;
	ipar.first = { "(" };
	ipar.follows = { "(","int" };
	Terminal dpar;
	dpar.first = { ")" };
	dpar.follows = { "+","$" };
	Terminal tint;
	tint.first = { "int" };
	tint.follows = { "*","+","$",")" };
	Terminal T;
	T.first = { "(","int" };
	T.follows = { "+","$",")"};
	Terminal X;
	X.first = { "+","0" };
	X.follows = { "$",")" };
	Terminal Y;
	Y.first = { "*","0" };
	Y.follows = { "+","$",")" };
	Terminal E;
	E.first = { "(","int" };
	E.follows = { "$",")" };

	cout << mat[1].size() << endl;
	string entrada;
	cin >> entrada;
	entrada = entrada + "$";
	evaluar1(entrada);
	system("pause");
	return 0;
}

