#include <iostream>

using namespace std;

struct drzewoBST
{
	//drzewoBST* up;
	drzewoBST* left;
	drzewoBST* right;
	int val;
};

void AddBstNode(drzewoBST*& root, int x);

void ShowBstLOP(drzewoBST* root);

drzewoBST* lookForX(drzewoBST* root, int x);

drzewoBST* lookforMAX(drzewoBST* root);

drzewoBST* searchMAXrecursion(drzewoBST* root);

void deleteBranch(drzewoBST*& root);


int main()
{
	drzewoBST* root = NULL;
	AddBstNode(root, 12);
	AddBstNode(root, 16);
	AddBstNode(root, 25);
	AddBstNode(root, 14);

	cout << root->right->val << endl;
	cout << root->right->left->val << endl;
	cout << root->right->right->val << endl;

	ShowBstLOP(root);
	cout << endl;

	if (lookForX(root, 15))
	{
		cout << "Wskazany element istnieje\n";
	}
	else
		cout << "Wskazany element nie istnieje\n";

	cout << lookforMAX(root)->val << endl;

	//deleteBranch(root->right);

	ShowBstLOP(root);

	cout <<"\n"<< searchMAXrecursion(root)->val<< "\n";


	system("pause");
	return 0;
}

void AddBstNode(drzewoBST*& root, int x)
{
	if (root == NULL)
	{
		drzewoBST* p = new drzewoBST;
		p->left = NULL;
		p->right = NULL;
		p->val = x;
		root = p;
	}
	else
	{
		if (root->val <= x)
			AddBstNode(root->right,x);
		else
			AddBstNode(root->left, x);
	}
}

void ShowBstLOP(drzewoBST* root)
{
	if (root != NULL)
	{
		ShowBstLOP(root->left);
		cout << root->val <<" ";
		ShowBstLOP(root->right);
	}
}

drzewoBST* lookForX(drzewoBST* root, int x)
{
	drzewoBST* p = root;
	while (p != NULL)
	{
		if (p->val == x)
			return p;
		else if (p->val < x)
			p = p->left;
		else
			p = p->right;
	}
	return nullptr;
}

drzewoBST* lookforMAX(drzewoBST* root)
{
	if (root) {

		drzewoBST* p = root;
		while (p->right != NULL)
		{
			p = p->right;
		}
		return p;
	}
	else
		return nullptr;
}

drzewoBST* searchMAXrecursion(drzewoBST* root)
{
	if (root)
	{
		if (root->right)
			return searchMAXrecursion(root->right);
		else
			return root;
	}
	else
	{
		return nullptr;
	}
}

void deleteBranch(drzewoBST*& root)
{
	if (root)
	{
		deleteBranch(root->left);
		deleteBranch(root->right);
		delete root;
		root = NULL;
	}
}