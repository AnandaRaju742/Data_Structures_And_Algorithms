/*
Leetcode
https://leetcode.com/problems/license-key-formatting/submissions/

*/
#include<iostream>
using namespace std;
string licenseKeyFormatting(string S, int K) {
        string newKey="";
        int tempK=0;
        for(int i=S.length()-1;i>=0;i--)
        {
            if(S[i]=='-')
                continue;
            if(tempK==K)
            {
                newKey.push_back('-');
                tempK=0;
                i++;
            }
            else
            {
                newKey.push_back(toupper(S[i]));
                tempK++;
            }
        }
        reverse(newKey.begin(),newKey.end());
        //cout<<newKey<<endl;
        return newKey;
    }
int main()
{
string input;
int k;
cin>>input>>k;
cout<<licenseKeyFormatting(input,k);
}