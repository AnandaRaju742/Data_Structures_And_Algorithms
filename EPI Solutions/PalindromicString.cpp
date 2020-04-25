#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	bool b=true;
	for(int i=0,j=str.length()-1;i<j;i++,j--)
	{
		while(!isalnum(str[i])&&i<j)
		{
			i++;
		}
		while(!isalnum(str[j])&&i<j)
		{
			j--;
		}
		if(tolower(str[i])!=tolower(str[j]))
		{
			b=false;
			break;
		}
	}
	if(b)
		cout<<"Palindrome"<<endl;
	else
		cout<<"Not a Palindrome"<<endl;
}
/*
//Initial Try
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	bool b=true;
	for(int i=0,j=str.length()-1;i<j;)
	{
		if(!isalnum(str[i]))
		{
			i++;
			continue;
		}
		if(!isalnum(str[j]))
		{
			j--;
			continue;
		}
		if(tolower(str[i])!=tolower(str[j]))
		{
			b=false;
			break;
		}
		else
		{
			i++;
			j--;
		}
	}
	if(b)
		cout<<"Palindrome"<<endl;
	else
		cout<<"Not a Palindrome"<<endl;
}
*/
