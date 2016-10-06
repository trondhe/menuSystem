#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


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
	typedef struct node_t {
		char** scrndata;
		struct node_t *node_nxt[8];
		struct node_t *node_pre;
	} node_t;

	char* scrndata_mthr[8] = { "Play", "Settings", "Easteregg", "4", "5", "6", "7", "8" };
	char* scrndata_play[8] = { "Normal", "Hard", "u w0t m8", "4", "5", "6", "7", "8" };
	char* scrndata_sett[8] = { "Tuning", "mordi", "deadzone", "balleflass", "bla", "bleh", "bluh", "gaga" };
	char* scrndata_east[8] = { "penis", "i", "anus", "kuk", "i", "kurry", "dick", "butt" };

	node_t node_mthr;
	node_t node_play;
	node_t node_sett;
	node_t node_east;

	node_mthr.node_pre = NULL;
	node_mthr.node_nxt[0] = &node_play;
	node_mthr.node_nxt[1] = &node_sett;
	node_mthr.node_nxt[2] = &node_east;
	
	for (int i = 3; i < 8; i++) {
		node_mthr.node_nxt[i] = NULL;
	}

	node_play.node_pre = &node_mthr;
	node_sett.node_pre = &node_mthr;
	node_east.node_pre = &node_mthr;

	for (int i = 0; i < 8; i++) {
		node_play.node_nxt[i] = NULL;
		node_sett.node_nxt[i] = NULL;
		node_east.node_nxt[i] = NULL;
	}

	node_mthr.scrndata = (char**)malloc(sizeof(char*) * 8);
	node_play.scrndata = (char**)malloc(sizeof(char*) * 8);
	node_sett.scrndata = (char**)malloc(sizeof(char*) * 8);
	node_east.scrndata = (char**)malloc(sizeof(char*) * 8);

	for (int i = 0; i < 8; i++) {
		node_mthr.scrndata[i] = scrndata_mthr[i];
		node_play.scrndata[i] = scrndata_play[i];
		node_sett.scrndata[i] = scrndata_sett[i];
		node_east.scrndata[i] = scrndata_east[i];
	}

	char buffer[8][21];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 21; j++) {
			buffer[i][j] = 32;
		}
	}

	int menuctrl_state = 0;
	int menuctrl = 0;

	node_t* node_current = &node_mthr;


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
			if ((*node_current).node_nxt[menuctrl_state] == NULL) {
				break;
			}
			node_current = (*node_current).node_nxt[menuctrl_state];
			break;

		case 97:	//left
			if ((*node_current).node_pre == NULL) {
				break;
			}
			node_current = (*node_current).node_pre;
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

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < strlen((*node_current).scrndata[i]); j++) {
				buffer[i][j+1] = (*node_current).scrndata[i][j];
			}
			for (int j = strlen((*node_current).scrndata[i]); j < 20; j++) {
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