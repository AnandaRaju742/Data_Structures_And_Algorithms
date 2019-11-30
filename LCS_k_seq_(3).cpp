/*
	Done By: G.Anandaraju
*/
#include<iostream>
using namespace std;
int LengthLCS_3(string X,string Y,string Z)
{
	int M=X.length(),N=Y.length(),O=Z.length();
	int lookup[M+1][N+1][O+1];
	for(int i=0;i<=M;i++)
	{
		for(int j=0;j<=N;j++)
		{
			for(int k=0;k<=O;k++)
			{
				if(i==0||j==0||k==0)
				{
					lookup[i][j][k]=0;
				}
				else
				{
					if(X[i-1]==Y[j-1]&&Y[j-1]==Z[k-1])
					{
						lookup[i][j][k]=lookup[i-1][j-1][k-1]+1;
					}
					else
					{
						lookup[i][j][k]=max(lookup[i-1][j][k],max(lookup[i][j-1][k],lookup[i][j][k-1]));
					}	
				}
			}
		}
	}
	return lookup[M][N][O];
}
int main()
{
	string a,b,c;
	getline(cin,a);
	getline(cin,b);
	getline(cin,c);
	cout<<LengthLCS_3(a,b,c)<<endl;
}