#include "menu.h"


static int menuctrl_state = 0;
static int menuctrl_hold = 0;
char menuctrl;

int* menuctrl_state_pass2main() {
	return &menuctrl_state;
}

node_t* node_init(int num_childs, char* name, node_t* parent, void* action)
{
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL) {
		return NULL;
	}

	node->node_name = malloc(sizeof(char) * (strlen(name) + 1));
	strcpy_s(node->node_name, (strlen(name) + 1), name);
	node->node_parent = (node_t*)malloc(sizeof(node_t*));
	node->node_parent = parent;
	node->node_child = (node_t**)malloc(sizeof(node_t*) * num_childs);
	for (int i = 0; i < num_childs; i++) {
		node->node_child[i] = NULL;
	}
	node->node_child_count = 0;
	if (parent != NULL) {
		parent->node_child[parent->node_child_count] = node;
		parent->node_child_count++;
	}
	node->action = action;
	return node;
}


node_t* node_menuinit() {
	//NODE TEMPLATE
	// 	node_t* node_ = node_init(8, "", &node_);

	// MOTHER NODE
	node_t* node_mthr = node_init(8, "Home", NULL, NULL);

	// CHILD NODES,	CHILD OF CHILD, ...
	node_t* node_play = node_init(8, "Play", node_mthr, NULL);
	node_t* node_easy = node_init(8, "Easy", node_play, NULL);
	node_t* node_medi = node_init(8, "Medium", node_play, NULL);
	node_t* node_hard = node_init(8, "Hard", node_play, NULL);
	node_t* node_uwmt = node_init(8, "U wut m8", node_play, NULL);

	node_t* node_sett = node_init(8, "Settings", node_mthr, NULL);
	node_t* node_tuni = node_init(8, "Tuning", node_sett, NULL);
	node_t* node_dead = node_init(8, "Deadzone", node_sett, NULL);

	node_t* node_high = node_init(8, "Highscore", node_mthr, NULL);
	node_t* node_trond = node_init(8, "Trond", node_high, NULL);
	node_t* node_lars = node_init(8, "Lars", node_high, NULL);

	node_t* node_estr = node_init(8, "Easteregg", node_mthr, NULL);
	node_t* node_kuk = node_init(8, "Kuk", node_estr, NULL);
	node_t* node_i = node_init(8, "i", node_estr, NULL);
	node_t* node_kurry = node_init(8, "Curry", node_estr, NULL);
	node_t* node_dickbutt = node_init(8, "Dickbutt", node_estr, NULL);

	return node_mthr;
}

void menu_nav(node_t** node_current) {
	// Menu control
	menuctrl = _getch();

	switch (menuctrl) {
		case 119:	// Menu control direction: UP
			if ((**node_current).node_child_count == 0) {
				break;
			}
			else if (menuctrl_state == 0) {
				menuctrl_state = ((**node_current).node_child_count - 1);
				menuctrl_hold = 1;
				break;
			}
			else {
				menuctrl_state -= 1;
				menuctrl_hold = 1;
			}
			break;

		case 115:	// Menu control direction: DOWN
			if ((**node_current).node_child_count == 0) {
				break;
			}
			else if (menuctrl_state == ((**node_current).node_child_count - 1)) {
				menuctrl_state = 0;
				menuctrl_hold = 1;
				break;
			}
			else {
				menuctrl_state += 1;
				menuctrl_hold = 1;
			}
			break;

		case 100:	// Menu control direction: RIGHT
			if ((**node_current).node_child[menuctrl_state]->node_child_count == 0) {
				if ((**node_current).node_child[menuctrl_state]->action == NULL) {
					break;
				}
				(**node_current).node_child[menuctrl_state]->action();
				menuctrl_hold = 1;
				break;
			}
			*node_current = (**node_current).node_child[menuctrl_state];
			menuctrl_hold = 1;
			menuctrl_state = 0;
			break;

		case 97:	// Menu control direction: LEFT
			if ((**node_current).node_parent == NULL) {
				menuctrl_hold = 1;
				break;
			}
			*node_current = (**node_current).node_parent;
			menuctrl_hold = 1;
			menuctrl_state = 0;
			break;
	}
	
}