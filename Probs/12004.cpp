#include <cstdio>

void result(int n){
	unsigned long long res = 0;
	for (int i = 0; i < n; i++) res += i;

	if (res % 2 == 0) printf("%llu\n", res / 2);
	else printf("%llu/2\n", res);	 
}

int main(){
	int T, n;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		scanf("%d", &n);
		printf("Case %d: ", i+1);
		result(n);
	}

	return 0;
}

