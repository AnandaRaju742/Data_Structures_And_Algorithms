#include<bits/stdc++.h>
using namespace std;
struct Edges
{
	int src,dest,weight;
};
class Graph
{
	public:
	int N;
	vector< vector<pair<int,int> > > adj_list;
	Graph(int N)
	{
		this->N=N;
		adj_list.resize(N);
	}
	void add_Item(int src,int dest,int weight)
	{
		adj_list[src].push_back(make_pair(dest,weight));
		//uncomment below for undirected
		//adj_list[dest].push_back(make_pair(src,weight));
	}
	void printGraph()
	{
		for(int i=0;i<N;i++)
		{
				for(auto e:adj_list[i])
				{
					cout<<"( "<<i<<","<<e.first<<","<<e.second<<") ";
				}
				cout<<endl;
		}
	}
};
int main()
{
	//no of vertices
	int N;
	cin>>N;
	//number of relations ie, src,des,weight
	int temp;
	cin>>temp;
	Graph graph(N);
	for(int i=0;i<temp;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		graph.add_Item(s,d,w);
	}
	graph.printGraph();
}