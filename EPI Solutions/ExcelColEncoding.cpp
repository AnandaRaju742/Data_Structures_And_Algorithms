#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	long int ans=0;
	for(int i=0;i<str.length();i++)
	{
		ans=ans*26+(str[i]-'A')+1;
	}
	cout<<ans<<endl;
}
/*
//Variation 1
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	long int ans=0;
	for(int i=0;i<str.length();i++)
	{
		ans=ans*26+(str[i]-'A');
	}
	cout<<ans<<endl;
}
*/
//Variation 2
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int X;
	cin>>X;
	string result="";
	while(X!=0)
	{
		int temp=(X-1)%26;
		result.push_back('A'+temp);
		X=(X-1)/26;
	}
	reverse(result.begin(),result.end());
	cout<<result<<endl;
}

*/