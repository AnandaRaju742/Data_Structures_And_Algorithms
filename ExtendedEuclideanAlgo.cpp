/*
//initial try produces correct ans but code is ambigious
#include <bits/stdc++.h>
using namespace std;
void ExtendedEuclideanAlgo(int x,int y,int a,int b)
{
	while(b)  //note that it is not "y" 
	{
		swap(x,y);
		y=y-x*(a/b);
		swap(a,b);
		b=b%a;
	}
	cout<<"\nThe gcd(a,b) in eqn ax+by=gcd(a,b)="<<a<<endl;
}
int main()
{
	int x,y,a,b;
	cout<<"Enter the value of x";
	cin>>x;
	cout<<"\nEnter the value of a";
	cin>>a;
	cout<<"\nEnter the value of y";
	cin>>y;
	cout<<"\nEnter the value of b";
	cin>>b;
	ExtendedEuclideanAlgo(x,y,a,b);
}
*/