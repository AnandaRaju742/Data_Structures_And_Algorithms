#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>>& board,vector<vector<bool>> &visited,int i,int j)
    {
        if(i>=board.size()||i<0||j<0||j>=board[0].size()||visited[i][j])
            return false;
        return true;
    }
    bool solve(vector<vector<char>>& board,vector<vector<bool>> &visited,string &word,int i,int j,int ptr)
    {
        if(ptr>=word.size())
                return true;
        if(!isSafe(board,visited,i,j)||word[ptr]!=board[i][j])
        {
            return false;
        }
        //cout<<ptr<<" "<<i<<" "<<j<<" "<<board[i][j]<<endl;
        visited[i][j]=true;
        if(solve(board,visited,word,i+1,j,ptr+1)||
        solve(board,visited,word,i-1,j,ptr+1)||
        solve(board,visited,word,i,j-1,ptr+1)||
        solve(board,visited,word,i,j+1,ptr+1))
            return true;
        visited[i][j]=false;
        return false;
    }

    bool solve(vector<vector<char>>& board, string word) {
        //bool visited[board.size()][board.size()];
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        //visited{false};
        int ptr=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                //cout<<i<<" "<<j<<" "<<visited[i][j]<<endl;
                if(solve(board,visited,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
int main()
{
	int M,N;
	vector<vector<char>> board;
	cin>>M>>N;
	board.resize(M);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			char c;
			cin>>c;
			board[i].push_back(c);
		}
	}
	string find;
	cin>>find;
	cout<<solve(board,find);
	/*for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}*/
	return 0;
}
