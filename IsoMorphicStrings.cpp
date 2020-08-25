/*
	IsoMorphic Strings
*/
#include <bits/stdc++.h>
using namespace std;
bool isIsoMorphic(string a,string b)
{
	if(a.length()!=b.length()) return false;
	unordered_map<char,char> map;
	unordered_set<char> set;
	for(int i=0;i<a.length();++i)
	{
		if(map.find(a[i])!=map.end())
		{
			if(map[a[i]]!=b[i]) return false;
		}
		else
		{
			if(set.find(b[i])!=set.end()) return false;
			map[a[i]]=b[i];
			set.insert(b[i]);
		}
	}	
	return true;
}
int main()
{
	string a="abad",b="xyxz";
	cout<<std::boolalpha<<isIsoMorphic(a,b)<<endl;
}