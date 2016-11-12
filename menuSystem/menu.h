#pragma once

typedef struct node_t {
	char* node_name;
	struct node_t *node_parent;
	struct node_t **node_child;
	int node_child_count;
	int(*action)();
} node_t;

int* menuctrl_state_pass2main();
node_t* node_init(int num_childs, char* name, node_t* parent, void* action);
node_t* node_menuinit();
void menu_nav(node_t** node_current);