#include <stdio.h>
#include <assert.h>
#include <vector>

using std::vector;

#define MAXM 100000
vector<int> adj[MAXM];
bool visitato[MAXM];

void DFS(int i){
	if(visitato[i])
		return;
	visitato[i] = true;
	for(int n : adj[i])
		DFS(n);
}

int costruisci(int N, int M, int da[], int a[]) {
    // Mettete qui il codice della soluzione

    for(int i = 0; i < M; i++){
    	adj[da[i]].push_back(a[i]);
    	adj[a[i]].push_back(da[i]);
    }

    int count = -1;
    for(int i = 0; i < N; i++){
    	if(!visitato[i]){
    		count++;
    		DFS(i);
    	}
    }
    return count;
}


int da[MAXM], a[MAXM];

int main() {
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int N, M;
    assert(2 == scanf("%d %d", &N, &M));

    for(int i = 0; i < M; i++)
        assert(2 == scanf("%d %d", &da[i], &a[i]));

    printf("%d\n", costruisci(N, M, da, a));
    return 0;
}