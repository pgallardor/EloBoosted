#include <cstdio>
#include <cmath>
#define EPS 1e-6
using namespace std;

double f(double p, double q, double r, double s, double t, double u, double x){
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x*x + u;
}

int main(){
	double p, q, r, s, t, u;
	while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) != EOF){
		double min = 0.0f, max = 1.0f;
		double x = (min + max) / 2;

		double eval = f(p, q, r, s, t, u, x); 

		while (min < max && abs(eval - 0.0f) > EPS){
			if (eval < 0.0f) max = x;
			else if (eval > 0.0f) min = x;
			x = (min + max) / 2;
			eval = f(p, q, r, s, t, u, x);
		}
		if (abs(eval - 0.0f) > EPS) printf("No solution\n");
		else printf("%.4f\n", x);
	}

	return 0;
}