#include <cstdio>
using namespace std;

int main(){
	int n;

	while(scanf("%d", &n) != EOF){
		if (n > 0 && !(n%3)) printf("1\n");
		else printf("0\n");
	}

	return 0;
}