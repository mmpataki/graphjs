#include "mchart.h"

int main(int argc, char **argv) {

	if(argc < 2) {
		printf("usage %s <maxlimit> <want html> < PIDIGITS\n", argv[0]);
		return 0;
	}

	struct chart *x = new_mchart(
					"/home/mmp/projects/mchartjs/",
					"op.html",
					MCHART_CREGION
				);
	int i = 0, x3, n = atoi(argv[1]);

#define XC (getchar()-'0')

	while(i < n) {
		x3 = XC*10+XC;
		putchar(x3);
		mchart_add_data(x, x3);
		i++;
	}
	if(argv[2])
		mchart_flush(x);
}
