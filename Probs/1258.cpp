#include <cstdio>
#include <vector>
#define TOTAL 87

using namespace std;

unsigned long long fib[TOTAL];

void init(){
	fib[1] = 1; fib[2] = 2;
	for (int i = 3; i < TOTAL; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
	}
}

void solve(unsigned long long N){
	int ind;
	vector<int> coef;
	vector<unsigned long long> vals;
	for (int i = 1; i < TOTAL; i++){
		if (fib[i] > N){
			ind = i - 1;
			break;
		}
	}

	//printf("T(%d)\n", ind);

	unsigned long long tmp = N;
	for (int i = ind; i >= 1; i--){
		if (fib[i] > tmp) continue;
		coef.push_back(i);
		vals.push_back(fib[i]);
		tmp -= fib[i];
	}

	printf("%llu\n", N);
	int L = coef.size();
	for (int i = 0; i < 2*L; i++){
		if (i == L) printf("\n");
		
		if (i < L) printf("%d ", coef[i]);
		else printf("%llu ", vals[i - L]);
	}
	printf("\n");
}

int main(){
	unsigned long long N;
	init();
	while(scanf("%llu", &N) != EOF){
		solve(N);
		printf("\n");
	}

	return 0;
}