#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "menu.h"


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
	node_t* node_current = node_menuinit();
	char** buffer = screenbuffer_init();
	
	while (1) {

	
		menu_nav(node_current, buffer);

		for (int i = 0; i < node_current->node_chld_count; i++) {
			for (int j = 0; j < strlen(node_current->node_chld[i]->node_name); j++) {
				buffer[i][j + 1] = node_current->node_chld[i]->node_name[j];
			}
			for (int j = strlen(node_current->node_chld[i]->node_name); j < 20; j++) {
				buffer[i][j + 1] = 32;
			}
		}

		system("cls");
		printscreen(buffer);
		//printf("%i\n", menuctrl);
		//printf("%i", menuctrl_state);
		
		//itoa()
		//_sleep(100);
	}
	return 0;
}