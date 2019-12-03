#include<bits/stdc++.h>
using namespace std;
struct Edges
{
	int src,dest;
};
class Graph
{
	public:
			int N;
			vector< vector<int> > adj_list;
			Graph(int N)
			{
				this->N=N;
				adj_list.resize(N);
			}
			void addItem(int src,int dest)
			{
				adj_list[src].push_back(dest);
				//uncomment below line for undirected graph
				//adj_list[dest].push_back(src);
			}
			void printGraph()
			{
				for(int i=0;i<N;i++)
				{
					cout<<i<<"-->";
					for(int x:adj_list[i])
					{
						cout<<x<<" ";
					}
					cout<<"\n";
				}
			}
};
int main()
{
	int N;
	cin>>N;
	int temp;
	cin>>temp;
	Graph graph(N);
	for(int i=0;i<temp;i++)
	{
		int s,d;
		cin>>s>>d;
		graph.addItem(s,d);
	}
	graph.printGraph();
}