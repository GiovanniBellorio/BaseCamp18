#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<queue>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N,M;

vector<int> L[100000];
int V[100000];

int main() 
{
	in >> N >> M; // Leggo la prima riga contenente N(numero nodi) ed M(numero archi).
	for( int i = 0; i < M; i++ ){
		int a,b;
		in >> a >> b;
		L[a].push_back(b);
		L[b].push_back(a);
	}
	
	queue<int> q;
	q.push(0);

	while( q.size() > 0 )
	{

		int n = q.front(); // top in priority queue
		q.pop();
		
		if( V[n] > 0 )
			continue; // Rimane nel ciclo e si salta un giro, mentre break termina il ciclo.
			
		cout << "Visitato il nodo " << n << endl;
			
		V[n] = 1;
		
		for( int i = 0; i < L[n].size(); i++)
		{
			q.push(L[n][i]);
		}
		
	}
}