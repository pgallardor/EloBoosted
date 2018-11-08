/*
* Bitmask y obtención de combinaciones con bitshift
*/

#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int comb = 1 << n;
	for (int k = 0; k < comb; k++){
		for (int i = n; i >= 0; i--){
			if (k & (1 << i)) printf("1");
			else printf("0");
		}
	printf("\n");
	}

	return 0;
}
