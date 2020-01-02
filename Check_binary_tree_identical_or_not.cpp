#include<bits/stdc++.h>
using namespace std;
class Tree
{
	int val;
	Tree* left,right;
	public:
			Tree()
			{
				val=0;
				left=NULL;
				right=NULL;
			}
			Tree(int N)
			{
				val=N;
				left=NULL;
				right=NULL;
			}
			static void inorder(Tree *leaf)
			{
				while(leaf!=NULL)
				{
					inorder(leaf->left);
					cout<<(leaf->val)<<" ";
					inorder(leaf->right);
				}
			}
};
int main()
{
	Tree *root=new Tree(8);
	inorder(root);
}