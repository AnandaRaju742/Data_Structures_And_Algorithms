/*
Done by G.Anandaraju
*/
#include<iostream>
using namespace std;
string longestCommonSubstring(string X,string Y)
{
	int M=X.length(),N=Y.length();
	int lookup[M+1][N+1];
	int maxlength=0,endPos=-1;
	for(int i=0;i<=M;i++)
	{
		for(int j=0;j<=M;j++)
		{
			if(i==0||j==0)
			{
				lookup[i][j]=0;
			}
			else{
				if(X[i-1]==Y[j-1])
				{
					lookup[i][j]=lookup[i-1][j-1]+1;
					//Upto here same logic but
					//here we have to find common substring(consecqutive positions)
					//refer techiedelight : https://www.techiedelight.com/longest-common-substring-problem/
					//refer that table in that if two chars match then they increment the value from  immediate left diagonal box
					//The max() find step is not needed here if chars dont match leave that
					//We keep a variable maxlength variable to keep track of largest number in that array/
					//Largest number means largest consecqutive numbers so to save that endpoint we use endPos variable
					if(lookup[i][j]>maxlength)
					{
						maxlength=lookup[i][j];
						endPos=i;
					}
				}
			}
		}
	}
	if(endPos==-1)
	{
		return "";
	}
	else{
		//endposition keeps the index of last element in consecqutive common string ; maxlength keeps the length of variable 
		// so endPos-maxlength gives the first index    (endPos-startpos=length)
		return X.substr(endPos-maxlength,maxlength);
	}
	/*
		to avoid if else in return statment (avoididng 39-47 )
		se like 
		use endPos=m;
		and write one return statement 
		return X.substr(endPos-maxlength,maxlength);
	*/
}
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	cout<<longestCommonSubstring(a,b)<<endl;
}