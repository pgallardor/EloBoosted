/*
* Búsqueda binaria en arreglo
*/

#include <cstdio>

int binary(int A[], int E, int min, int max){
	while(min <= max){
		int mid = (min + max)/2;
		if (A[mid] == E) return mid;

		if (A[mid] < E) min = mid + 1;
		else max = mid - 1;
	}
	return -1;
}