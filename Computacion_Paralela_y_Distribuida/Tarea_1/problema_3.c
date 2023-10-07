#include <stdio.h>
#include <stdlib.h>
#include<time.h>
 
void MultiplyByBlocks(int n, double** a, double** b, double** c)
{
    int jj=0;
    int kk=0;
    int ii=0;
    int i=0;
    int j=0;
    int k=0;
    int B=3; // tamaño del bloque
    printf ("Tamaño del Bloque : ");
    scanf("%d", &B);
    
    
    for (ii = 0; ii < n; ii+=B) {
        for (jj = 0; jj < n; jj+=B) {
            for (kk = 0; kk < n; kk+=B) {
                for (i = 0; i < B; i++) {
                    for (k = 0; k < B; k++) {
                        for (j = 0; j < B; j++) {
                            c[ii+i][jj+j] += a[ii+i][kk+k]*b[kk+k][jj+j];
                            //c[i][j] += a[i][k]*b[k][j];
                        }
                    }
                }
            }
        }
    }

}
 
void MultiplySimple(int n, double** a, double** b, double** c)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void MultiplySimple2(int n, double** a, double** b, double** c)
{
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(void)
{
    int n;
    double** A;
    double** B;
    double** C;
    int numreps = 3;
    int i=0;
    int j=0;
    double elapsed;
    printf ("Dimension de las matrices : ");
    scanf("%d", &n);


    // allocate memory for the matrices     
    //Matrix A
     
    A =(double **)malloc(n*sizeof(double *));
    A[0] = (double *)malloc(n*n*sizeof(double));


    for(i=1; i<n; i++)
    {
        A[i] = A[0]+i*n;
    }
    
    // Matrix B 
 
    B =(double **)malloc(n*sizeof(double *));
    B[0] = (double *)malloc(n*n*sizeof(double));

    for(i=1; i<n; i++)
    {
        B[i] = B[0]+i*n;
    }
    
    // Matrix C 
    C =(double **)malloc(n*sizeof(double *));
    C[0] = (double *)malloc(n*n*sizeof(double));

    for(i=1; i<n; i++)
    {
        C[i] = C[0]+i*n;
    }
    
   
    // initialize the matrices
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            A[i][j] = 5;
            B[i][j] = 10;
        }
    }
 
    //multiply matrices

    struct timespec start, end;
    double time_spent;


    clock_gettime(CLOCK_REALTIME, &start);
    MultiplyByBlocks(n,A,B,C);
    clock_gettime(CLOCK_REALTIME, &end);
    
    time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Elapsed time in seconds of a Multiplication by Blocks: %f \n", time_spent);
     
 
    clock_gettime(CLOCK_REALTIME, &start);
    MultiplySimple(n,A,B,C);
    clock_gettime(CLOCK_REALTIME, &end);
    
    time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Elapsed time in seconds of a Multiplication Simple (i,j,k): %f \n", time_spent);



    clock_gettime(CLOCK_REALTIME, &start);
    MultiplySimple2(n,A,B,C);
    clock_gettime(CLOCK_REALTIME, &end);
    
    time_spent = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    printf("Elapsed time in seconds of a Multiplication Simple (i,k,j): %f \n", time_spent);



    //deallocate memory
     
    free(A[0]);
    free(A);
    free(B[0]);
    free(B);
    free(C[0]);
    free(C);
    return 0;
}