#include<bits/stdc++.h>
using namespace std;
class Tree
{
	public:
		int data;
		Tree *left,*right;
	Tree(int data)
	{
		this->data=data;
		left=right=nullptr;
	}
};
void leftView(Tree *root)
{
	if(root==nullptr)
	{
		return;
	}
	list<Tree*> que;
	que.push_back(root);
	while(que.size())
	{
		int node=1;
		int i=0,n=que.size();
		while(i++<n)
		{
			Tree *temp=que.front();
			que.pop_front();
			if(node==1)
			{
				cout<<temp->data<<" ";
			}
			node++;
			if(temp->left)
				que.push_back(temp->left);
			if(temp->right)
				que.push_back(temp->right);
		}
		
	}
}
int main()
{
	Tree *root;
	root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->right = new Tree(4);
    root->right->left = new Tree(5);
    root->right->right = new Tree(6);
    root->right->left->left = new Tree(7);
    root->right->left->right = new Tree(8);

    leftView(root);

}