#ifndef CSVG_CHART_INCLUDED
#define CSVG_CHART_INCLUDED

#include "sl_list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MCHART_CREGION	"region"
#define MCHART_CBAR	"bar"
#define MCHART_CDOT	"dot"

#define MMPLPATH mchart_js_cpath
char *MMPLPATH = NULL;

struct chart {
	char *bg;
	char *strk;
	char *fill;
	char *type;
	char *opf;
	char *width;
	char *height;
	int ydivs, xdivs;
	struct s_list_head *list;
};

char *newcstr(char *str) {
	char *x = malloc(sizeof(char)*(strlen(str)+1));
	strcpy(x, str);
	return x;
}

struct chart *new_mchart(char *path, char *opf, char *type) {
	if(!MMPLPATH) {
		MMPLPATH = newcstr(path);
	}
	struct chart *x = malloc(sizeof(struct chart));
	x->bg = "transparent";
	x->strk = "#000";
	x->fill = "#de214c";
	x->ydivs = 0;
	x->xdivs = 0;
	x->width = "90%";
	x->height= "90%";
	x->opf = newcstr(opf);
	x->type = newcstr(type);
	x->list = new_s_list_head();
	return x;
}

void mchart_add_data(struct chart *c, double v) {
	if(c == NULL) return;
	double *x = malloc(sizeof(double));
	*x = v;
	s_list_add(c->list, x);
}

void mchart_flush(struct chart *c) {

	FILE *ptr = fopen(c->opf, "w");

	fprintf(
		ptr,
		"<html><head><script src=\"%smchartjs.js\"></script><link href=\"%smchartjs.css\" rel=\"stylesheet\" type=\"text/css\" ></head>",
		MMPLPATH, MMPLPATH
	);
	fprintf(
		ptr,
		"<div class=\"mchart\" style=\'width: %s; height: %s\'",
		c->width, c->height
	);
	fprintf(
		ptr,
		" gdata='{\"background\": \"%s\", \"type\": \"%s\", \"ydivs\": %d, \"xdivs\": %d, \"vgrids\": true, \"hgrids\": true,",
		c->bg, c->type, c->ydivs, c->xdivs
	);
	fprintf(
		ptr,
		" \"datasets\": [{\"fill\": \"%s\", \"data\": [",
		c->fill
	);
	struct s_list_node *node;
	foreach_sl_list(node, c->list) {
		double *d = (double*)node->data;
		fprintf(ptr, "%lf%c", *d, node->next?',':' ');
	}
	fprintf(ptr, "]}]}'></div></html>");
	fflush(ptr);
	fclose(ptr);

	char buf[4096];
	sprintf(buf, "firefox %s", c->opf);
	system(buf);
}

#endif
