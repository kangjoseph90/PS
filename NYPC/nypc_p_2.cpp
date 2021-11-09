#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 250

void dist_map(int map[NUM][NUM],int path[NUM][NUM])
{
    int count=0;
    do
    {
    
        count=0;
        for(int i=0;i<NUM;i++)
        for(int j=0;j<NUM;j++)
        if(i!=j)
        {
            for(int k=0;k<NUM;k++)
            if(k!=i)
            if(k!=j)
            if(map[i][j]>map[i][k]+map[k][j])
            {
                map[i][j]=map[i][k]+map[k][j];
                path[i][j]=k;
                count++;
            }

        }
    } while (count>0);
}
void path_map(int path[NUM][NUM],int start,int end)
{
    if(path[start][end]==-1)
        printf("=> %d ",end);
    else     
    {
        int k=path[start][end];
        path_map(path,start,k);
        path_map(path,k,end);
    }
}
int random(int limit)
{
    return (rand()%limit);    
}
int main()
{
    srand(time(NULL));
    int map[NUM][NUM];
    int path[NUM][NUM];
    int MM=100000;
    for(int i=0;i<NUM;i++)
    for(int j=0;j<NUM;j++)
    {
        map[i][j]=random(100);
        path[i][j]=-1;
    }
    dist_map(map,path);
    int id_start=2;
    int id_end=24;
    path_map(path,id_start,id_end);

}