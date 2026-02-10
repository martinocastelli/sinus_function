#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "trig_table.h"

double sin_x(double x);

int main(void) {
	FILE *output_file = fopen("output.txt", "w");
	double a,b;
	printf("max value and increment: ");
	scanf("%lf %lf", &a, &b);
	
	
	for(double i = -10.0;i < a;i += b) {
		fprintf(output_file, "%lf, %lf\n", i, sin_x(i));
	}
	
	return 0;
}

double sin_x(double x) {
	int quadrante = 1;
	while(x >= SIN_MIN_DOMAIN) {
		x -= SIN_MIN_DOMAIN;
		if(++quadrante > 4) {
			quadrante = 1;
		}
	}
	while (x < 0) {
		x += SIN_MIN_DOMAIN;
		if(--quadrante < 1) {
			quadrante = 4;
		}
	}
	switch(quadrante) {
		case 1: {
			return SIN_VALUES[(unsigned int)(N_OF_POINT * x / SIN_MIN_DOMAIN)];
		} break;
		case 2: {
			return SIN_VALUES[(unsigned int)(N_OF_POINT * (SIN_MIN_DOMAIN - x) / SIN_MIN_DOMAIN)];
		} break;
		case 3: {
			return -SIN_VALUES[(unsigned int)(N_OF_POINT * x / SIN_MIN_DOMAIN)];
		} break;
		case 4: {
			return -SIN_VALUES[(unsigned int)(N_OF_POINT * (SIN_MIN_DOMAIN - x) / SIN_MIN_DOMAIN)];
		} break;
		default:
			break;
	}
	return -1;
}


