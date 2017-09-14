
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int Get_Binary(int sparsity){
	int r;
	return ((int)pow((r % 7), sparsity)) % 2;
}

void Get_Number_Nodes(int *num_nodes){
	printf("Voce deseja um grafo de quantos nos?\n");
	scanf("%d", &(*num_nodes));
}

void Fill_Matrix(int *graph, int num_nodes, int sparsity){
	int i, j;
	for(i = 0; i < num_nodes; i++){
		for(j = 0; j < num_nodes; j++){
			*(graph + (i * num_nodes) + j) = 8;//Get_Binary(sparsity);
		}
	}
}

void Show_Matrix(int *graph, int num_nodes);

void Create_Matrix(int *graph, int num_nodes, int sparsity){
	graph = (int*)malloc(num_nodes * num_nodes * sizeof(int));
	if(graph == NULL) printf("fufufufuf\n");
	Show_Matrix(&(*graph), num_nodes);
	Fill_Matrix(&(*graph), num_nodes, sparsity);
}

void Show_Matrix(int *graph, int num_nodes){
	int i, j;
	for(i = 0; i < num_nodes; i++){
                for(j = 0; j < num_nodes; j++){
			printf("%d\n", *(graph + (i * num_nodes) + j));
                }
        }
}

void Get_Sparsity(int *sparsity){
	char confirmation;
	printf("Voce deseja uma matriz esparsa? (s/n)\n");
	scanf(" %c", &confirmation);
	if(confirmation == 's' || confirmation == 'S'){ //Uses linked list
		*sparsity = 2;
	} else if(confirmation == 'n' || confirmation == 'N'){ //Uses 2d array
			*sparsity = 1;
		} else Get_Sparsity(&(*sparsity));
}

int main() {
	int num_nodes;
	int sparsity;
	int *graph;
	Get_Number_Nodes(&num_nodes);
	Get_Sparsity(&sparsity);
	Create_Matrix(&(*graph), num_nodes, sparsity);
//	Create_Structure(sparsity);
	srand((unsigned int)time(NULL));
	printf("%d %d\n", num_nodes, sparsity);
	Show_Matrix(&(*graph), num_nodes);
	return 0;
}
