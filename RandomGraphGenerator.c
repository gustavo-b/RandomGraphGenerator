#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
/*
int nodes;
int graph_matrix[nodes][nodes];
*/
int Get_Binary(){
	int r;
	return (r % 7) % 2;
}

int main() {
	srand((unsigned int)time(NULL));
	printf("%d\n", Get_Binary());	
	return 0;
}
