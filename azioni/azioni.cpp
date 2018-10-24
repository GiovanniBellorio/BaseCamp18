#include <cstdio>
#include <cassert>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");
const int N_MAX = 100;

int N;
int valori[N_MAX];

int main(){
	int max = 0;
	in >> N;
	
	for(int i = 0; i<N; i++)
		in >> valori[i];

	for(int i = 0; i<N-1; i++)
		if(max < abs(valori[i] - valori[i+1]))
			max = abs(valori[i] - valori[i+1]);

	out << max;
}