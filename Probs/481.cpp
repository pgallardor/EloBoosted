#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;


vector<int> X;

vector<int> sequence;

int LIS(int i){
	if(i == 0) return 1;

	int ans = 1;

	for(int j = 0; j < i; j++){
		if(X[i] > X[j]){
			ans = max(ans, 1+ LIS(j));
		} 
	}
	return ans;
}


int main(){
	int aux;
	int count=0;
	while(scanf("%d",&aux) != EOF){
		X.push_back(aux);
		count++;
	}
	cout << LIS(count-1) << "*" << endl;


	return 0;
}