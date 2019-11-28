#include <bits/stdc++.h>
using namespace std;
int fib[100];
long int fibonacci(int N)
{
	if(fib[N]!=-1)
	{
		return fib[N];
	}
	if(N==0||N==1)
	{
		return N;
	}
	else{
		fib[N]=fibonacci(N-1)+fibonacci(N-2);
		return fib[N];
	}
}
int main()
{
	int N;
	cin>>N;
	memset(fib,-1,sizeof fib);
	cout<<fibonacci(N)<<endl;
}






/*#include <iostream>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int fib[N+1];
	fib[0]=0;
	fib[1]=1;
	for(int i=2;i<=N;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
	}
	cout<<fib[N]<<endl;
}
*/
