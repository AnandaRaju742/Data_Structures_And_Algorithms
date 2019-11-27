/*
Done by: G.Anandaraju
*/
#include <bits/stdc++.h>
using namespace std;
const int N=8;
//row denotes current row

bool isSafe(char mat[][N],int row,int col)
{
	//check for col safe
	for(int i=0;i<N;i++)
	{
		if(mat[i][col]=='Q')
			return false;
	}
	//check for left diagonal 
	for(int r=row,c=col;r>=0&&c>=0;r--,c--)
	{
		if(mat[r][c]=='Q')
			return false;
	}
	//check for right diagonal
	for(int r=row,c=col;r>=0&&c<N;r--,c++)
	{
		if(mat[r][c]=='Q')
			return false;
	}
	//no need to check for row safe because of next statement to this function call ---  1
	return true;
}
void print_n_queens(char mat[][N],int row)
{
	if(row==N)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cout<<mat[i][j]<<" ";
			}
			cout<<"\n";
		}
		cout<<"\n";
		return ;
	}
	for(int i=0;i<N;i++)
	{
		if(isSafe(mat,row,i))
		{
			mat[row][i]='Q';
			print_n_queens(mat,row+1);
			////   1 ----------  this is the reason for 
			////				not checking for row safe because after keeping queen in that row,
			////				we move the current row to next and after all combinations completed(on return) we take the queen from that place.
			/////					so this place is the backtrack place ie., starting to explore other possiblities wheater postive or not.
			mat[row][i]='-';
		}
	}
}
int main()
{
//	cin>>::N;
	char chess[N][N];
	if(N==2||N==3)
	{
			cout<<"Not possible"<<"\n";
			return 1;
	}
	else{
		memset(chess,'-',sizeof chess);
	print_n_queens(chess,0);
	}
}
