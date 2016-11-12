#pragma once

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct node_t {
	char node_name[16];
	struct node_t *node_prnt;
	struct node_t **node_chld;
	int node_chld_count;
	int(*action)();
} node_t;

int* menuctrl_state_pass2main();
node_t* node_init(int num_pointers, char* name, node_t* parent, void* action);
node_t* node_menuinit();
void menu_nav(node_t** node_current);