#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int bitn(int N, int idx, vector<int> &w){
	int cnt = 0, nei;
	for (int i = 0; i < N; i++){
		nei = idx ^ (1 << i);
		cnt += w[nei];
	}

	return cnt;
}

int sum(int N, int idx, vector<int> &pot){
	int max_tmp = -1, nei, sum;
	for (int i = 0; i < N; i++){
		nei = idx ^ (1 << i);
		sum = pot[idx] + pot[nei];
		max_tmp = max(sum, max_tmp);
	}

	return max_tmp;
}

int solve(int N, int E, vector<int> &w){
	vector<int> potency(E, 0);
	for (int i = 0; i < E; i++){
		potency[i] = bitn(N, i, w);
	}

	int maxsum = -1;
	for (int i = 0; i < E; i++){
		int temp = sum(N, i, potency);
		maxsum = max(temp, maxsum);
	}

	return maxsum;
}

int main(){
	int N, bf;
	while(scanf("%d", &N) != EOF){
		int E = 1 << N;
		vector<int> weights(E);

		for (int i = 0; i < E; i++){
			scanf("%d", &bf);
			weights[i] = bf;
		}
		int result = solve(N, E, weights);
		printf("%d\n", result);
	}
	return 0;
}