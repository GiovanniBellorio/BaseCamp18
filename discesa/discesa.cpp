#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int valore;
vector<int> p;

int main() 
{
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &N);
    int count = 0;

    for (int livello = 0; livello < N; livello++)
    {
    	if (livello == 0)
    	{
    		scanf("%d", &valore);
    		p.push_back(valore);
    		count++;
    		continue;
    	}
    	
    	for (int j = 0; j < livello + 1; j++)
    	{
    		scanf("%d", &valore);
    		int padre1, padre2;
    		
    		if (j == 0)
    		{
    			padre1 = count - livello;
    			p.push_back( p[padre1] + valore );
    			count++;
    		}
    		else if (j == livello)
    		{
    			padre1 = count - livello - 1;
    			p.push_back( p[padre1] + valore );
    			count++;
    		}
    		else
    		{
    			padre1 = count - livello;
    			padre2 = count - livello - 1;

    			int max_somma = std::max(p[padre1], p[padre2]);
    			p.push_back( max_somma + valore);
    			count++;
    		}
    	}

    	#if 0
    	for (int k = 0; k < p.size(); k++ )
    		printf("%d ", p[k] );
    	printf("\n");
    	#endif
    }

    int max = *max_element(p.begin(), p.end());
    printf("%d\n", max );
    return 0;
}