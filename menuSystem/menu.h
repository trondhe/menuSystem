#pragma once

typedef struct node_t {
	char node_name[21];
	struct node_t *node_prnt;
	struct node_t **node_chld;
	int node_chld_count;
} node_t;

char** screenbuffer_init();
node_t* node_init(int num_pointers, char* name, node_t* parent);
node_t* node_menuinit();
void menu_nav(node_t** node_current, char** buffer);