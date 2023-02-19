#include <bits/stdc++.h>
#define N 8

//can be taken via string also 
using namespace std;
int board[N][N];



int row[] = {2, 2, -2, -2, -1, -1, 1, 1};
int cln[]=   { -1, 1, -1, 1, 2, -2, 2, -2};

bool issafe(int r,int c)
{
    return (r>=0 && c>=0 && r<N && c<N && board[r][c] == -1);
}

bool MOVES(int r,int c,int pos)
{
  
    if(pos == N*N)
        return true; 
    
    int pos_x=0, pos_y=0;
    
    
    
for ( int i =0 ; i < N ; i++)
  {
	  pos_x = r + row[i];
	  pos_y = c + cln[i];
	  
	  
	  // change it accordingly 
	  
	  for( int i = 0 ; i< n ; i++)
	  {
		  pos_x = min();
		  pos_y = min();
		  }
		  
	  if(issafe( pos_x, pos_y))
	  {
		  board[pos_x][pos_y] = pos+1;
		  if( MOVES(pos_x, pos_y, pos+1) == 1)
		   return true ;
		  else
		    board [pos_x] [pos_y]= -1; 
	  }
	  
} 


return false;}
int main() {
    
    memset(board,-1,sizeof(board));
    board[0][0] = 1;
    if(MOVES(0,0,1)){
        for(int i = 0;i<N;i++)
        {
            for(int j = 0;j<N;j++)
                cout<<board[i][j]<<"  ";
            cout<<endl;
        }
    }
    else cout<<"try different board ";
    return 0;
}
