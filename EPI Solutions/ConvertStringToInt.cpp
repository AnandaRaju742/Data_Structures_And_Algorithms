#include<bits/stdc++.h>
using namespace std;
long int stringToInt(string str)
{
	long int result=0;
	int i=0;
	i=(str[0]=='-'||str[0]=='+')?1:0;
	for(;i<str.length();i++)
		result=result*10+(str[i]-'0');
	return (str[0]=='-')? -result: result;
		
}
int main()
{
	string str;
	cin>>str;
	long int result=stringToInt(str);
	cout<<str<<" conversion to string is "<<result<<endl;
}