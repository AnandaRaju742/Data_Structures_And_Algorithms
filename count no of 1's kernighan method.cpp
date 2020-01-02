#include<bits/stdc++.h>
using namespace std;
int countSBits(int N)
{
	int count=0;
	while(N!=0)
	{
		N=N&(N-1);
		count++;
	}
	return count;
}
int main()
{
	int N;
	cin>>N;
	cout<<"No of set bits is "<<countSBits(N)<<"\n";
}