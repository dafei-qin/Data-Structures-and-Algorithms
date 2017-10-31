#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

class Node
{
public:
	int x;
	int y;
	Node* left, *right;
	Node(int x, int y)
	{
		this->x = x;
		this->y = y;
		this->left = NULL;
		this->right = NULL;
	}
};

class BST
{
private:
	Node *root;
puublic:
	BST(int *L, int n)
	{
		
	}
}