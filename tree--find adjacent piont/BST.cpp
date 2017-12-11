#include <iostream>
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
	Node* root;	
	Node* rotL(Node *h)
	{
		Node* v = h->right;
		h->right = v->left;
		v->left = h;
		return v;
	}
	Node* rotR(Node *h)
	{
		Node* u = h->left;
		h->left = u->right;
		u->right= h;
		return u;
	}
	Node* putRoot(Node *z, int x, int y)
	{
		if (z == NULL) return new Node(x, y);
		if (x == z->x) {z->x = x; return z;}
		else if (x < z->x) {z->left = putRoot(z->left, x, y); z = rotR(z);}
		else if (x > z->x) {z->right = putRoot(z->right, x, y); z = rotL(z);}
		return z;
	}
public:
	BST()
	{
		root = NULL;
	}
	void put(int x, int y)
	{
		root = putRoot(root, x, y);
	}
	int get(int x)
	{
		Node *z = root;
		while (z != NULL)
		{
			if (x == z->x) return z->y;
			else if (x < z->x) z = z->left;
			else if (x > z->x) z = z->right;
		}
		return -1;
	}
};

int main(int argc, char const *argv[])
{
	return 0;
}