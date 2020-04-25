#include<bits/stdc++.h>
#define SIZE 25
using namespace std;
int arr[SIZE][SIZE];
void LCSLength(string a,string b)  //same lcs table
{
	int M=a.length();
	int N=b.length();
	for(int i=0;i<M+1;i++)
	{
		for(int j=0;j<N+1;j++)
		{
			if(i==0||j==0)
			{
				arr[i][j]=0;
			}
			else{
				if(a[i-1]==b[j-1])
				{
					arr[i][j]=arr[i-1][j-1]+1;
				}
				else{
					arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
				}
			}
		}
	}
}
void Diff(string a,string b,int i,int j)
{
	/*
		Inference is in the LCS table (use this website for visualisation http://lcs-demo.sourceforge.net)
		when the two strings are same no problem just display
		when the new string contains alphabet that is not present in the old we put "+" otherwise "-"
		
		Remember in LCS table old string is on left side and new string are on top side
		
		in the visualisation, the newer string doesnot contain the older string char, in the LCS length table top cell ([i-1][j]) will be having higher value
		if the new string contain new value not contained in old string then,in the LCS length table left cell ([i][j-1]) will be having higher value
		
	*/
	if(i>0&&j>0&&a[i-1]==b[j-1])
	{
		/*
			notice that we call the function and only display because we iterate the strings from the backwards to front
		*/
		Diff(a,b,i-1,j-1);                  
		cout<<a[i-1]<<" ";
	}
	else if((i>0)&&(j==0||arr[i-1][j]>arr[i][j-1]))  
	{
		/*
			we put i>0 because in the next stmt after this condition is true i value is decremented by 1. decrementing 0 and access string with negative idx cause seg fault;
			we put j==0 or arr[i-1.........      we put that here because int the condition arr[i][j-1] if j value is zero then it access negative index so..  ("i" cant be -ve because of first condition)
		*/
		Diff(a,b,i-1,j);
		cout<<"-"<<a[i-1]<<" ";
	}
	else if((j>0)&&(i==0||arr[i-1][j]<=arr[i][j-1]))
	{
		/*
			we put j>0 because in the next stmt after this condition is true j value is decremented by 1. decrementing 0 and access string with negative idx cause seg fault;
			we put i==0 or arr[i-1.........      we put that here because int the condition arr[i][j-1] if i value is zero then it access negative index so..  ("j" cant be -ve because of first condition)
		*/
		Diff(a,b,i,j-1);
		cout<<"+"<<b[j-1]<<" ";
	}
}
void Diff(string a,string b)
{
	LCSLength(a,b);
	Diff(a,b,a.length(),b.length());  //overloaded fn
}
int main()
{
	string a,b;
	cin>>a>>b;
	Diff(a,b);
}