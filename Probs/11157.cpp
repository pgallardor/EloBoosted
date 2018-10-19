#include <cstdio>
#include <vector>
using namespace std;

int big[101], small[101], sim[202];

int hop(int bi, int i, int j){

	int hoppity;
	sim[0] = big[bi - 1];
	for (int k = i; k <= j; k++) sim[k - i + 1] = small[k];
	sim[j - i + 2] = big[bi];
	
	int n = j - i + 3, jmp = -1;	

	for (int k = 0; k < n; k+=2){
		if (k + 2 >= n){
			hoppity = sim[n - 1] - sim[k];
			jmp = max(jmp, hoppity);
			break;
		}

		hoppity = sim[k + 2] - sim[k];
		jmp = max(jmp, hoppity);
	}

	int start = n - 1;
	if ((j - i + 1) % 2){
		start = n - 2;
		jmp = max(jmp, sim[n - 1] - sim[start]);
	}

	for (int k = start; k >= 0; k-=2){
		if (k - 2 < 0){
			hoppity = sim[k] - sim[0];
			jmp = max(jmp, hoppity);
			break;
		} 

		hoppity = sim[k] - sim[k - 2];
		jmp = max(jmp, hoppity);
	}

	return jmp;
}

int solve(int B, int S){
	int minimax = -1;
	int bi, si, sj;
	bi = 1;
	si = sj = 0;

	while(bi < B){
		if (si >= S || small[si] > big[bi]){
			minimax = max(minimax, big[bi] - big[bi - 1]);
			bi++;
			continue;
		}
		while(sj + 1 < S && small[sj + 1] < big[bi]) sj++;

		minimax = max(minimax, hop(bi, si, sj));

		bi++;
		si = sj = sj + 1;
	}

	return minimax;	
}

void print(int B, int S){
	printf("big stones: ");
	for (int i = 0; i < B; i++){
		printf("%d ", big[i]);
	}
	printf("\nsmall stones: ");
	for (int i = 0; i < S; i++){
		printf("%d ", small[i]);
	}
	printf("\n");
}

int main(){
	int T, N, D;
	char c;
	scanf("%d", &T);
	for (int i = 0; i < T; i++){
		int b = 0, s = 0, pos;

		scanf("%d %d", &N, &D);
		big[b++] = 0;

		getchar();
		//getchar();

		for (int k = 0; k < N; k++){
			scanf("%c-%d", &c, &pos);
			//printf("%c %d\n", c, pos);
			if (c == 'B') big[b++] = pos;
			else small[s++] = pos;
			getchar();
		}

		big[b++] = D;
		//print(b, s);


		printf("Case %d: %d\n", i+1, solve(b, s));
	}
	return 0;
}