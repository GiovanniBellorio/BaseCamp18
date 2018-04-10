#include <stdio.h>
#include <assert.h>

typedef long long ll;

int calcola(ll k, ll e, ll x){
    ll n = 1;
    while(e){
        n *= x;
        e--;
    }

    int c = 1;
    while(n > 9){
        c++;
        n /= 10;
    }
    return c;
}

ll ricerca(ll s, ll e, int n, int K, int E){
    while(e-s > 1){
        int m = (e+s) / 2;
        if(calcola(K, E, m) <= n){
            s = m;
        }
        else{
            e = m;
        }
    }
    return s;
}

long long predict(long long K, long long E, long long N) {
    // insert your code here
    int inizio = 1;
    int oldidx = 1;
    for(int i=1; i<18; i++){
        int idx = ricerca(1, 1000000000000000000LL, i, K, E);
        if(N >= inizio && N <= inizio + (idx-oldidx)*i){
            return oldidx + (N - inizio)/i; 
        }
        inizio += (idx-oldidx)*i;
        oldidx = idx;
    }
}

int main() {
    FILE *fr, *fw;
    long long K, E, N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(3 == fscanf(fr, "%lld %lld %lld", &K, &E, &N));

    fprintf(fw, "%lld\n", predict(K, E, N));
    fclose(fr);
    fclose(fw);
    return 0;
}