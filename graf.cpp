#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct node
{
	int connect;
	int val;
	node* next;
};

struct nodeGraph
{
	int from;
	int to;
	int val;
	nodeGraph* next;
};



void Add(node*& H, int, int);

void Add(nodeGraph*& H, int, int, int);

void Show(node* H);

void Show(nodeGraph* H);

int main()
{
	cout << "Hello World" << endl;

	int size = 0;

	//Reprezentacja tablicowa

	fstream plik;
	plik.open("graf.txt");

	string line;
	getline(plik, line);
	size = atoi(line.c_str());
	int** graph = new int* [size];

	for (int i = 0; i < size; i++)
	{
		graph[i] = new int[size];
		getline(plik, line);
		stringstream load(line);
		for (int j = 0; j < size; j++)
		{
			load >> graph[i][j];
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
	
	
	plik.close();

	//Reprezentacja listowa
	
	plik.open("graf.txt");

	//string line;
	getline(plik, line);
	size = atoi(line.c_str());
	node** LN = new node * [size];
	for (int i = 0; i < size; i++)
	{
		LN[i] = nullptr;
		getline(plik, line);
		stringstream load(line);
		for (int j = 0; j < size; j++)
		{
			int val;
			load >> val;
			if (val != 0)
				Add(LN[i], j, val);
		}
	}
	plik.close();


	cout << endl << endl;
	for (int i = 0; i < size; i++)
	{
		cout << i << ": ";
		Show(LN[i]);
	}

	//Reprezentacja listy krawedzi

	plik.open("graf.txt");
	getline(plik, line);
	size = atoi(line.c_str());
	nodeGraph* graph2 = nullptr;
	for (int i = 0; i < size; i++)
	{
		getline(plik, line);
		stringstream load(line);
		for (int j = 0; j < size; j++)
		{
			int val;
			load >> val;
			if (val != 0)
				Add(graph2, i, j, val);
		}
	}
	plik.close();

	Show(graph2);
	



	system("pause");
	return 0;
}

void Add(node*& H, int x, int y)
{
	node* p = new node;
	p->connect = x;
	p->val = y;
	
	p->next = H;
	H = p;
}

void Add(nodeGraph*& H, int from, int to, int val)
{
	nodeGraph* p = new nodeGraph;
	p->from = from;
	p->to = to;

	p->val = val;
	p->next = H;
	H = p;
}

void Show(node* H)
{
	cout << "H->";
	while (H != NULL)
	{
		cout << H->connect <<":"<< H->val<< "->";
		H = H->next;
	}
	cout << "NULL" << endl;
}

void Show(nodeGraph* H)
{
	cout << "H->";
	while (H != nullptr)
	{
		cout << H->from << "-" << H->to << ":" << H->val<< endl;
		H = H->next;
	}
	cout << "NULL" << endl;
}