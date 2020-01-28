/* 
	Done By: G.Anandaraju
 */
 /* 
	The question taken from interview experience in GFG and also found in 500 techdelight
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	int beg=0,index=0;
	for(;index<N;index++)
	{
		if(arr[index]==0)
		{
			arr[beg++]=0;
		}
	}
	for(int i=beg;i<N;i++)
	{
		arr[i]=1;
	}
	//sort(arr,arr+N);
	for(int i=0;i<N;i++)
	{
		cout<<arr[i]<<" ";
	}
}