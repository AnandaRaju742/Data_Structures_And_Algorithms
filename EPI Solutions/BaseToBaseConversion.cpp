#include<bits/stdc++.h>
using namespace std;
long long int convertToDecimal(string str,int b)
{
	int i=0;
	long long result=0;
	for(auto it=str.rbegin();it != str.rend();it++)
	{
		result=result+(((*it)-'0')*pow(b,i++));
	}
	return result;
}
string convertToBase(long long int IntRepr,int b)
{
	string result="";
	//long long int IntRepr=stoi(str);
	//cout<<IntRepr<<endl;
		while(IntRepr>0)
		{
			int rem=IntRepr%b;
			if(rem>=10)
				result+=(rem-10+'A');
			else
				result+=to_string(rem);
			IntRepr/=b;
		}
		//cout<<result<<endl;
	return string(result.rbegin(),result.rend());
}
string stringFromBase1ToBase2(string str,int b1,int b2)
{
	long long int InDec=convertToDecimal(str,b1);
	cout<<"In decimal form:"<<InDec<<endl;
	//int DecimalRepr=stoi(StrInDec);
	return convertToBase(InDec,b2);
	
}
int main()
{
	string str;
	cin>>str;
	int base1, base2;
	cin>>base1>>base2;
	string result=stringFromBase1ToBase2(str,base1,base2);
	cout<<"The conversion of string from base "<<base1<<" to base"<<base2<<" is "<<result<<endl;
}