#include <stdio.h>
#define row 4
#include <limits.h>
#define col 4

int findPath(int a[][col+2],int rows,int cols)
{
    int mat_dir[4][2]={0,-1,1,0,0,1,-1,0};
    int index,check=0,i,j;
    if(a[1][1]!=0)
        return 0;
    if(rows==col&&cols==col)
        return 1;
    for(index=0;index<col;index++)
    {
        i=rows+mat_dir[index][0];
        j=cols+mat_dir[index][1];
        if(a[i][j]==0)
        {
            a[i][j]=1;
            a[1][1]=0;
            check=check+findPath(a,i,j);
        }
    }
    return check;
}

void wayAmount(int a[][col+2],int rows,int cols,int *times){
    int index=0,i=rows,j=cols;
    int mat_dir[4][2]={0,-1,1,0,0,1,-1,0};
    if(i==4&&j==4){
        (*times)++;
    }
    else{
        a[i][j]=1;
        for(index=0;index<4;index++)
        {
            i=rows+mat_dir[index][0];
            j=cols+mat_dir[index][1];

            if(a[i][j]==0)
            {
                wayAmount(a,i,j,times);
            }
        }
        a[rows][cols]=0;
    }
}


int main()
{
    int a[6][6]={{1,1,1,1,1,1},
                 {1,0,0,1,1,1},
                 {1,1,0,0,1,1},
                 {1,1,0,0,1,1},
                 {1,1,1,0,0,1},
                 {1,1,1,1,1,1}};
    //symetric(an,row,col);
    //perfectArray(c,row,col);
    //sumOfIndex(an,row,col);
    //halfLatin(an,row,col);
    //neighbours(an,b,c);
    int times =0;
    wayAmount(a,1,1,&times);
    printf("%d",times);
    return 0;
}
