#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stdint.h>
 
using namespace std;
 
ifstream in("input.txt");
ofstream out("output.txt");
 
int N, A, B;
vector<pair<int, int64_t> > L[100000];
int64_t D[100000];
 
class compare 
{
public:
    bool operator()(pair<int, int64_t> a, pair<int, int64_t> b) const 
    {
        return a.second > b.second;
    }
};
 
 
int main() {
    // N numero di nodi
    // M numero di archi
    in >> N >> A >> B;
    // printf("%d, %d, %d\n", N, A, B);
    int M = A + B;
    int s = 1, d = N; // s nodo di start e d nodo di arrivo.
    //in >> s >> d;
    // printf("%d, %d\n", s, d);
     
    for (int i = 0; i < A; i++) {
        int a, b;
        in >> a >> b ;
        // printf("%d, %d\n", a, b);
        L[a].push_back(make_pair(b, 0)); // Creo l'arco ab di peso c.
        L[b].push_back(make_pair(a, 0));  
    }

    for (int i = 0; i < B; i++) {
        int a, b;
        in >> a >> b ;
        // printf("%d, %d\n", a, b);
        L[a].push_back(make_pair(b, 1)); // Creo l'arco ab di peso c.
        L[b].push_back(make_pair(a, 1));  
    }
     
    for (int i = 0; i <= N; i++) {
        D[i] = -1;
    }
    //memset(D, -1, N * sizeof(int)); Si puo' usare questa ma solo con -1 e 0
     
    priority_queue<pair<int, int64_t>, vector<pair<int, int64_t> >, compare> q;
    q.push(make_pair(s, 0)); // aggiungo il nodo di partenza di peso zero
     
    while (q.size() > 0) {
        
        pair<int, int64_t> n = q.top(); q.pop();
         
        if (D[n.first] >= 0) continue;

        D[n.first] = n.second;         
        int s = L[n.first].size();

        for (int i = 0; i < s; i++)      
        { 
            if (D[L[n.first][i].first] >= 0) continue;
             
            q.push(make_pair(L[n.first][i].first, n.second + L[n.first][i].second));
        }
    }
    out << D[d] << endl;
}
			