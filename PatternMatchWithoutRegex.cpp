/*
	Determine the pattern will match or not without using regex
	e.g xyx matches with codegeekcode
*/
#include<bits/stdc++.h>
using namespace std;
bool patternmatch(string pattern,string text,unordered_map<char,string> &map,int i,int j)
{
	int m=pattern.size(),n=text.size();
	if(n<m) return false;
	if(i==m&&j==n) return true; //both string and pattern reaches end
	if(i==m||j==n) return false; //either string or pattern reaches end
	char P_char=pattern[i]; //pattern character
	if(map.find(P_char)!=map.end()) //If already assigned a value to this pattern character
	{
		string value=map[P_char];
		int V_size=value.size();
		if(text.substr(j,V_size).compare(value)) return false;
		return patternmatch(pattern,text,map,i+1,j+V_size);
	}
	for(int k=1;k<=n-j;++k)
	{
		map[P_char]=text.substr(j,k);
		if(patternmatch(pattern,text,map,i+1,j+k))
		return true;
		map.erase(P_char);
	}
	return false;
}
bool patternmatch(string pattern,string text)
{
	unordered_map<char,string> map;
	return patternmatch(pattern,text,map,0,0);
	/*//Prints the associated strings
        if(true from above line then)
        {
            for(string x:map[pattern[i]) cout<<x<<endl;
        }
	*/
}
int main()
{
	string pattern="xyy";
	string text="codegeekcode";
	cout<<std::boolalpha<<patternmatch(pattern,text);
}
