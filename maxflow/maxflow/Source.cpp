#include <algorithm>
#include <iostream> 
#include <limits.h> 
#include <string> 
#include <queue> 
using namespace std;

#define V 6 

bool bfs(int grafo[V][V], int s, int t, int parent[])
{

	bool visitados[V];
	memset(visitados, 0, sizeof(visitados));

	queue <int> q;
	q.push(s);
	visitados[s] = true;
	parent[s] = -1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v = 0; v<V; v++)
		{
			if (visitados[v] == false && grafo[u][v] > 0)
			{
				q.push(v);
				parent[v] = u;
				visitados[v] = true;
			}
		}
	}


	return (visitados[t] == true);
}


int maxflow(int grafo[V][V], int ini, int fin )
{
	int cont = 0;
	bool visit = 0;
 for(int i=0;i<V;i++)
 {
	 for(int j=0;j<V;j++)
	 {
		 grafo[i][j];
	if(bfs(grafo))
	 }
 }
 }