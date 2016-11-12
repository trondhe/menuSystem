#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print2cmd(char** frame);
char** screenbuffer_init();
void buffer_writemenu(char** buffer, node_t** node_current, int* menuctrl_state);
void buffer_writegame(char** buffer);
