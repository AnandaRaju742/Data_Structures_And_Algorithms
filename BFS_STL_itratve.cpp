/* 
	Done by:G.Anandaraju
 */
 /* 
	The concept here is take one node take its adjecent node list if the all adjecency node is taken and traverse the first adjecent taken
	ie. step 1:take one node and collect its adjlist and keep it in a queue. Display the current node
		step 2:take a node from queue(front member) and do step 1
 */
#include<bits/stdc++.h>
using namespace std;
struct Edges
{
	int src,dest;
	public:
			Edges()
			{

			}
			Edges(int src,int dest)
			{
				this->src=src;
				this->dest=dest;
			}
};
//One thing to note class graph wont contain edges object. Seems awkward right? A graph object is made of edge but here it is not
//If it holds Edges then it should have copy of Edges objects or referece to array of edges object
//In our case it is goint to hold only the information about the edges. Adjecency list only it holds not same Edges arrays or its copy
class Graph
{
	int N_nodes,N_edges;
	vector< vector <int> > Adj_list;
	public:
			Graph()
			{
				N_nodes=0;
				N_edges=0;
			}
			Graph(vector<Edges> &edges_objs, int N)
			{
				N_nodes=N;
				N_edges=edges_objs.size();
				//Here Adj_list.resize(N_edges) will not work;
				Adj_list.resize(N);
				for(Edges a_edge:edges_objs)
				{
					Adj_list[a_edge.src].push_back(a_edge.dest);
					Adj_list[a_edge.dest].push_back(a_edge.src);
				}
			}
			void BFS(vector<bool> &visited,int i)
			{
				queue<int> neigh_nodes;  //neighbour or adj nodes
				neigh_nodes.push(i);
				//visited[i]=true;  //May work if we remove stmt at line 51 ( visited[front]=true; ) and uncomment stmt at line 57 (visited[node]=true);
				while(!neigh_nodes.empty())
				{
					int front=neigh_nodes.front();
					neigh_nodes.pop();
					visited[front]=true;
					cout<<front<<" "; //Displays result of DFS
					for(int node:Adj_list[front])
					{
						if(!visited[node])
						{
							//visited[node]=true;
							neigh_nodes.push(node);
						}
					}
				}
				
			}
			void disp_BFS()
			{
				vector < bool > visited(N_nodes,false);
				//Not used for each loop because to initialise of visited. Use of visited makes it difficult. 
				//Difficulty will increase or code becomes clumspsy complex if use for each here
				for(int i=0;i<N_nodes;i++)
				{
					if(!visited[i])
					{
						BFS(visited,i);
					}
				}
			}
};
int main()
{
	int N_nodes,N_edges;
	cin>>N_nodes>>N_edges;
	//use vector here for neat code otherwise we have to pass N_edges value to many functions
	vector< Edges > Edj_list;
	
	for(int i=0;i<N_edges;i++)
	{
		int src,dest;
		cin>>src>>dest;
		// very important here we use anonymous object XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
		Edj_list.push_back(Edges(src,dest));
	}
	Graph graph(Edj_list,N_nodes);
	graph.disp_BFS();
}
/*
	Very very bad attempt
 #include<bits/stdc++.h>
using namespace std;
struct Edges
{
	int src,dest;
};
class Graph
{
	int N;
	vector< vector<int> > adj_list;
	public:
			Graph()
			{
				this->N=N;
				adj_list.resize(0);
			}
			Graph(Edges edges[],int N,int noofedge)
			{
				this->N=N;
				adj_list.resize(N);
				for(int i=0;i<noofedge;i++)
				{
					adj_list[edges[i].src].push_back(edges[i].dest);
					adj_list[edges[i].dest].push_back(edges[i].src);
				}
			}
			void DFS(vector<bool> &visited,int start)
			{
				queue<int> que;
				visited[start]=true;
				que.push(start);
				while(!que.empty())
				{
					int top=que.front();
					que.pop();
					cout<<top<<" ";
					visited[top]=true;
					for( int node:adj_list[top])
					{
						if(visited[node]==false)
						{
							visited[node]=true;
							que.push(node);
						}
					}
				}
			}
			void Disp_DFS()
			{
				vector< bool > visited(N,false);
				for(int i=0;i<N;i++)
				{
					if(visited[i]==false)
					{
						DFS(visited,i);
					}
				}
			}
};
int main()
{
	//No of edges;
	int N,noofedge;
	cin>>N;
	cin>>noofedge;
	Edges edges[noofedge];
	for(int i=0;i<noofedge;i++)
	{
		cin>>edges[i].src>>edges[i].dest;
	}
	Graph graph(edges,N,noofedge);
	graph.Disp_DFS();
} */