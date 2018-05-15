#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>

using namespace std;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;

int N, M;
vector<pair<int, int> > adj[1001];

int solve(int n){
	min_heap<tuple<int, int, int> > Q;

	int D[1001];

	for (int i = 0; i < 1001; i++)
		D[i] = -1;

	Q.push( make_tuple(0, n, -1) );

	while(!Q.empty())
	{
		auto x = Q.top();
		Q.pop();

		int d = get<0>(x); // distanza impiegata per raggiungere u
		int u = get<1>(x); // nodo corrente
		int p = get<2>(x); // nodo padre

		if (D[u] >= 0)
			return D[u] + d;

		D[u] = d; // setto distanza

		for (auto y : adj[u])
		{
			int v = y.first;
			int w = y.second;

			if (p == v) // nodo uguale al padre, non lo considero
				continue;

			Q.push( make_tuple(d + w, v, u) );
		}
	}
	return INT_MAX;
}


int main() {
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; i++)
    {
    	int u, v, w;
    	scanf("%d %d %d", &u, &v, &w);
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }

    int min = INT_MAX;
    for (int i = 1; i <= N; i++)
    {
    	int res = solve(i);
    	if (res < min)
    		min = res;
    }

    printf("%d\n", min);
    return 0;
}