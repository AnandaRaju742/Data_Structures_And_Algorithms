#include<bits/stdc++.h>
using namespace std;
bool palindrome(string str,int i,int j)
{
	//i==j point to same letter and 
	//i>j says that string should have even length
	//if it comes to i>j then previous result also palindrome
	if(i>=j)  
		return true;
	if(str[i]==str[j])
		return palindrome(str,i+1,j-1);
	return false;
}
int main()
{
	string str;
	cin>>str;
	cout<<"IS "<<str<<" is palindrome"<<palindrome(str,0,str.length()-1);
}