/*
	Facebook Question:https://leetcode.com/discuss/interview-question/629432/facebook-phone-unique-elements-in-a-sorted-array-clone-graph
	time complexity: O(n) space:O(1)
*/
#include <iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> arr{1, 1, 1, 1, 2, 2, 2, 2, 5, 5, 5, 7, 7, 8, 8, 10};
	int count=0;int curr=arr[0];
	for(int i=1;i<arr.size();i++)
	{
		if(arr[i]!=curr)
		{
			curr=arr[i];
			count++;
		}
	}
	cout<<count+1<<endl;
	return 0;
}
