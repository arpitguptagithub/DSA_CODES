#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<bool>>> t; //table
int n,b,k ; //total size, sub part size, no. of sub parts


int lsb( int num)
{
    int c=0;
    int p = num&1;
    while((p == 0)&& c < 32)
    { num = num >>1; 
      p= num & 1;
      c++ ;
    }
    
    if( c == 32)
     return 0;
    return c;
}


int b_d(vector<vector<int>> &cc, int b, int start , int n )
{ 
	int sz = cc.size();
    int s =0;
    for( int i = start+ b -1; i>=start ; i--)
    {
		if (i < sz)
     s= s*2 + cc[i][n];
     
     else
        s = s * 2 + 0;
     }
    return s;}

void table ( int n, int b, int k, vector<vector<int>> &a ,vector<vector<vector<bool>>> &t)
{
int r= int(pow(2,b)); //2 pow b
t.resize(k,vector<vector<bool>>(r, vector<bool>(n)));

    for (int j = 0; j < k; j++)
    {   for (int i = 0; i < n; i++)
          t[j][0][i] = 0;
        
        for (int l = 1; l < r; l++)
        {  int q = lsb(l);
            int l1 = l & (~(1 << q));

            for (int i = 0; i < n; i++)
            { t[j][l][i] = t[j][l1][i] | a[i][(q + j * b)];
                
            } } }
}


void print_v ( vector<vector <int>> &cc)
   { for (vector<int> i : cc)
    { for (int j : i)
          { cout <<j<< " ";}
        
        cout << endl;
       }
    }


int main()
{
    cin >> n; 
    vector<vector<int>> cx(n, vector<int>(n));
    vector<vector<int>> cy(n, vector<int>(n));
    vector<vector<int>> cc(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
  {        for (int j = 0; j < n; j++)
     {       cin >> cx[i][j];}
   }     
    for (int i = 0; i < n; i++)
     {for (int j = 0; j < n; j++)
            cin >> cy[i][j];
      }
   
   int b = int(ceil(log2(n)));
    k = int (ceil(n /float (b)));  // number of subgroups    
    //length of subgroup


    table(n, b, k, cx, t); // table formin 
    int r = int(pow(2, b)); //rows


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        { int d = b_d(cy, b, j * b, i);
            for (int h = 0; h < n; h++)
            {   cc[h][i] |= t[j][d][h]; 
            //cout <<cc[h][i];
            }
        }
    }

print_v( cc);


}
