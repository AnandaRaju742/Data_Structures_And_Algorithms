/*
	Done by: Anandaraju G
*/
#include<bits/stdc++.h>
using namespace std;
bool contains( unordered_set<int> const &window,int k)
{
	return (window.find(k)!=window.end());
}
void K_duplicates(vector<int> arr,int k)
{
	unordered_set<int> window;
	bool flag=false;
	for(int i=0;i<arr.size();i++)
	{
		if(contains(window,arr[i])==false)
		{
			window.insert(arr[i]);
		}
		else{
			flag=true;
			break;
		}
		if(i>k)
		{
			window.erase(arr[i-k]);
		}
	}
	if(flag)
		cout<<"contains duplicate";
	else
		cout<<"No duplicates in k range";
}
int main()
{
	vector<int> arr={5, 6, 8, 2, 4, 6, 9};
	int k=4;
	K_duplicates(arr,k);
}