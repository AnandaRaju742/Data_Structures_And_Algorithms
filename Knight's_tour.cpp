#include<bits/stdc++.h>
using namespace std;
bool isSafe(int x,int y,int N)
{
	if(x<0||y<0||x>=N||y>=N)
		return false;
	return true;
}
void knightTour(int arr[8][8],int i, int j, int PosNo,int N)
{
	arr[i][j]=PosNo;
	if(PosNo==64)
	{
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<"\n";
		}
		PosNo=1;
		cout<<"\n";
		return;
	}
	if(isSafe(i-2,j-1,N)&&!arr[i-2][j-1])
	{
		knightTour(arr,i-2,j-1,PosNo+1,N);
		arr[i-2][j-1]=0;
	}
	if(isSafe(i-1,j-2,N)&&!arr[i-1][j-2])
	{
		
		knightTour(arr,i-1,j-2,PosNo+1,N);
		arr[i-1][j-2]=0;
	}
	if(isSafe(i+1,j-2,N)&&!arr[i+1][j-2])
	{
		
		knightTour(arr,i+1,j-2,PosNo+1,N);
		arr[i+1][j-2]=0;
	}
	if(isSafe(i+2,j-1,N)&&!arr[i+2][j-1])
	{
		
		knightTour(arr,i+2,j-1,PosNo+1,N);
		arr[i+2][j-1]=0;
	}
	if(isSafe(i+2,j+1,N)&&!arr[i+2][j+1])
	{
		
		knightTour(arr,i+2,j+1,PosNo+1,N);
		arr[i+2][j+1]=0;
	}
	if(isSafe(i+1,j+2,N)&&!arr[i+1][j+2])
	{
		
		knightTour(arr,i+1,j+2,PosNo+1,N);
		arr[i+1][j+2]=0;
	}
	if(isSafe(i-1,j+2,N)&&!arr[i-1][j+2])
	{
		
		knightTour(arr,i-1,j+2,PosNo+1,N);
		arr[i-1][j+2]=0;
	}
	if(isSafe(i-2,j+1,N)&&!arr[i-2][j+1])
	{
		
		knightTour(arr,i-2,j+1,PosNo+1,N);
		arr[i-2][j+1]=0;
	}
}	
int main()
{
	int N=8;
	int arr[8][8];
	memset(arr,0,sizeof(arr));
	knightTour(arr,0,0,1,N); //array then position 1 denotes the first position and size of board
}
