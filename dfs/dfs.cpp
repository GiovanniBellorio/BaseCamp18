#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N,M;

vector<int> L[100000];
int V[100000];

void DFS( int n ){
    
    if(V[n] > 0 ) return;
    
    cout << "Visitato il nodo " << n << endl;
    V[n]=1;
    for(int i = 0; i<L[n].size(); i++)
    {
        DFS(L[n][i]); // i esimo elemento della lista di adiacenza di n
    }
}

int main() {

    in >> N >> M; // Leggo la prima riga contenente N(numero nodi) ed M(numero archi).

    for( int i = 0; i < M; i++ ){
        int a,b;
        in >> a >> b;
        L[a].push_back(b);
        L[b].push_back(a);
    }
    
    DFS(0);
}