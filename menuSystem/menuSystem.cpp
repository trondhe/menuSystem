#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct node_t {
	char node_name[21];
	struct node_t *node_prnt;
	struct node_t **node_chld;
	int node_chld_count;
} node_t;

node_t* node_init(int num_pointers, char* name, node_t* parent)
{
	node_t* node = (node_t*)malloc(sizeof(node_t));
	if (node == NULL){
		return NULL;
	}
	node->node_chld_count = 0;
	strcpy_s(node->node_name, 21, name);
	node->node_prnt = (node_t*)malloc(sizeof(node_t));
	node->node_prnt = parent;
	node->node_chld = (node_t**)malloc(sizeof(node_t*) * num_pointers);
	for (int i = 0; i < 8; i++){
		node->node_chld[i] = NULL;
	}

	if(parent != NULL){
		parent->node_chld[parent->node_chld_count] = node;
		parent->node_chld_count++;
	}
	return node;
}

void printscreen(char frame[8][21]) {
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 21; i++) {
			printf("%c", frame[j][i]);
		}
		printf("\r\n");
	}
}

int main()
{
	//NODE TEMPLATE
	// 	node_t* node_ = node_init(8, "", &node_);
	
	// MOTHER NODE
	node_t* node_mthr = node_init(8, "Home", NULL);

	// CHILD NODES,	CHILD OF CHILD, ...
	node_t* node_play = node_init(8, "Play", node_mthr);
		node_t* node_easy = node_init(8, "Easy", node_play);
		node_t* node_medi = node_init(8, "Medium", node_play);
		node_t* node_hard = node_init(8, "Hard", node_play);
		node_t* node_uwmt = node_init(8, "U wut m8", node_play);

	node_t* node_sett = node_init(8, "Settings", node_mthr);
		node_t* node_tuni = node_init(8, "Tuning", node_sett);
		node_t* node_dead = node_init(8, "Deadzone", node_sett);

	node_t* node_high = node_init(8, "Highscore", node_mthr);
		node_t* node_trond = node_init(8, "Trond", node_high);
		node_t* node_lars = node_init(8, "Lars", node_high);

	node_t* node_estr = node_init(8, "Easteregg", node_mthr);
		node_t* node_kuk = node_init(8, "Kuk", node_estr);
		node_t* node_i = node_init(8, "i", node_estr);
		node_t* node_kurry = node_init(8, "Curry", node_estr);
		node_t* node_dickbutt = node_init(8, "Dickbutt", node_estr);


	char buffer[8][21];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 21; j++) {
			buffer[i][j] = 32;
		}
	}

	int menuctrl_state = 0;
	int menuctrl = 0;

	node_t* node_current = node_mthr;
	

	while (1) {
		switch (menuctrl) {
		case 119:	//up
			if (menuctrl_state == 0) {
				menuctrl_state = 7;
				break;
			}
			else {
				menuctrl_state -= 1;
			}
			break;

		case 115:	//down
			if (menuctrl_state == 7) {
				menuctrl_state = 0;
				break;
			}
			else {
				menuctrl_state += 1;
			}
			break;

		case 100:	//right
			if ((*node_current).node_chld[menuctrl_state] == NULL) {
				break;
			}
			node_current = (*node_current).node_chld[menuctrl_state];
			break;

		case 97:	//left
			if ((*node_current).node_prnt == NULL) {
				break;
			}
			node_current = (*node_current).node_prnt;
			break;
		}

		for (int i = 0; i < 8; i++) {
			if (i != menuctrl_state)
			{
				buffer[i][0] = 255;
			}
			else {
				buffer[i][0] = 175;
			}
		}



		for (int i = 0; i < node_current->node_chld_count; i++) {
			for (int j = 0; j < strlen(node_current->node_chld[i]->node_name); j++) {
				buffer[i][j+1] = node_current->node_chld[i]->node_name[j];
			}
			for (int j = strlen(node_current->node_chld[i]->node_name); j < 20; j++) {
				buffer[i][j+1] = 32;
			}
		}

		system("cls");
		printscreen(buffer);
		//printf("%i\n", menuctrl);
		//printf("%i", menuctrl_state);
		menuctrl = _getch();


		//itoa()



		//_sleep(100);

	}
	return 0;
}