#include <cstdio>



int main(){
	unsigned int N, L, U;

	while (scanf("%d %d %d", &N, &L, &U) != EOF){
		int mask = 1;
		while (mask < N) mask = mask << 1;
		mask -= 1;

		int M = ~N & mask;

		int add, subs = 1;
		while (M < L){
			add = 1;
			while (M + (add << 1) < U) add = add << 1;
			M += add;
		}

		printf("%d\n", M);
	}

	return 0;
}