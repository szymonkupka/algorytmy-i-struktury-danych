#include <iostream>

using namespace std;

struct drzewoBST
{
	drzewoBST* up;
	drzewoBST* left;
	drzewoBST* right;
	int val;
};

void addBstNode(drzewoBST*& root, int x, drzewoBST* pr = NULL);

void showBstLOP(drzewoBST* root);

drzewoBST* maximum(drzewoBST* root);

drzewoBST* minimum(drzewoBST* root);

drzewoBST* maximumRecursion(drzewoBST* root);

drzewoBST* minimumRecursion(drzewoBST* root);

drzewoBST* previous(drzewoBST* root);

drzewoBST* next(drzewoBST* root);

void deleteBstNode(drzewoBST*& root);

void rotateLeft(drzewoBST*& root);

void rotateRight(drzewoBST*& root);

void rotateRightLeft(drzewoBST*& root);

void rotateLeftRight(drzewoBST*& root);

drzewoBST* searchValue(drzewoBST* root, int x);

drzewoBST* searchMaxNode(drzewoBST* root);

drzewoBST* searchMAXrecursion(drzewoBST* root);

void deleteBranch(drzewoBST*& root);


int main()
{
	drzewoBST* root = NULL;
	addBstNode(root, 10);
	addBstNode(root, 5);
	addBstNode(root, 20);
	addBstNode(root, 15);
	addBstNode(root, 30);
	addBstNode(root, 0);
	addBstNode(root, 7);
	addBstNode(root, 8);

	/*cout << "-----Poprzednik-----" << endl;

	cout <<"10\t"<< previous(root)->val << endl;

	cout << "5\t" << previous(root->left)->val << endl;

	cout << "20\t" << previous(root->right)->val << endl;

	cout << "30\t" << previous(root->right->right)->val << endl;

	cout << "7\t" << previous(root->left->right)->val << endl;

	cout << "15\t" << previous(root->right->left)->val << endl;

	if (!previous(root->left->left))
		cout << "0\t" << "nullptr\n";
	else
		cout << previous(root->left->left)->val << endl;

	cout << "\n-----Nastepnik-----" << endl;
	
	cout << "10\t" << next(root)->val << endl;

	cout << "5\t" << next(root->left)->val << endl;

	cout << "20\t" << next(root->right)->val << endl;

	cout << "0\t" << next(root->left->left)->val << endl;

	cout << "7\t" << previous(root->left->right)->val << endl;

	cout << "15\t" << next(root->right->left)->val << endl;

	if (!next(root->right->right))
		cout << "30\t" << "nullptr\n";
	
	
	cout << "\n-----Kolejnosc drzewa-----"<<endl;

	showBstLOP(root);
	cout << endl;

	cout << "Usuniecie " << root->left->right->val << endl;

	deleteBstNode(root->left->right);

	showBstLOP(root);
	cout << endl;*/

	showBstLOP(root);
	cout << endl;

	//deleteBstNode(root);

	showBstLOP(root);
	cout << endl;


	system("pause");
	return 0;
}

void addBstNode(drzewoBST*& root, int x, drzewoBST* pr)
{
	if (root == NULL)
	{
		drzewoBST* p = new drzewoBST;
		p->left = NULL;
		p->right = NULL;
		p->val = x;
		p->up = pr;
		root = p;
	}
	else
	{
		if (root->val <= x)
			addBstNode(root->right, x, root);
		else
			addBstNode(root->left, x, root);
	}
}

void showBstLOP(drzewoBST* root)
{
	if (root != NULL)
	{
		showBstLOP(root->left);
		cout << root->val << " ";
		showBstLOP(root->right);
	}
}

drzewoBST* maximum(drzewoBST* root)
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

drzewoBST* minimum(drzewoBST* root)
{
	if (root) {

		drzewoBST* p = root;
		while (p->left != NULL)
		{
			p = p->left;
		}
		return p;
	}
	else
		return nullptr;
}

drzewoBST* maximumRecursion(drzewoBST* root)
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

drzewoBST* minimumRecursion(drzewoBST* root)
{
	if (root)
	{
		if (root->left)
			return searchMAXrecursion(root->left);
		else
			return root;
	}
	else
	{
		return nullptr;
	}
}

drzewoBST* previous(drzewoBST* root)
{
	if (root)
	{
		if (root->left)
		{
			return maximum(root->left);
		}
		else
		{	
			while (root->up != nullptr)
			{
				//drzewoBST* ptr = root->up;
				if (root->up->left == root)
				{
					root = root->up;
				}
				else if (root->up->right == root)
				{
					return root->up;
				}
				//else
				//	return nullptr;
			}
			return nullptr;
		}
	}
	else
		return nullptr;
}

