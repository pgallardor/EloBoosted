#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(){
	
	int T, N;
	scanf("%d", &T);
	vector<string> o, d;
	string name;

	while(T--){
		scanf("%d", &N);
		cin.ignore();

		for (int i = 0; i < N; i++){
			getline(cin, name);
			o.push_back(name);
		}

		for (int i = 0; i < N; i++){
			getline(cin, name);
			d.push_back(name);
		}

		int oi = N - 1, di = N - 1, difs = 0;

		while(oi >= 0){
			if (o[oi].compare(d[di]) != 0){
				oi--;
				difs++;
			}
			else{
				di--; oi--;
			}
		}

		for (int i = difs - 1; i >= 0; i--){
			cout << d[i] << endl;
		}
		cout << endl;

		o.clear();
		d.clear();
	}

	return 0;
}