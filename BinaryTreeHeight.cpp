#include <bits/stdc++.h>
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
int height(Tree *root)
{
	if(root==nullptr)
		return 0;
	return 1+max(height(root->left),height(root->right));
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

    cout << "The height of the binary tree is " << height(root);
	return 0;
}
