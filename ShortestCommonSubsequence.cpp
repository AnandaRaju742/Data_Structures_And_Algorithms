#include <bits/stdc++.h>
using namespace std;
/*
goal is to find string in which a and b both are subsequence
*/

int SSS(string a,string b,int i,int j,unordered_map<string,int> lookup)
{
	/*
		why "i+j" 
		in prev problem we used condition as "if(i==0||j==0) return 0"
		why suddenly i+j ?
		because for this problem 
			if a and b are equal strings 
				then we return either of these (at that time if we put return 0 then no problem because both i and j reach(get the value) 0 at same time.
			else
				(a and b are in different length or equal length of strings with some difference or entirely different)
				then else part of the function will be executed, in that at some point of recursion we reach either i or j is 0
				
				let us consider example
				aaabcbdab ->a
				   bdcaba ->b
				b is smaller so j value will be zero now but a has remaining 3 chars. These 3 chars can be appended to resultant string in that way also it becomes subsequence.
				the 3 chars count is stored in i in this case to just we add up.
				
				To conclude:
						our algo try to find the common chars (subsequence) b/w two strings. after one point if any string reaches end ( here reaching zero because of right to left traversal)
						the remaining part is to just appended ( or char count is added) to result. It is correct because nothing left to find common so just adding them makes the string with greater length 
						to part of subsequence and lesser length string already find and combined with the common chars of long length string
				
			
	*/
	if(i==0||j==0)
		return i+j;
	string key=to_string(i)+"|"+to_string(j);
	if(lookup.find(key)==lookup.end())
	{
		if(a[i-1]==b[j-1])
		{
			lookup[key]= 1+SSS(a,b,i-1,j-1,lookup);
		}
		else
		{
			lookup[key]= min( SSS(a,b,i-1,j,lookup) + 1,
								SSS(a,b,i,j-1,lookup) + 1);
			/*
				SSS(a,b,i-1,j,lookup) + 1
				notice that plus one is added which was not done in prev problem.
				because in this problem we consider the selected char also consitute for the shortest subsequence
				
				but why not applicable to LCS
				not applicable because the length value is incremented only if i and j are equal. The result should contain only common chars among the strings
				but this problem we are trying to add the current char (either a or b) and check for furthur. may be after adding this char we may smaller subsequence.
			*/
		}
	}
	return lookup[key];
}
int main()
{
	string a,b;
	cin>>a>>b;
	unordered_map<string,int> lookup;
	cout<<SSS(a,b,a.length(),b.length(),lookup);
	return 0;
}
