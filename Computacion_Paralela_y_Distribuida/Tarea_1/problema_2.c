#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int main(int argc, char** argv){
	int m,n,f,c,i,j,k,MAX;


	printf("\nIngrese el tamaño de los arrays\n");
	scanf("%d",&MAX);
	
	double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

	printf("\nIngrese la fila y columna de la primera matriz\n");
	scanf("%d",&m);
	scanf("%d",&n);

	printf("\nIngrese la fila y columna de la primera matriz\n");
	scanf("%d",&f);
	scanf("%d",&c);

	srand((unsigned int) time(NULL));
	double range = 10.0;

	if(n == f){

		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				A[i][j] = ((double) rand()/ RAND_MAX) * range;
			}
		}
		printf("\nPrimera matriz creada\n");

		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{
				B[i][j] = ((double) rand()/ RAND_MAX) * range;
			}
		}
		
		printf("\nSegunda matriz creada\n");
		
		for ( i = 0; i < m; i++)
		{
			for (j = 0; j < c; j++)
			{
				C[i][j] = 0;
				for (k = 0; k < m; k++)
				{
					C[i][j] += A[i][k] * B[k][j];
				}
			}
		}

		printf("\nImprimiendo :\n\n");

		//IMPRESION

		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{ 
				printf("%f ",A[i][j]);
			}
			printf("\n");
		}

		printf("\n");

		for (i=0;i<m;i++)
		{
			for (j=0;j<n;j++)
			{ 
				printf("%f ",B[i][j]);
			}
			printf("\n");
		}

		printf("\nMultiplicacion de matrices\n");
		

		for (i=0;i<m;i++)
		{
			for (j=0;j<c;j++)
			{ 
				printf("%f ",C[i][j]);
			}
			printf("\n");
		}

	}
	return 0;
}
