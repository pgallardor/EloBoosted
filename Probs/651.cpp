#include <cstdio>
#include <cmath>
#define MAX 100001
#define EPS 1e-6
using namespace std;

double memo[MAX];

void init(){
	for (int i = 0; i < MAX; i++) memo[i] = -1.0f;
}

double dp(int N){
	if (N == 1)
		return 0.5f;

	if (abs(memo[N] + 1.0f) > EPS)
		return memo[N];

	memo[N] = dp(N - 1) + 1.0f/(2.0f*N);
	return memo[N];
}

int main(){
	int n;
	init();
	printf("# Cards Overhang\n");
	while(scanf("%d", &n) != EOF){
		printf("%5d     %.3f\n", n, dp(n));
	}

	return 0;
}