#include <bits/stdc++.h>
using namespace std;
int josepheus(int n,int k)
{
	//trick to remember
	//to find remainder (remaining persons) in k by n we do k%n
	//here our results based on prev result "res" so (res+k)%n
	int res=0;
	for(int i=0;i<=n;i++)
		res=(res+k)%n;
	return res+1;
}
int main()
{
	int k,n;
	cin>>n>>k;
	cout<<josepheus(n,k);
}
