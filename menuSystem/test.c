/*
#include<stdio.h>
#include<conio.h>



typedef struct menu_node {
	int selected;
	struct menu_node *next;
	struct menu_node *previous;
	//char menu_data[8][21];
	char *menu_data[8];
}menu_node;

void print_menu_node(menu_node menu) {
	for (int i = 0; i < 8; i++) {
		printf("%s\r\n", menu.menu_data[i]);
	}
}

static menu_node test_start = { 0, NULL, NULL,{ "test","test","test","test","test","test","test","test" } };
static menu_node test_stop = { 0, NULL, NULL,{ "test2","test2","test2","test2","test2","test2","test2","test2" } };

int main()
{

	test_start.next = &test_stop;

	printf("%p", test_start.next);

	print_menu_node(test_start);
	print_menu_node(*test_start.next);

	while (1);
	return 0;
}*/