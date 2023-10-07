#include <stdio.h>
#include <stdlib.h>  
#include <time.h> 


int main(int argc, char** argv[]){

    //time_t t1;
    //srand((unsigned) time(&t1));
    srand((unsigned int) time(NULL));  
    int MAX = atoi(argv[1]);
    //printf("%d",MAX);

    double A[MAX][MAX];

    double x[MAX];
    double y[MAX];
    int i ,j;
    double range = 5.0;

    for (i = 0; i < MAX; i++ ) {
        for (j = 0; j < MAX; j++ ) {
            A[i][j] =  ((double) rand()/ RAND_MAX) * range;
        }
    }

    for (i = 0; i < MAX; i++)
    {
        x[i] = ((double) rand()/ RAND_MAX) * range;
    }
    
    // print values of A
    // printf("A: \n");
    // for (i = 0; i < MAX; i++ ) {

    //   for (int j = 0; j < MAX; j++ ) {
    //     //printf("A[%d][%d] = %f", i,j, A[i][j]);
    //     printf("%f ",A[i][j]);
    //   }
    //   printf("\n");
    // }
    // printf("\n");
    
    // // print values of x
    // printf("x: \n");
    // for (i = 0; i < MAX; i++)
    // {
    //     printf("%f ",x[i]);
    // }
    printf("\n\n");

    /* First pair of loops */
    clock_t start = clock();
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            y[i] += A[i][j] * x[j];
        }
    }
    clock_t stop = clock();


    // printf("y: \n");
    // for (int h = 0; h < MAX; h++ ) {
    //     printf("y[%d] = %f ",h,y[h]);
    // }

    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f\n\n", elapsed);
    
    /* Assign y = 0 */
    
    for ( i = 0; i < MAX; i++)
    {
        y[i] = 0;
    }

    /* Second pair of loops */
    
    clock_t start1 = clock();
    for (j = 0; j < MAX; j++)
    {
        for (i = 0; i < MAX; i++)
        {
            y[i] += A[i][j]*x[j];
        }   
    }
    clock_t stop1 = clock();

    // printf("y: \n");
    // for (int h = 0; h < MAX; h++ ) {
    //     printf("y[%d] = %f ",h,y[h]);
    // }
    
    elapsed = (double)(stop1 - start1) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f\n\n", elapsed);

    return 0;
}
