#include <stdio.h>
#include <time.h>
#include "stdafx.h"

typedef struct {
	int val;
	char** screendata;
	int** node_nxt;
	int* node_pre;
} node_type;

node_type node_main;
//node_main->screendata = { "kuk", "i", "kurry" };
node_main->val = 5;

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
	printf("%d", node_main.val);
	char buffer[8][21];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 21; j++) {
			buffer[i][j] = 219;
		}
	}

	int menuctrl_state = 0;
	int menuctrl_depth = 0;
	int menuctrl = 0;




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