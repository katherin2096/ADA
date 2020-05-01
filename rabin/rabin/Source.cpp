
#include <string.h>
#include <iostream> 
#include <math.h> 
using namespace std;
#define d 256 
void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0;
	int t[23];
	t[0] = 0;
	int a = pow(d, M - 1);
	int h = (a) % q;
	cout << h << endl;
	//for (i = 0; i < M - 1; i++) 
	//	h = (h * d) % q; 
	for (i = 0; i < M; i++) {
		cout << d * p + pat[i] << ", " << d * t[0] + txt[i] << endl;
		p = (d * p + pat[i]) % q;
		t[0] = (d * t[0] + txt[i]) % q;
	}
	for (i = 0; i <= N - M; i++) {
		if (p == t[i]) {
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j])
					break;
			}
			if (j == M)
				cout << "index" << i << endl;
		}
		if (i < N - M) {
			t[i + 1] = (d*(t[i] - txt[i + 1] * h) + txt[i + M + 1]) % q;
		}
		cout << j << " ";
	}

}

int main()
{
	char txt[] = "walkercito es un papito";
	char pat[] = "papi";
	int q = 101; // A prime number 
	search(pat, txt, q);
	system("pause");
	return 0;
}
