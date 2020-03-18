#include<bits/stdc++.h>
using namespace std;
int binarySearch(int arr[],int low,int high,int x)
{
	if(low>high)
		return -1;
	int mid=(low+high)/2;
	if(arr[mid]==x)
		return mid;
	else if(arr[mid]>x)
		return binarySearch(arr,low,mid-1,x);
	else
		return binarySearch(arr,mid+1,high,x);
}
int exponentialSearch(int arr[],int N,int x)
{
	int bound=1;
	while(bound<N&&arr[bound]<x)
		bound*=2;
	return binarySearch(arr,bound/2,min(bound,N),x);
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10};
	cout<<"The position of 6 is "<<exponentialSearch(arr,10,6);
}