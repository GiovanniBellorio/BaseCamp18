#include <iostream>
#include <string>
#include <set>

#define MAXN 100000

std::string target_var[MAXN];
std::string operand1_var[MAXN];
std::string operand2_var[MAXN];

std::set<std::string> s;

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        char eq, op;
        std::cin >> target_var[i] >> eq >> operand1_var[i] >> op >> operand2_var[i];
    }

    // insert your code here
    int cnt = 0;
    for (int i=0; i<N; i++){
    	if(s.find(operand1_var[i]) == s.end()) {
    		if(s.find(operand2_var[i]) == s.end()) {
    			cnt++;
    		}
    	}
    	s.insert(target_var[i]);
    }

    std::cout << cnt << std::endl;

    return 0;
}