/*
Done by:G.Anandaraju
*/
#include<iostream>
using namespace std;
int findLCSLength(string X,string Y)
{
	int M=X.length();
	int N=Y.length();
	//Extra length 1 for initializing zero in first row and col (REFER cormen)
	int dp[M+1][N+1];
	//condition: " <=N "or " < N+1"
	for(int i=0;i<=N;i++)
	{
		dp[i][0]=0;
	}
	for(int i=0;i<=M;i++)
	{
		dp[0][i]=0;
	}
	//Starting from i=1 and j=1 because first row and col already filled
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				//Length from upper diagonal right box + 1
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				//max of Length from upper  box or right box
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[M][N];
}
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	cout<<findLCSLength(a,b)<<endl;
}