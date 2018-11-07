#include <iostream>
#include <cstdio>

using namespace std;


int main(){
	int N,b,sg,sb,ng,nb,aux;
	cin >> N;

	for(int i = 0; i < N; i++){
		scanf("%d %d %d",&b,&sg,&sb);
		nb = ng = 0;
		for(int j = 0; j < sg;j++){
			cin >> aux;
			ng += aux;
		}

		for(int j = 0; j < sb;j++){
			cin >> aux;
			nb += aux;
		}

		if(nb == ng){
			 cout << "green and blue died" << endl;
			 continue;
		}

		if(nb > ng){
			 cout << "blue wins" << endl;
			 continue;
		}
		else{
			 cout << "green wins" << endl;
			 continue;
		}		
	}


	return 0;
}