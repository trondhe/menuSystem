#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "menu.h"
#include "screen.h"

int main()
{	
	// -------- Menu and screen --------
	node_t* node_current = node_menuinit();
	char** buffer = screenbuffer_init();
	int* menuctrl_state = menuctrl_state_pass2main();
	

	// -------- System loop --------
	while (1) {
		menu_nav(&node_current);
		buffer_writemenu(buffer, &node_current, menuctrl_state);
		system("cls");
		print2cmd(buffer);
	}
	return 0;
}