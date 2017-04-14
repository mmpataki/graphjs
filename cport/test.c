#include "mchart.h"

int main(int argc, char **argv) {

	if(argc < 3) {
		printf("usage %s <seed> <maxlimit>\n", argv[0]);
		return 0;
	}

	struct chart *x = new_mchart(
					"/home/mmp/projects/mchartjs/",
					"op.html",
					MCHART_CDOT
				);
	int i = 0, x3 = atoi(argv[1]), n = atoi(argv[2]);
	while(i < n) {
		x3 = (x3 & 1) ? (3 * x3 + 1) : (x3 >> 1);
		mchart_add_data(x, x3);
		i++;
	}
	mchart_flush(x);
}
