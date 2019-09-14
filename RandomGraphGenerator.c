#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	int pass;
	struct elem *next;
}node;

int Get_Binary(float sparsity) {
	int randomNumber = rand();
	if(randomNumber < RAND_MAX * sparsity) {
        	return 1;
	} else {
        	return 0;
	}
}

void Create_List (node **list) {
	*list = malloc (sizeof(node));
	(*list)->next = NULL;
}

void Get_Number_Nodes(int *num_nodes) {
	printf("Voce deseja um grafo de quantos nos?\n");
	scanf("%d", &(*num_nodes));
}

void Fill_Matrix(int **graph, int num_nodes, float sparsity) {
	int i, j;
	int *arr = *graph;
	for(i = 0; i < num_nodes; i++) {
		for(j = 0; j < num_nodes; j++) {
			arr[(i * num_nodes) + j] = Get_Binary(sparsity);
		}
	}
	*graph = arr;
}

void Create_Matrix(int **graph, int num_nodes) {
    int *array = malloc(num_nodes * num_nodes * sizeof(int));
    *graph = array;
}

void Show_Matrix(int *graph, int num_nodes) {
	int i, j;
	
	for(i = 0; i < num_nodes; i++) {
        	for(j = 0; j < num_nodes; j++) {
			printf("%d ", graph[(i * num_nodes) + j]);
        	}	
        	printf("\n");
    	}
}

void Get_Sparsity(float *sparsity) {
	char confirmation;
	
	printf("Voce deseja uma matriz esparsa? (s/n)\n");
	scanf(" %c", &confirmation);
	
	if(confirmation == 's' || confirmation == 'S') {
		*sparsity = 0.3;
	} else if(confirmation == 'n' || confirmation == 'N') {
		*sparsity = 0.8;
	} else {
		Get_Sparsity(&(*sparsity));
	}
}

int main() {
	srand((unsigned int)time(NULL));
	
	int num_nodes;
	float sparsity;
	int *graph = NULL;
	
	Get_Number_Nodes(&num_nodes);
	Get_Sparsity(&sparsity);
	Create_Matrix(&graph, num_nodes);
	Fill_Matrix(&graph, num_nodes, sparsity);
	
	printf("%d %f\n", num_nodes, sparsity);
	Show_Matrix(graph, num_nodes);
	
	return 0;
}
