/*
	Count the occurance of each element in the array which have 0<=a[i]<=n where n is the size of the array
	Note that it should be done in constant space
*/
#include<bits/stdc++.h>
using namespace std;
void countOccurance(int arr[],int n)
{
	for(int i=0;i<n;++i)
	{
	    //cout<<arr[arr[i]]<< " "<<arr[i]<<" ";
		arr[arr[i]%n]+=n;    //Although the arr[i] initially is less than value of n arr[arr[i]] will give wrong result, because after adding n to arr[i] it will bounce out of n value
		//cout<<arr[arr[i]]<<endl;
	}
	for(int i=0;i<n;++i)
	{
	    //cout<<arr[i]<<endl;
		if(arr[i]/n!=0)
			cout<<"Element "<<i<<" occurs "<<arr[i]/n<<" times\n";
	}
	/*
		Restore the array
		for(int i=0;i<n;++i)
		{
			arr[arr[i]]-=n;
		}
	*/
}
int main()
{
	int arr[]={2,2,2,3,1,1};
	countOccurance(arr,sizeof(arr)/sizeof(arr[0]));
}
