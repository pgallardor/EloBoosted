#include <cstdio>
#include <iostream>
#include <bitset>
#include <utility>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> ii; 
ull sieve_size;

bitset<10000010> bs;
vector<ull> primes;

void sieve(ull upperbound){
	sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;

	for (ull i = 2; i < sieve_size; i++){
		if (bs[i]){
			for (ull j = i*i; j < sieve_size; j += i){
				bs[j] = 0;
			}
			primes.push_back(i);
		}
	}
}

bool isPrime(ull N){
	if (N <= sieve_size) return bs[N];
	for (int i = 0; i < primes.size(); i++){
		if (!(N % primes[i])) return false;
	}

	return true;
}

ull convertToInt(ull b, ull exp){
	ull result = 1;
	for (ull i = 0; i < exp; i++){
		result *= b;
	}

	return result;
}

void solve(ull N){
	stack<ii> s;
	while(N > 1){
		//printf("%llu\n", N);
		for (int i = 0; i < primes.size(); i++){
			ull exp = 0;
			while(N % primes[i] == 0){
				N /= primes[i];
				exp++;
			}
			if (exp > 0)
				s.push(ii(primes[i], exp));
		}
	}
	bool first = true;
	while(!s.empty()){
		ii tmp = s.top(); s.pop();
		if (!first) printf(" ");
		printf("%llu %llu", tmp.first, tmp.second);
		first = false;
	}
	printf("\n");
}

int main(){
	string in;
	sieve(100000);
	while(getline(cin, in) && in.compare("0")){
		//cin.ignore();
		ull b, e, num = 1;
		istringstream ss(in);

		while(ss >> b >> e){
			//printf("%llu %llu\n", b, e);
			num *= convertToInt(b, e);
		}

		num--;
		//printf("%llu\n", num);
		solve(num);
		//cin.ignore();
	}

	return 0;
}