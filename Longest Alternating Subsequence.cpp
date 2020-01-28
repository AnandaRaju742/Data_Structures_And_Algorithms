/*
	Done by:G.AnandaRaju
	
*/
/*
	Approach: Same as kadane's algorithm keep track of end of change of sign
*/
#include<bits/stdc++.h>
using namespace std;
void printLongSubseq(vector<int> arr)
{
	int end_idx=0,len=1,temp_len=1;
	for(int i=0;i<arr.size()-1;i++)
	{
		if(arr[i]*arr[i+1]<0) ///multiplication of opposite sign numbers less than zero
		{
			temp_len++;
			if(temp_len>len)
			{
				len=temp_len;
				end_idx=i+1;
			}
		}else{
			temp_len=1;
		}
	}
	copy(arr.begin()+end_idx-len+1,arr.begin()+end_idx+1,ostream_iterator<int>(cout," "));
}
int main()
{
	
	vector<int> array={1, -2, 6, 4, -3, 2, -4, -3};
	printLongSubseq(array);
}