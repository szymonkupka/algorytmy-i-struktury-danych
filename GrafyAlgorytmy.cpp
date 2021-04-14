#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct nodeGraph
{
	int from;
	int to;
	int val;
	nodeGraph* next;
};

struct queue
{
	int val;
	queue* next;
};

void BFS(nodeGraph*);

void algorytmPrima(nodeGraph*);

void bublesort(nodeGraph*& H);

void swap(nodeGraph*& H, nodeGraph* p);

void Swap(nodeGraph*& H);

bool isAllGray(int*,int);

void algorytmKuskarla(nodeGraph*);


//void Add(node*& H, int, int);

void Add(nodeGraph*& H, int, int, int);

//void Show(node* H);

void Show(nodeGraph* H);

int amountOfNode(nodeGraph*);

void push(queue*& H, int val);

void pop(queue*& H);

int main()
{
	cout << "Hello World" << endl;

	int size = 0;

	//Reprezentacja tablicowa

	fstream plik;

	string line;

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

	//Przeszukiwanie wszerz

	cout << "Przeszukanie grafu wszerz\n";
	BFS(graph2);

	bublesort(graph2);

	Show(graph2);

	algorytmKuskarla(graph2);


	system("pause");
	return 0;
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

void Show(nodeGraph* H)
{
	//cout << "H->";
	while (H != nullptr)
	{
		cout << H->from << "-" << H->to << ":" << H->val << endl;
		H = H->next;
	}
	//cout << "NULL" << endl;
}

void BFS(nodeGraph* graph)
{
	//Pierwszy wierzcho³ek
	int s = graph->from;

	int amountOfNodes = amountOfNode(graph);

	int* color = new int[amountOfNodes];
	//-1 kolor bia³y
	//0 kolor szary
	//1 kolor czarny
	int* d = new int[amountOfNodes];
	int* pi = new int[amountOfNodes];


	for (int i = 0; i < amountOfNodes; i++)
	{
		//kolor bialy
		color[i] = -1;
		//odleglosc nieskoczona
		d[i] = -1;
		//poprzednik zaden
		pi[i] = -1;
	}

	color[s] = 0;
	d[s] = 0;
	pi[s] = -1;

	queue* Q = nullptr;
	push(Q, s);
	while (Q != nullptr)
	{
		int u = Q->val;
		nodeGraph* ptrGraph = graph;
		while (ptrGraph != nullptr)
		{
			if (ptrGraph->from == u)
			{
				if (color[ptrGraph->to] == -1)
				{
					color[ptrGraph->to] = 0;
					d[ptrGraph->to] = d[u] + 1;
					pi[ptrGraph->to] = u;
					push(Q, ptrGraph->to);
				}
			}
			ptrGraph = ptrGraph->next;
		}
		pop(Q);
		color[u] = 1;
		cout <<"Tablica kolorow ";
		for (int i = 0; i < amountOfNodes; i++)
		{
			cout << color[i] << " ";
		}
		cout << endl;

		cout << "Tablica poprzednikow ";
		for (int i = 0; i < amountOfNodes; i++)
		{
			cout << pi[i] << " ";
		}
		cout << endl;

		cout << "Tablica odleglosci";
		for (int i = 0; i < amountOfNodes; i++)
		{
			cout << d[i] << " ";
		}
		cout << endl<<endl;
	}
}

int amountOfNode(nodeGraph* H)
{
	int max = -1;
	while (H != NULL)
	{
		if (H->from > max)
			max = H->from;
		H = H->next;
	}
	return max + 1;
	
}

void push(queue*& H, int val)
{
	if (H == nullptr)
	{
		queue* p = new queue;
		p->val = val;
		p->next = H;
		H = p;
	}
	else
	{
		queue* ptr = H;
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		queue* p = new queue;
		p->val = val;
		p->next = ptr->next;
		ptr->next = p;
	}
}

void pop(queue*& H)
{
	if (H != nullptr)
	{
		queue* p = H;
		H = H->next;
		delete p;
	}
}

void algorytmPrima(nodeGraph* graph)
{
	//Pierwszy wierzcho³ek
	int s = graph->from;

	int amountOfNodes = amountOfNode(graph);

	int* color = new int[amountOfNodes];
	//0 kolor bia³y
	//1 kolor szary


	for (int i = 0; i < amountOfNodes; i++)
	{
		//kolor bialy
		color[i] = 0;
	}

	color[s] = 1;

	while (!isAllGray(color, amountOfNodes))
	{
		nodeGraph* minimum = nullptr;
		for (int i = 0; i < amountOfNodes; i++)
		{
			if (color[i] == 1)
			{

			}
		}
	}




}

void bublesort(nodeGraph*& H)
{
	if (H != nullptr && H->next != nullptr)
	{
		nodeGraph* p = H;
		nodeGraph* end = nullptr;
		bool is = true;
		while (is == true)
		{
			is = false;
			if (H->val > H->next->val)
			{
				Swap(H);
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

void swap(nodeGraph*& H, nodeGraph* p)
{
	if (p == nullptr)
	{
		Swap(H);
	}
	else
	{
		if (p != nullptr && p->next != nullptr && p->next->next != nullptr)
		{
			nodeGraph* ptr = p->next;
			p->next = ptr->next;
			ptr->next = ptr->next->next;
			p->next->next = ptr;
		}
	}
}

void Swap(nodeGraph*& H)
{
	if (H != NULL && H->next != NULL)
	{
		nodeGraph* p = H;
		H = H->next;
		p->next = H->next;
		H->next = p;
	}
}

bool isAllGray(int* array, int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		if (array[i] == 0)
			return false;
	}
	return true;
}

void algorytmKuskarla(nodeGraph* graph)
{
	int s = graph->from;

	int amountOfNodes = amountOfNode(graph);

	int* color = new int[amountOfNodes];
	//0 kolor bia³y
	//1 kolor szary
	int* forest = new int[amountOfNodes];
	int forestIterator = 0;


	for (int i = 0; i < amountOfNodes; i++)
	{
		//kolor bialy
		color[i] = 0;
		forest[i] = 0;
	}

	nodeGraph* kuskarlList = nullptr;

	while (graph != nullptr)
	{
		if (color[graph->from] == 0 && color[graph->to] == 0)
		{
			color[graph->from] = 1;
			color[graph->to] = 1;
			forestIterator++;
			forest[graph->from] = forestIterator;
			forest[graph->to] = forestIterator;
			nodeGraph* p = graph;
			graph = graph->next;
			p->next = kuskarlList;
			kuskarlList = p;
		}
		else if ((color[graph->from] != 0) ^ (color[graph->to] != 0))
		{
			color[graph->from] = 1;
			color[graph->to] = 1;
			if (forest[graph->from] == 0)
				forest[graph->from] = forest[graph->to];
			else
				forest[graph->to] = forest[graph->from];
			nodeGraph* p = graph;
			graph = graph->next;
			p->next = kuskarlList;
			kuskarlList = p;
		}
		else if (forest[graph->to] != forest[graph->from])
		{
			int forest1 = forest[graph->to];
			int forest2 = forest[graph->from];
			forestIterator++;
			for (int i = 0; i < amountOfNodes; i++)
			{
				if (forest[i] == forest1 || forest[i] == forest2)
				{
					forest[i] = forestIterator;
				}

			}
			nodeGraph* p = graph;
			graph = graph->next;
			p->next = kuskarlList;
			kuskarlList = p;
		}
		else
		{
			nodeGraph* p = graph;
			graph = graph->next;
			delete p;
		}
	}

	cout << "Lista polaczen algorytmu kuskarla:\n";
	Show(kuskarlList);
}


