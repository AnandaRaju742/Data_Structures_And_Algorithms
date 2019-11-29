/*
	Done by :G. Anandaraju
*/
//using only one array
#include<iostream>
using namespace std;
int findLCSLength(string X,string Y)
{
	int M=X.length();
	int N=Y.length();
	int curr[N+1],prev;
	for(int i=0;i<=N;i++)
	{
		//prev contains the previous value that the array element holds
		//Dont come to conclusion that it stores junk value in for loop stmt 25 takes care of these initialization
		//prev ini to zero because of first col value contains zero
		prev=0; // or curr[0]
		for(int j=0;j<=N;j++)
		{
			//storing prev values
			prev=curr[j];
			if(i==0||j==0)
				curr[j]=0;
			else{
				//Why we select prev value??
				//because as we visualize , if the alphabets are equal, we goto to x-1,y-1 location
				//x-1,y-1 location is nothing but ancient value or old value of previous element
				//E.g:
				//		1 2 x x
				//		0 2 x x
				//		  *         x-some value        
				// 2 is the current element and we get this value by adding +1 to the 1
				// coming to our curr array, prev denotes this value only 
				// so we took prev value +1
				if(X[i-1]==Y[j-1])
					curr[j]=prev+1;
				else
				//Why curr[j] and curr[j-1]
				// curr[j-1] because it is the length from left box
				// why curr[j] because curr[j] denotes the prev value that is top box length
					curr[j]=max(curr[j-1],curr[j]);
			}
		}
	}
	return curr[N];
}
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	if(a.length()>b.length())
		cout<<findLCSLength(a,b)<<endl;
	else
		cout<<findLCSLength(b,a)<<endl;
}

/*
using two arrays

#include<iostream>
using namespace std;
int findLCSLength(string X,string Y)
{
	int M=X.length();
	int N=Y.length();
	int prev[N+1],curr[N+1];
	for(int i=0;i<N;i++)
		prev[i]=0;
	for(int i=0;i<=M;i++)
	{
		for(int j=0;j<=N;j++)
		{
			prev[j]=curr[j];
			if(i==0||j==0)
				curr[j]=0;
			else
			{
				
				if(X[i-1]==Y[j-1])
					curr[j]=prev[j-1]+1;
				else
					curr[j]=max(prev[j],curr[j-1]);
			}
		}
	}
	return curr[N];
}
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	if(a.length()>b.length())
		cout<<findLCSLength(a,b)<<endl;
	else
		cout<<findLCSLength(b,a)<<endl;
}

*/