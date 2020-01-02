#include<bits/stdc++.h>
using namespace std;
class Graph
{
	public:
			int N;
			vector< vector<int> > adj_list;
			Graph()
			{
				N=0;	
			}
			Graph(int N)
			{
				this->N=N;
				adj_list.resize(N);
			}
			void addEdge(int src,int dest)
			{
				adj_list[src].push_back(dest);
			}
			void DFS(int root)
			{
				stack<int> stk;
				vector<int> visited(this->N,0);
				stk.push(root);
				while(stk.empty()==false)
				{
					int top=stk.top();
					stk.pop();
					//If below stmt not there then some edges comes repeatedly
					//though the below stmt look redundant it is very important
					//take edge 8-9
					//at some iteration 8 calls 9
					//9 calls 9-10 and 9-11 so 10 and 11 are inserted
					//if again some edge calls 9 i.e x-9 then 10 and 11 is inserted 
					//because it is not still explored and mark as visited
					if(visited[top])
						continue;
					cout<<top<<" ";
					visited[top]=1;
					///note that here revere iterator is used
					for (auto it = adj_list[top].rbegin();  it != adj_list[top].rend(); ++it)
					{
						int x = *it;
						if(!visited[x])
							stk.push(x);
					}
				}
			}				
			
};
int main()
{
	int N;
	cin>>N;
	Graph graph(N);
	for(int i=0;i<N;i++)
	{
		int src,dest;
		cin>>src>>dest;
		graph.addEdge(src,dest);
	}
	graph.DFS(1);
}