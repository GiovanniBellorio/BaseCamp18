#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int N;
int D[101];
int S[101];
int mem[101][366];

int solve (int i, int d)
{
    if (d >= 365 || i == N)
        return 0;
    
    if (mem[i][d])
        return mem[i][d] - 1;
    
    if (d + D[i] > S[i] + 1) 
        return solve(i + 1, d);
    
    int m1 = solve(i + 1, d + D[i]) + 1;
    int m2 = solve(i + 1, d);
    
    mem[i][d] = (m1 > m2 ? m1 : m2) + 1; 
    return mem[i][d] - 1;
}

int main () 
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &N);
    
    for (int i = 0; i < N; i++)
        scanf("%d %d", &D[i], &S[i]);
    
    printf("%d\n", solve(0, 1));
}