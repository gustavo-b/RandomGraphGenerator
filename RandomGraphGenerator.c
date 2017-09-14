
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int Get_Binary(){
	int r;
	return (r % 7) % 2;
}

void Get_Number_Nodes(unsigned long long int *num_nodes){
	printf("Voce deseja um grafo de quantos nos?\n");
	scanf("%llu", &(*num_nodes));
}

void Get_Sparsity(int *sparsity){
	char confirmation;
	printf("Voce deseja uma matriz esparsa? (s/n)\n");
	scanf(" %c", &confirmation);
	if(confirmation == 's' || confirmation == 'S'){
		*sparsity = 1;
	} else if(confirmation == 'n' || confirmation == 'N'){
			*sparsity = 0;
		} else Get_Sparsity(&(*sparsity));
}
/*
void Create_Matrix(int graph[][]){
	int *arr = (int *)malloc(r * c * sizeof(int));
}
*/
int main() {
	unsigned long long int num_nodes;
	int sparsity;
	Get_Number_Nodes(&num_nodes);
	Get_Sparsity(&sparsity);
//	srand((unsigned int)time(NULL));
	printf("%llu %d\n", num_nodes, sparsity);	
	return 0;
}
