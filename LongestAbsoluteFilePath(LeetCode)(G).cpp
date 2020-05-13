#include <bits/stdc++.h>
using namespace std;

int main()
{
	string input;
	cin>>input;
	unordered_map<int,string> lookup;
	lookup[0]="dir";
	int tcount=0;
	for(int i=3;i<input.length();i++)
	{
		int temp=input.find('\\',i+1);
		string Name;
		if(temp==-1)
		{
			Name=input.substr(i+1);
			cout<<lookup[tcount-1]+'/'+Name<<endl;
			lookup[tcount]=lookup[tcount-1]+'/'+Name;
			break;
		}
		if(input[temp+1]=='t')
			tcount++;
		else
		{
			string Name=input.substr(i+1,temp-i-1);
			cout<<lookup[tcount-1]+'/'+Name<<endl;
			lookup[tcount]=lookup[tcount-1]+'/'+Name;
			tcount=0;
		}
		i=temp;
	}
	int maxi=0;string result="";
	for(auto p:lookup)
	{
		cout<<'{'<<p.first<<" "<<p.second<<'}'<<endl;
		if(p.second.length()>maxi)
		{
			result=p.second;
			maxi=p.second.length();
		}
	}
	cout<<result<<endl;
	return 0;
}
