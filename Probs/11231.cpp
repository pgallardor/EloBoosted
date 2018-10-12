#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int m, n, c, re, can;
	while (scanf("%d %d %d", &n, &m, &c) != EOF && (n || m || c)){
		if (n == 8 && m == 8){
			printf("%d\n", c);
			continue;
		}

		n-=6; m-=7;
		re = n%2;
		n /= 2;

		switch(c){
			case 1:{
				if (re) can = m*n;
				else {
					if (!(m%2)){ 
						m /= 2;
						can = m*n + (m*(n-1));
					}
					else{
						m++;
						m = m/2;
						can = m*n + (n-1)*(m-1);
					}
				}
				break;
			}
			case 0:{
				if (re) can = m*n;
				else{
					if (!(m%2)){ 
						m /= 2;
						can = m*n + (m*(n-1));
					}
					else{
						m++;
						m = m/2;
						can = m*n + (n-1)*(m-1);
					}
				}
				break;
			}
		}

		printf("%d\n", can);
	}
	return 0;
}