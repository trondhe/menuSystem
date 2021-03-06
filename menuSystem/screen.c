#include "screen.h"


void print2cmd(char** frame) {
	system("cls");
	for (int j = 0; j < SCREENBUFFER_HEIGHT; j++) {
		for (int i = 0; i < SCREENBUFFER_WIDTH; i++) {
			printf("%c", frame[j][i]);
		}
		printf("\r\n");
	}
}

char** screenbuffer_init() {
	char** buffer = (char**)malloc(sizeof(char*) * SCREENBUFFER_HEIGHT);
	if (buffer == NULL) {
		printf("buffer** not allocated\n");
		return NULL;
	}
	for (int i = 0; i < SCREENBUFFER_HEIGHT; i++) {
		buffer[i] = malloc(sizeof(char) * SCREENBUFFER_WIDTH);
		if (buffer[i] == NULL) {
			printf("buffer[%d] not allocated\n",i);
			return NULL;
		}
	}
	for (int i = 0; i < SCREENBUFFER_HEIGHT; i++) {
		for (int j = 0; j < SCREENBUFFER_WIDTH; j++) {
			buffer[i][j] = 32;
		}
	}
	return buffer;
}


void buffer_writemenu(char** buffer, node_t** node_current, int* menuctrl_state){
	
	// Screen clear
	for (int i = 0; i < SCREENBUFFER_HEIGHT; i++) {
		for (int j = 0; j < SCREENBUFFER_WIDTH; j++) {
			buffer[i][j] = 32;
		}
	}
	
	// Write current node on top
	int node_name_len = strlen((**node_current).node_name);
	int buffer_space_remaining = SCREENBUFFER_WIDTH - node_name_len;
	int buffer_space_remhalf = buffer_space_remaining / 2;
	int buffer_space_modulo = buffer_space_remaining % 2;

	for(int i = 0; i < buffer_space_remhalf; i++){
		buffer[0][i] = 61;
	}
	for(int i = buffer_space_remhalf; i < buffer_space_remhalf+node_name_len; i++){
		buffer[0][i] = (**node_current).node_name[i-buffer_space_remhalf];
	}
	for(int i = buffer_space_remhalf+node_name_len+buffer_space_modulo; i < SCREENBUFFER_WIDTH; i++){
		buffer[0][i] = 61;
	}

	// Write child nodes
	for (int i = 0; i < (**node_current).node_child_count; i++) {
		for (int j = 0; j < strlen((**node_current).node_child[i]->node_name); j++) {
			buffer[i+1][j+1] = (**node_current).node_child[i]->node_name[j];
		}
		for (int j = strlen((**node_current).node_child[i]->node_name); j < SCREENBUFFER_WIDTH; j++) {
			buffer[i+1][j+1] = 32;
		}
	}

	// Write guide arrow
	for (int i = 1; i < SCREENBUFFER_HEIGHT; i++) {
		if (i == *menuctrl_state + 1)
		{
			buffer[i][0] = 45;
		}
		else {
			buffer[i][0] = 32;
		}
	}
}

void buffer_writegame(char** buffer){
	for (int i = 0; i < SCREENBUFFER_HEIGHT; i++) {
		for (int j = 0; j < SCREENBUFFER_WIDTH; j++) {
			buffer[i][j] = 35;
		}
	}
}