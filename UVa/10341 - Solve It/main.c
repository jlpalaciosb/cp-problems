#include <stdio.h>
#include <math.h>

double p, q, r, s, t, u;

double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main() {
	scanf("%lf%lf%lf%lf%lf%lf", &p, &q, &r, &s, &t, &u);
	
	if(f(0) * f(1) > 0) {
		printf("sin solucion");
	} else {
		double a, b, x;
		if(f(0) < 0) {
			a = 0; b = 1;
		} else {
			b = 0; a = 1;
		}
		for(int i = 0; i < 30; i++) {
			x = (a + b) / 2;
			if(f(x) > 0) b = x;
			else a = x;
		}
		printf("%.4f", x);
	}
	return 0;
}
