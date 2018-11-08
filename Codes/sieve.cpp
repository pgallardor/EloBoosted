/*
* Criba de Eratóstenes
*/
#include <bitset>
#include <vector>
using namespace std;

typedef unsigned long long ull; 
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