drzewoBST* next(drzewoBST* root)
{
	if (root)
	{
		if (root->right)
			return minimum(root->right);
		else
		{
			while (root->up != nullptr)
			{
				if (root->up->left == root)
				{
					return root->up;
				}
				else if (root->up->right == root)
				{
					root = root->up;
				}
			}
			return nullptr;
		}
	}
	else
		return nullptr;
}

void deleteBstNode(drzewoBST*& root)
{
	if (root != nullptr)
	{
		//Przypadek liscia
		if (root->left == nullptr && root->right == nullptr)
		{

			if (root->up != nullptr)
			{
				drzewoBST* p = root;
				if (root->up->right == root)
					root->up->right = nullptr;
				else
					root->up->left = nullptr;
				delete p;
			}
			else
			{
				//przypadek jednoeoementowego drzewa
				delete root;
				root = nullptr;
			}
		}
		//Przypadke galezi z jednym synem po lewej
		else if (root->right == nullptr)
		{
			drzewoBST* del = root;
			if (root->up != nullptr)
			{
				drzewoBST* p = root->up;
				if (p->left == root)
				{
					p->left = root->left;
					delete del;
				}
				else
				{
					p->right = root->left;
					delete del;
				}
			}
			else
			{
				//Przypadek gdy jest to korzen
				drzewoBST* p = root;
				root = root->left;
				delete p;
			}
		}
		//Przypadke galezi z jednym synem po prawej
		else if (root->left == nullptr)
		{
			drzewoBST* del = root;
			if (root->up != nullptr)
			{
				drzewoBST* p = root->up;
				if (p->left == root)
				{
					p->left = root->right;
					delete del;
				}
				else
				{
					p->right = root->right;
					delete del;
				}
			}
			else
			{
				//Przypadek gdy jest to korzen
				drzewoBST* p = root;
				root = root->right;
				delete p;
			}
		}
		//Przypadek galezi z dwoma synami
		else
		{
			drzewoBST* next_ptr = next(root);
			drzewoBST* del = root;
			if (next_ptr->right != nullptr)
			{
				//przypadek kiedy nastepnik posiada prawego syna
				if(next_ptr->up->left == next_ptr)
					next_ptr->up->left = next_ptr->right;
				else
					next_ptr->up->right = next_ptr->right;
			}
			else
			{
				//ustawienie wspaznika ojca na NULL
				//next_ptr->up->left = nullptr;
				if (next_ptr->up->left == next_ptr)
					next_ptr->up->left = nullptr;
				else
					next_ptr->up->right = nullptr;
			}

			next_ptr->left = root->left;
			next_ptr->right = root->right;

			
			if (root->up != nullptr)
			{
				//przypadek gdy wezel ma ojca
				if (root->up->left == root)
				{
					next_ptr->up = root->up;
					root->up->left = next_ptr;
				}
				else
				{
					next_ptr->up = root->up;
					root->up->right = next_ptr;
				}
				delete del;
			}
			else
			{
				next_ptr->up = nullptr;
				delete del;
			}
		}
	}
}

void rotateLeft(drzewoBST*& root)
{
	if (root && root->right)
	{
		drzewoBST* ptr = root;
		root = root->right;
		if (ptr->up != nullptr)
		{
			/*if (ptr->up->right == ptr)
			{
				ptr->up->right = root;
				root->up = ptr->up;
			}
			else
			{
				ptr->up->left = root;
				root->up = ptr->up;
			}*/

		root->up = ptr->up;
		}
		else
		{
			root->up = nullptr;
		}

		if (root->left != nullptr)
		{
			ptr->right = root->left;
			root->left->up = ptr;
		}
		else
		{
			ptr->right = nullptr;
			
		}
		root->left = ptr;
		ptr->up = root;
	}
}

void rotateRight(drzewoBST*& root)
{
	if (root && root->left)
	{
		drzewoBST* ptr = root;
		root = root->left;

		if (ptr->up != nullptr)
		{
			/*if (ptr->up->right == ptr)
			{
				ptr->up->right = root;
				root->up = ptr->up;
			}
			else
			{
				ptr->up->left = root;
				root->up = ptr->up;
			}*/

		root->up = ptr->up;
		}
		else
		{
			root->up = nullptr;
		}

		if (root->right != nullptr)
		{
			ptr->left = root->right;
			root->right->up = ptr;
		}
		else
		{
			ptr->left = nullptr;

		}
		root->right = ptr;
		ptr->up = root;
	}
}

void rotateRightLeft(drzewoBST*& root)
{
	if (root && root->right)
	{
		rotateRight(root->right);
		rotateLeft(root);
	}
}

void rotateLeftRight(drzewoBST*& root)
{
	if (root && root->left)
	{
		rotateLeft(root->left);
		rotateRight(root);
	}
}



drzewoBST* searchValue(drzewoBST* root, int x)
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

drzewoBST* searchMaxNode(drzewoBST* root)
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