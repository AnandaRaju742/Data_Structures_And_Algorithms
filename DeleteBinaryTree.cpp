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
void deleteBinaryTree(Tree* &root)
{
	/*
		Post Order traversal is followed here because child should be deleted before parent
	*/
	if(root==nullptr)
		return;
	deleteBinaryTree(root->left);
	deleteBinaryTree(root->right);
	delete root;
	root=nullptr;
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

    // delete entire tree
    deleteBinaryTree(root);

    if (root == nullptr)
        cout << "Tree Successfully Deleted";

}