#include <iostream>

using namespace std;

void heapSort(int tab[], int arraySize);

void heapify(int n, int tab[], int heapsize);

int main()
{
	int array[11];

	array[0] = 10;
	array[1] = 8;
	array[2] = 7;
	array[3] = 5;
	array[4] = 1;
	array[5] = 4;
	array[6] = 6;
	array[7] = 12;
	array[8] = 14;
	array[9] = 8;
	array[10] = 3;


	for (int i = 0; i < 11; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	heapSort(array, 11);

	for (int i = 0; i < 11; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
	system("pause");

	return 0;
}

void heapSort(int tab[], int arraySize)
{
	int heapsize = arraySize;
	for (int i = (arraySize / 2) - 1; i >= 0; i--)
		heapify(i, tab, arraySize);
	while (heapsize > 1)
	{
		swap(tab[0], tab[heapsize - 1]);
		heapsize--;
		heapify(0, tab, heapsize);
	}
}

void heapify(int n, int tab[], int heapsize)
{
	int l = 2 * n + 1;
	int r = 2 * n + 1 + 1;
	int largest = 0;

	if (l < heapsize && tab[l] > tab[n])
		largest = l;
	else
		largest = n;

	if (r < heapsize && tab[r] > tab[largest])
		largest = r;
	if (largest != n)
	{
		swap(tab[n], tab[largest]);
		heapify(largest, tab, heapsize);
	}
}