#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
	int N,b,sg,sb,ng,nb,aux;
	cin >> N;

	for(int i = 0; i < N; i++){
		priority_queue<int> blue, green;
		queue<int> survb, survg;
		scanf("%d %d %d",&b,&sg,&sb);
		nb = ng = 0;
		for(int j = 0; j < sg;j++){
			cin >> aux;
			green.push(aux);
			ng += aux;
		}

		for(int j = 0; j < sb;j++){
			cin >> aux;
			blue.push(aux);
			nb += aux;
		}

		if(nb == ng){
			 cout << "green and blue died" << endl << endl;
			 continue;
		}

		while(!blue.empty() && !green.empty()){
			for (int i = 0; i < b; i++){
				if (blue.empty() || green.empty())
					break;

				int sb = blue.top(), sg = green.top();
				blue.pop(); green.pop();

				if (sb - sg == 0) continue;
				if (sb - sg > 0) survb.push(sb - sg);
				else survg.push(sg - sb);
			}

			while(!survb.empty()){
				blue.push(survb.front());
				survb.pop();
			}

			while(!survg.empty()){
				green.push(survg.front());
				survg.pop();
			}
		}

		if (blue.empty()){
			printf("green wins\n");
			while(!green.empty()){
				printf("%d\n", green.top());
				green.pop();
			}	
		}

		else if (green.empty()){
			printf("blue wins\n");
			while(!blue.empty()){
				printf("%d\n", blue.top());
				blue.pop();
			}
		}
		if (i < N - 1)
			printf("\n");		
	}


	return 0;
}