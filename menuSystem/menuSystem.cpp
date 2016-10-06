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
		struct node_t *node_nxt;
		struct node_t *node_pre;
	} node_t;

	char* scrndata_hved[8] = { "Play", "Highscore", "Settings", "Easteregg", "test", "6", "7", "8" };
	char* scrndata_play[8] = { "Normal", "Hard", "u w0t m8", "4", "5", "6", "7", "8" };
	char* scrndata_sett[8] = { "Tuning", "", "Settings", "Easteregg", "test", "6", "7", "8" };
	char* scrndata_east[8] = { "Play", "Highscore", "Settings", "Easteregg", "test", "6", "7", "8" };

	node_t node_hved;
	node_t node_play;
	node_t node_sett;
	node_t node_east;

	node_hved.node_pre = NULL;
	node_hved.node_nxt = &node_play;
	//node_hved.node_nxt[1] = &node_sett;
	//node_hved.node_nxt[2] = &node_east;

	node_play.node_pre = &node_hved;
	node_sett.node_pre = &node_hved;
	node_east.node_pre = &node_hved;

	node_play.node_nxt = NULL;
	node_sett.node_nxt = NULL;
	node_east.node_nxt = NULL;

	node_hved.scrndata = (char**)malloc(sizeof(char*) * 8);
	node_play.scrndata = (char**)malloc(sizeof(char*) * 8);
	node_sett.scrndata = (char**)malloc(sizeof(char*) * 8);
	node_east.scrndata = (char**)malloc(sizeof(char*) * 8);

	for (int i = 0; i < 8; i++) {
		node_hved.scrndata[i] = scrndata_hved[i];
		node_play.scrndata[i] = scrndata_play[i];
		node_sett.scrndata[i] = scrndata_sett[i];
		node_east.scrndata[i] = scrndata_east[i];
	}


	char buffer[8][21];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 21; j++) {
			buffer[i][j] = 219;
		}
	}

	int menuctrl_state = 0;
	int menuctrl = 0;

	node_t* node_current = &node_hved;



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
			//entermenu();
			break;

		case 97:	//left
			//backmenu();
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
		}

		system("cls");
		printscreen(buffer);
		printf("%i\n", menuctrl);
		printf("%i", menuctrl_state);
		menuctrl = _getch();


		//itoa()



		//_sleep(100);

	}
	return 0;
}