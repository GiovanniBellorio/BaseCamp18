#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <vector>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int* inizio;
static int* fine;
static int tempo;

using namespace std;

vector<pair<int,int> > adj[500001];

static inline int max(int a, int b){
	return a > b ? a : b;
}

bool visitato[500001];

// Declaring functions
int raggiungi(int N, int M, int A[], int B[], int inizio[], int fine[]){
	for (int i = 0; i < M; i++){
		adj[A[i]].push_back(make_pair(B[i], i));
		adj[B[i]].push_back(make_pair(A[i], i));
	}

	priority_queue<pair<int,int> > Q;
	Q.push(make_pair(0, 0));

	while (!Q.empty()) {
		auto e = Q.top(); Q.pop();
		int u = e.second;
		int t = -e.first;

		if (visitato[u])
			continue;

		visitato[u] = true;

		if (u == N-1)
			return t;

		for (auto e : adj[u]) {
			int v = e.first;
			int scala = e.second;
			int time = max(inizio[scala], t) + 1;
			if (time <= fine[scala])
				Q.push(make_pair(-time, v));
		}
	}

	return -1;
}

int main() {
	fr = stdin;
	fw = stdout;

	// Reading input
	fscanf(fr, " %d %d", &N, &M);
	A = (int*)malloc((M) * sizeof(int));
	B = (int*)malloc((M) * sizeof(int));
	inizio = (int*)malloc((M) * sizeof(int));
	fine = (int*)malloc((M) * sizeof(int));
	for (int i0 = 0; i0 < M; i0++) {
		fscanf(fr, " %d %d %d %d", &A[i0], &B[i0], &inizio[i0], &fine[i0]);
	}

	// Calling functions
	tempo = raggiungi(N, M, A, B, inizio, fine);

	// Writing output
	fprintf(fw, "%d\n", tempo);

	fclose(fr);
	fclose(fw);
	return 0;
}