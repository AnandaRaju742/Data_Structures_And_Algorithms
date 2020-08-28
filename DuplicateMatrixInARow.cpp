/*
	Duplicate row in the matrix
*/
#include<bits/stdc++.h>
using namespace std;
const int col=5;
class Trie
{
public:
	bool isLeaf;
	unordered_map<char,Trie*> map;
	Trie()
	{
		isLeaf=false;

	}
};
bool insert(Trie* head,int mat[3])
{
	Trie *curr=head;
	for(int i=0;i<3;++i)
	{
		if(curr->map[mat[i]]==nullptr)
			curr->map[mat[i]]=new Trie();
		curr=curr->map[mat[i]];
	}
	if(curr->isLeaf==true) return false;  //denotes duplicate
	return curr->isLeaf=true;
}
bool containsDuplicateRow(int mat[5][3])
{
	Trie *head=new Trie();
	for(int i=0;i<5;++i)
		if(!insert(head,mat[i])) return true;
}
int main()
{
	int mat[5][3]={{1,0,0},
				  {0,0,0},
				  {1,1,0},
				  {1,0,1},
				  {1,0,1}};
	cout<<boolalpha<<containsDuplicateRow(mat);
}
