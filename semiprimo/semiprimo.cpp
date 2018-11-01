#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

bool isPrime(int x){
	if ( x % 2 == 0) return 0;
	int radq = sqrt(x);
	for (int i = 3; i < radq + 1; i += 2){
		if ( x % i == 0) return 0;
	}
	return 1;
}

int main(){
	int N;
	in >> N;

	if (isPrime(N)){
		out << "-1" << endl;
		return 0;
	}

	int radq = sqrt(N);
	for (int i = 2; i <= radq; ++i){
		if (N % i == 0 && isPrime(i)){
			int d = N/i;
			if (isPrime(d)){
				out << i << " " << d << endl;
				return 0;
			}
			else{
				out << "-1" << endl;
				return 0;
			}
		}
	}
}