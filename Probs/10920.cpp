#include <cstdio>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int main(){
	int N, k;
	while(scanf("%d %d", &N, &k) != EOF && (N || k)){
		int x = (N + 1)/2, y = (N + 1)/2;
		int step = 0, dir = UP, num = 1;

		while (num <= k){
			printf("(%d, %d), step: %d, dir = %d\n", y, x, step, dir);
			if (num == k){
				printf("Line = %d, column = %d\n", y, x);
				break;
			}

			if (num < k && num + step > k){
				int d = k - num;
				if (dir == UP) y += d;
				if (dir == DOWN) y -= d;
				if (dir == LEFT) x -= d;
				if (dir == RIGHT) x += d;

				printf("Line = %d, column = %d\n", y, x);
				break;
			}

			if (dir == UP){
				step++;
				y += step;
				num += step;
				dir = LEFT;
			}

			if (dir == LEFT){
				x -= step;
				num += step;
				dir = DOWN;
				step++;
			}

			if (dir == DOWN){
				step++;
				y -= step;
				num += step;
				dir = RIGHT;
			}

			if (dir == RIGHT){
				x += step;
				num += step;
				dir = UP;
			}
			
		}
	}

	return 0;
}