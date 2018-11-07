#include <cstdio>
#include <iostream>
#include <algorithm>
#define MAX (1 << 29)

using namespace std;

int coins[105];
int b_value = MAX, c_m = MAX;

int func(int CN, int idx, int total_value, int curr, int ccoins){
	if (total_value <= curr){
		if (b_value > curr){
			b_value = curr;
			c_m = ccoins;
		}
		else if (b_value == curr && ccoins < c_m) c_m = ccoins;
		return curr;
	}

	if (idx >= CN){
		return MAX;
	}

	return min(func(CN, idx + 1, total_value, curr + coins[idx], ccoins + 1), func(CN, idx + 1, total_value, curr, ccoins));
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int v, CN;
		scanf("%d", &v);
		scanf("%d", &CN);

		for (int i = 0; i < CN; i++){
			scanf("%d", &coins[i]);
		}

		int e = func(CN, 0, v, 0, 0);
		printf("%d %d\n", b_value, c_m);
	}
	return 0;
}