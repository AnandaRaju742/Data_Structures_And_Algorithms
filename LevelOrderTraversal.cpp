#include<bits/stdc++.h>
using namespace std;
class Tree
{
	public:
	int data;
	Tree *left,*right;
	Tree()
	{
		data=-1;
		left=right=nullptr;
	}
	Tree(int data)
	{
		this->data=data;
		left=right=nullptr;
	}
};
bool printLevelOrderTraversal(Tree *root,int level)
{
	if(root==nullptr)
		return false;
	if(level==1)
	{
		std::cout << root->data <<" ";
		return true;
	}
	bool left=printLevelOrderTraversal(root->left,level-1);
	bool right=printLevelOrderTraversal(root->right,level-1);
	return left||right;
}
void levelOrderTraversal(Tree *root)
{
	int level=1;
	while(printLevelOrderTraversal(root,level))
		level++;
}
// linear time complexity
void QueueLevelOrderTraversal(Tree *root)
{
	if(root==nullptr)
		return;
	queue<Tree*> que;
	que.push(root);
	while(!que.empty())
	{
		Tree *temp=que.front();
		que.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			que.push(temp->left);
		if(temp->right)
			que.push(temp->right);
	}
}
int main()
{
	
	Tree* root = nullptr;

    root = new Tree(15);
    root->left = new Tree(10);
    root->right = new Tree(20);
    root->left->left = new Tree(8);
    root->left->right = new Tree(12);
    root->right->left = new Tree(16);
    root->right->right = new Tree(25);

	//quadratic time complexity
    levelOrderTraversal(root);
    cout<<endl;
    //linear time complexity
    QueueLevelOrderTraversal(root);


}