#include <cstdio>
#include <cmath>
using namespace std;


int factors[] = { 100, 10000 - 100, 1000000 - 10000 }, f2[] = {2, 3, 5};

int compose(int n){
	int result = 0;
	for (int i = 0; i < 3; i++){
		if (n < factors[i]){
			return result + n * f2[i];
		}

		result += factors[i] * f2[i];
		n -= factors[i];
	}

	return result + 7*n;
}

int binary(int D, int B, int min, int max){
	while(min <= max){
		int mid = (min + max)/2;
		int fm = compose(mid), f1 = compose(D - mid);
		//printf("consumo: %d\npago: %d\n", mid, fm);
		//printf("%d - %d = %d\n", f1, fm, B);
		if (f1 - fm == B) return fm;

		if (f1 - fm > B) min = mid + 1;
		else max = mid - 1;
	}
	return -1;
}


int decompose(int n){
	int result = 0, tmp = n;

	for (int i = 0; i < 3; i++){
		if (tmp < f2[i]*factors[i]){
			result += tmp / f2[i];
			return result;
		}

		tmp -= f2[i] * factors[i];
		result += factors[i];
	}

	result += tmp / 7;
	return result;

}

int main(){
	int A, B;
	while (scanf("%d %d", &A, &B) != EOF && (A || B)){
		int sum = decompose(A);
		//printf("decomposition: %d\n", sum);
		printf("%d\n", binary(sum, B, 0, sum/2));
	}
	return 0;
}