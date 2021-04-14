#include <iostream>

using namespace std;

struct node
{
	int val;
	node* next;
};

void Add(node*& H, int);

void Show(node* H);

void Del(node*& H);

void Del(node*& H, int x);

void Swap(node*& H);

void swap(node*& H, node* p = nullptr);

void DeleteList(node*& H);

void divide(node*& H, node*& H1, node*& H2);

void megre(node*& H, node*& H1, node*& H2);

void bublesort(node*& H);

void mergeSort(node*& H);

int countOfNodes(node* H);

void combSort(node*& H);

int main()
{
	node* H = nullptr;

	Add(H, 7);
	Add(H, 10);
	Add(H, 12);
	Add(H, 15);
	Add(H, 8);
	Add(H, 4);
	Add(H, 12);
	Add(H, 13);
	Add(H, 1);
	Add(H, 14);
	Add(H, 2);
	Add(H, 15);
	Add(H, 4);
	Add(H, 9);

	Show(H);

	/*mergeSort(H);

	Show(H);

	swap(H);

	

	bublesort(H);*/
	combSort(H);


	Show(H);

	DeleteList(H);

	


	system("pause");

	return 0;

}

void Add(node*& H, int x)
{
	node* p = new node;
	p->val = x;
	p->next = H;
	H = p;
}

void Show(node* H)
{
	cout << "H->";
	while (H != NULL)
	{
		cout << H->val << "->";
		H = H->next;
	}
	cout << "NULL" << endl;
}

void Del(node*& H)
{
	if (H != NULL)
	{
		node* p = H;
		H = H->next;
		delete p;
	}
}

void Del(node*& H, int x)
{
	if (H != NULL)
	{
		if (H->val == x)
			Del(H);
		else
		{
			node* p = H;
			while (p->next != NULL && p->next->val != x)
			{
				p = p->next;
			}
			if (p->next != NULL)
				Del(p->next);
		}
	}
}

void Swap(node*& H)
{
	if (H != NULL && H->next != NULL)
	{
		node* p = H;
		H = H->next;
		p->next = H->next;
		H->next = p;
	}
}

void swap(node*& H, node* p)
{
	if (p == nullptr)
	{
		Swap(H);
	}
	else
	{
		if (p != nullptr && p->next != nullptr && p->next->next != nullptr)
		{
			node* ptr = p->next;
			p->next = ptr->next;
			ptr->next = ptr->next->next;
			p->next->next = ptr;
		}
	}
}



void DeleteList(node*& H)
{
	while (H != NULL)
	{
		node* p = H;
		H = H->next;
		delete p;
	}
}

void divide(node*& H, node*& H1, node*& H2)
{

	while (H)// && H->next)
	{
		node* p = H;
		H = H->next;
		p->next = H1;
		H1 = p;
		p = H;
		if (p != NULL)
		{
			H = H->next;
			p->next = H2;
			H2 = p;
			p = H;
		}
	}
}

void megre(node*& H, node*& H1, node*& H2)
{
	if (H == NULL)
	{
		if (H1 != NULL && H2 != NULL)
		{
			if (H1->val < H2->val)
			{
				H = H1;
				H1 = H1->next;
				H->next = NULL;
			}
			else
			{
				H = H2;
				H2 = H2->next;
				H->next = NULL;
			}
		}
		node* p = H;
		while (H1 != NULL && H2 != NULL)
		{
			if (H1->val < H2->val)
			{
				p->next = H1;
				H1 = H1->next;
				p->next->next = NULL;
				p = p->next;
			}
			else
			{
				p->next = H2;
				H2 = H2->next;
				p->next->next = NULL;
				p = p->next;
			}
		}
		if (H1 == NULL)
		{
			if (H)
				p->next = H2;
			else
				H = H2;
			H2 = NULL;
		}
		else if (H2 == NULL)
		{
			if (H)
				p->next = H1;
			else
				H = H1;
			H1 = NULL;
		}
	}
}

void mergeSort(node*& H)
{
	if (H && H->next)
	{
		node* H1 = nullptr;
		node* H2 = nullptr;
		divide(H, H1, H2);
		mergeSort(H1);
		mergeSort(H2);
		megre(H, H1, H2);
	}
}



void bublesort(node*& H)
{
	if (H != nullptr && H->next != nullptr)
	{
		node* p = H;
		node* end = nullptr;
		bool is = true;
		while (is == true)
		{
			is = false;
			if (H->val > H->next->val)
			{
				swap(H);
				is = true;
			}

			p = H;
			while (p->next && p->next->next && p->next->next != end)
			{
				if (p->next->val > p->next->next->val)
				{
					swap(H, p);
					is = true;
					end = p->next->next;
				}
					p = p->next;
			}
			//Show(H);
		}
	}
}

int countOfNodes(node* H)
{
	int nodes = 0;
	while (H != NULL)
	{
		nodes++;
		H = H->next;
	}
	return nodes;
}

void combSort(node*& H)
{
	int count = countOfNodes(H);
	count /= 1.3;
	//bool isSwapped = true;
	//count /= 1.3;
	while (count > 1)// || isSwapped)
	{
		//isSwapped = false;
		//count /= 1.3;
		//if (count < 2)
		//{
			//bublesort(H);
		//}
		//else 
		//{
		node* begin = H;
		node* end = H;
		for (int i = 0; i < count-1; i++)
			end = end->next;
		//przypadek pierwszego elementu
		if (H->val > end->next->val)
		{
			node* ptr = H;
			H = end->next;
			end->next = ptr;
			node* ptr2 = H->next;
			H->next = ptr->next;
			ptr->next = ptr2;
			begin = H;
		}
		while (end->next != nullptr)
		{
			if (begin->next->val > end->next->val)
			{
				node* ptr = begin->next;
				node* ptr2 = end->next;

				end->next = ptr;
				begin->next = ptr2;
				ptr2 = ptr2->next;
				begin->next->next = ptr->next;
				ptr->next = ptr2;
				//isSwapped = true;
			}
			end = end->next;
			begin = begin->next;
			
		}
			//Show(H);
		count /= 1.3;
		//}
	}
	bublesort(H);
}
