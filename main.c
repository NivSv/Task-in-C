#include <stdio.h>
#define size 10

int HolesCount(int mat[size][size]); //Count the holes in the marix
void Copy (int new[size][size],int old[size][size]); //Copying the matrix
void Print (int mat[size][size]); //Printing the matrix
void Bomb (int mat[size][size],int row,int colum); //Recursive function to delete the holes you find :)

int main()
{
    int count;
    int mat[size][size] = {
    {1,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,0,0},
    {0,0,1,1,0,0,0,1,1,1},
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0}};
    
    count = HolesCount(mat);
    Print(mat);
    
    printf("\nThe count of the holes is: %i", count);
    return 0;
}


int HolesCount(int mat[size][size]) //Count the holes in the marix
{
    int temp[size][size];
    Copy(temp,mat);
    int count=0;
    
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            if(temp[i][j] == 1)
            {
                Bomb(temp,i,j);
                count++;
            }
        }
    }
    return count;
}

void Print (int mat[size][size]) //Printing the matrix
{
    printf ("You entered: \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%i ", mat[i][j]);
        }
        printf("\n");
    } 
}

void Copy (int new[size][size],int old[size][size]) //Copying the matrix
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            new[i][j]=old[i][j];
        }
    }
}

void Bomb (int mat[size][size],int row,int colum) //Recursive function to delete the holes you find :)
{
	mat[row][colum]=0;
	if(row!=0)
	{
		if(mat[row-1][colum] == 1)
		{
			Bomb(mat,row-1,colum);
		}
	}
	else if(row!=size)
	{
		if(mat[row+1][colum] == 1)
		{
			Bomb(mat,row+1,colum);
		}
	}
	if(colum!=0)
	{
		if(mat[row][colum-1] == 1)
		{
			Bomb(mat,row,colum-1);
		}
	}
	else if(colum!=size-1)
	{
		if(mat[row][colum+1] == 1)
		{
			Bomb(mat,row,colum+1);
		}
	}
}
