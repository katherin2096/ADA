#include<iostream>
using namespace std;
#define N 4

int mochila( int p[], int val[])
{
	int n = 4;  
	int m = 10;
	int resp[4] = { 0 };
	int mat[4 + 1][10 + 1];  // n+1  m+1
	int keep[4 + 1][10 + 1]; //n+1 m+1
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				mat[i][j] = 0;
				keep[i][j] = 0;
			}
			else if ((p[i - 1] <= j) && (val[i - 1] + mat[i - 1][j - p[i - 1]] > mat[i - 1][j]))
			{

				mat[i][j] = val[i - 1] + mat[i - 1][j - p[i - 1]];
				keep[i][j] = 1;
			}
			else
			{
				mat[i][j] = mat[i - 1][j];
				keep[i][j] = 0;
			}

			//cout<<mat[i][j]<<'\t';
		}
		//cout<<endl;

	}

	int k = m;
	for (int i = n; i >= 0; i--)
	{
		if (keep[i][k] == 1)
		{
			//cout<<i-1<<",";
			resp[i - 1] = 1;
			k = k - p[i - 1];
		}
	}
	//cout<<endl;

	for (int i = 0; i < n; i++)
	{
		cout << resp[i] << '\t';
	}
	cout << endl;
	return mat[n][m];
}

int main()
{
	int val[4] = { 10,40,30,50 };
	int p[4] = { 5,4,6,3 };

	int m = 10;

	cout << mochila( p, val);
	system("pause");
	return 0;

}