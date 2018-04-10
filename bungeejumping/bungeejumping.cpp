#include <cstdio>
#include <cassert>


int main(){
#ifdef 	EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int N;
	scanf("%d", &N);
	
	int v[N];
	for(int i = 0; i < N; i++)
		scanf("%d", &v[i]);

#if 0
	for(int i = 0; i < N; i++)
		printf("%d ", v[i]);
	printf("\n");
#endif

	

	return 0;
}