#include <iostream>
#include <chrono>

#define LENGHT_ARRAY 1000

using namespace std::chrono;
using namespace std;

void createRandomArray(int* array, int l);
void createSortedArray(int* array, int l);
void createReverseSortedArray(int* array, int l);

void copyArray(int* array, int* array2, int l);

void bubbleSort(int* array, int l, int r);

void heapSort(int tab[], int arraySize);
void heapify(int n, int tab[], int heapsize);

void quickSort(int* array, int l, int r);
int partition(int* array, int l, int r);

void quickSortHybrid(int* array, int l, int r);
void bubbleSort(int* array, int l, int r);


int main()
{
	srand(time(NULL));
	cout << "hello word\n";

	//int array[LENGHT_ARRAY];
	//int array2[LENGHT_ARRAY];

	int* array = new int[LENGHT_ARRAY];
	int* array2 = new int[LENGHT_ARRAY];

	createRandomArray(array, LENGHT_ARRAY);
	//createSortedArray(array, LENGHT_ARRAY);
	//createReverseSortedArray(array, LENGHT_ARRAY);
	copyArray(array, array2, LENGHT_ARRAY);

	auto start = high_resolution_clock::now();
	bubbleSort(array2, 0, LENGHT_ARRAY - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout <<"Czas pracy bubble sorta: \t\t"<< duration.count() << " mikrosekund" << endl;

	copyArray(array, array2, LENGHT_ARRAY);

	start = high_resolution_clock::now();
	heapSort(array2, LENGHT_ARRAY);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Czas pracy heap sort: \t\t\t" << duration.count() << " mikrosekund" << endl;

	copyArray(array, array2, LENGHT_ARRAY);

	start = high_resolution_clock::now();
	quickSort(array2, 0, LENGHT_ARRAY - 1);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Czas pracy quick sort: \t\t\t" << duration.count() << " mikrosekund" << endl;

	copyArray(array, array2, LENGHT_ARRAY);

	start = high_resolution_clock::now();
	quickSortHybrid(array2, 0, LENGHT_ARRAY - 1);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Czas pracy hybrydowego quick sort : \t" << duration.count() << " mikrosekund" << endl;

	delete[] array;
	delete[] array2;

	system("pause");
	return 0;

}

void createRandomArray(int* array, int l)
{
	for (int i = 0; i < l; i++)
	{
		array[i] = rand() % 1000;
	}
}

void createSortedArray(int* array, int l)
{
	for (int i = 0; i < l; i++)
	{
		array[i] = i + 1;
	}
}

void createReverseSortedArray(int* array, int l)
{
	for (int i = 0; i < l; i++)
	{
		array[i] = l - i;
	}
}

void copyArray(int* array, int* array2, int l)
{
	for (int i = 0; i < l; i++)
	{
		array2[i] = array[i];
	}
}

void quickSortHybrid(int* array, int l, int r)
{
	if (r - l > 10)
	{
		int p = partition(array, l, r);
		quickSort(array, l, p - 1);
		quickSort(array, p + 1, r);
	}
	else
		bubbleSort(array, l, r);
}

void bubbleSort(int* tab, int l, int r) {
	bool is = true;
	int lastIndex = r;
	while (is == true)
	{
		is = false;
		int i = l;
		while (i < r && i != lastIndex)
		{
			if (tab[i] > tab[i + 1])
			{
				swap(tab[i], tab[i + 1]);
				/*int temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;*/
				is = true;
				lastIndex = i;
			}
			i++;
		}
	}

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

void quickSort(int* array, int l, int r)
{
	if (l < r)
	{
		int p = partition(array, l, r);
		quickSort(array, l, p - 1);
		quickSort(array, p + 1, r);
	}
}

int partition(int* array, int l, int r)
{
	int x = array[l];
	int i = l, j = r + 1;
	while (true)
	{
		do ++i; while (i <= r && array[i] < x);
		do --j; while (array[j] > x);
		if (i > j)
			break;
		swap(array[i], array[j]);
	}

	array[l] = array[j];
	array[j] = x;
	return j;
}