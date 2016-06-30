#include <stdio.h>
#define MAX 10
void input(int matrix[MAX][MAX], int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
	    scanf("%d", &matrix[i][j]);
}

void print(int matrix[MAX][MAX], int m, int n)
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
	    printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void mproduct(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int m, int p, int q)
{
    int i, j, k;
    for(i = 0; i < m; i++)
        for(j = 0; j < q; j++)
        {
	    C[i][j] = 0;
	    for(k = 0; k < p; k++)
	        C[i][j] += A[i][k] * B[k][j];
        }
}
    

int main()
{
    int m, n, p, q;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    printf("Enter order of first matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter %d elements: \n", m*n);
    input(A, m, n);
    printf("Enter order of second matrix: ");
    scanf("%d %d", &p, &q);

    if(n != p)
    {
        printf("Error: Orders incompatible for multiplication\n");
	return 0;
    }
    printf("Enter %d elements: \n", p*q);
    input(B, p, q);
    printf("\n Matrix product: \n");
    mproduct(A, B, C, m, p, q);
    print(C, m, q);
    return 0;
}




    


