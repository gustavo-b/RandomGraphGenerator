#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int Get_Binary(float sparsity){
	int r = rand();
	return ((int)pow(r, sparsity)) % 2;
}

void Get_Number_Nodes(int *num_nodes){
	printf("Voce deseja um grafo de quantos nos?\n");
	scanf("%d", &(*num_nodes));
}

int* Fill_Matrix(int num_nodes, float sparsity){
	int i, j;
	int *arr = malloc(num_nodes * num_nodes * sizeof(int));
	for(i = 0; i < num_nodes; i++){
		for(j = 0; j < num_nodes; j++){
			arr[(i * num_nodes) + j] = Get_Binary(sparsity);
		}
	}
	return arr;
}

int* Create_Matrix(int num_nodes){
    return malloc(num_nodes * num_nodes * sizeof(int));
}

void Show_Matrix(int *graph, int num_nodes){
	int i, j;
	for(i = 0; i < num_nodes; i++){
        for(j = 0; j < num_nodes; j++){
			printf("%d ", graph[(i * num_nodes) + j]);
        }
        printf("\n");
    }
}

void Get_Sparsity(float *sparsity){
	char confirmation;
	printf("Voce deseja uma matriz esparsa? (s/n)\n");
	scanf(" %c", &confirmation);
	if(confirmation == 's' || confirmation == 'S'){ //Uses linked list
		*sparsity = 0.8;
	} else if(confirmation == 'n' || confirmation == 'N'){ //Uses 2d array
			*sparsity = 0.1;
		} else Get_Sparsity(&(*sparsity));
}

int main() {
	int num_nodes;
	float sparsity;
	int *graph = NULL;
	Get_Number_Nodes(&num_nodes);
	Get_Sparsity(&sparsity);
	graph = Create_Matrix(num_nodes);
    graph = Fill_Matrix(num_nodes, sparsity);
//	Create_Structure(sparsity);
	srand((unsigned int)time(NULL));
	printf("%d %f\n", num_nodes, sparsity);
	Show_Matrix(graph, num_nodes);
	return 0;
}
