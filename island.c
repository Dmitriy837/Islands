/*
*In this project all we going to do is to fill randomly the field of NxM integers wth 0 and 1,
*and then count how many islands there are, in assumption that
*1 means land and 0 means water.
*/
#include <stdio.h>
#include <time.h>
#define N 5
#define M 4


int field[N][M],visited[N][M];

int main(){
  srand(time(NULL));

  int i,j;
  for(i=0;i<N;++i){
    for(j=0;j<M;++j){
      field[i][j]=rand()%2;
      visited[i][j] = 0;
      printf("%c",field[i][j]?'1':' ');
    }
    printf("\n");
  }

  int count=0;
  for(i=0;i<N;++i)
    for(j=0;j<M;++j){
      count+=check(i,j);
   }

  printf("There are %d islands!\n",count);
}

int check(int x,int y){
  if(visited[x][y]==1)return 0;
  visited[x][y] = 1;
  if(field[x][y]==0)return 0;
//If we are on the ground, let's take a look around, and if somewhere near
//is groung too, we count it as a one island, so we should lost all returned values 
//from next calls of check(int,int) function bellow
  if(x>0)check(x-1,y);
  if(x<N-1)check(x+1,y);
  if(y<M-1)check(x,y+1);
  if(y>0)check(x,y-1);
  return 1;
}

