#include<stdio.h>
#include <stdbool.h>
int n;
int board[100][100];//limit N to 100


bool isSafe(x,y)
{
	int flag=0,i,j;
 for(i=0;i<n;i++)
 {
   if (board[x][i]==1)
   flag=1;  
 }	
 
  for(i=0;i<n;i++)
 {
   if (board[i][y]==1)
   flag=1;  
 }	
 
 for(i=0;i<n;i++)
 {
 	for(j=0;j<n;j++)
 	{
 		  if((board[i][j] == 1 ) && ((i+j == x+y) || (i-j == x-y))){
                flag=1; 
            }
	 }
 }

 if(flag==1)
 return false;
 
 else 
 return true;
 
}

bool NQueenAlgo(int col)
{
	
	int i,j;
for(i=0;i<n;i++)
 {
 	for(j=0;j<n;j++)
 	{
     printf("%d ",board[i][j]);
	}
	     printf("\n");
 }
	     printf("\n\n");

    if (col >= n) 
        return true; 
  
    for (i = 0; i < n; i++) { 

        if (isSafe(i, col)) { 
            board[i][col] = 1; 
  
            if (NQueenAlgo(col +1)) // why not col++
                return true; 
  

            board[i][col] = 0;  
        } 
    } 

    return false; 
}

int main()
{
	
    int i,j;
	scanf("%d",&n);
		for(i=0;i<n;i++)
 {
 	    for(j=0;j<n;j++)
 	   {
		  board[i][j]=0;
	}
 }
	bool x=NQueenAlgo(0);
		if(x==true)
	{
	printf("YES\n");
	
		for(i=0;i<n;i++)
 {
 	for(j=0;j<n;j++)
 	{
     printf("%d ",board[i][j]);
	}
	     printf("\n");
 }

 }
 else 
 	printf("NO");
}
