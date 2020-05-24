/*
	https://leetcode.com/problems/unique-email-addresses/
*/
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int numUniqueEmails(vector<string>& emails) {
        set<string> email_addrs;
        for(string s:emails)
        {
            string email="";
            int i;
            for(i=0;i<s.length();++i)
            {
                if(s[i]=='@'||s[i]=='+')
                    break;
                if(s[i]!='.')
                    email+=s[i];
            }
            if(s[i]!='@')
                i=s.find("@");
            email+=s.substr(i,s.length()-i);
            //cout<<email<<endl;
            email_addrs.insert(email);
        }
        return email_addrs.size();
    }
int main()
{
	vector<string> email_addrs{};
	
}