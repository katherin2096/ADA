#include <iostream>

int array[] = { 95, 45, 48, 98, 1, 485, 65, 478, 1, 2325 };
int n = sizeof(array) / sizeof(array[0]);

void printArray(int *array, int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << array[i] << std::endl;
}

void quickSort(int *array, int low, int high)
{
	int i = low;
	int j = high;
	int pivot = array[(i + j) / 2];
	int temp;

	while (i <= j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i <= j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			j--;
		}
	}
	if (j > low)
		quickSort(array, low, j);
	if (i < high)
		quickSort(array, i, high);
}


void merge(int *array, int low, int mid, int high)
{

	int temp[n];
	int i = low;
	int j = mid + 1;
	int k = 0;

	while (i <= mid && j <= high)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];
	while (j <= high)
		temp[k++] = array[j++];
	k--;
	while (k >= 0)
	{
		array[k + low] = temp[k];
		k--;
	}
}

void mergeSort(int *array, int low, int high)
{
	int mid;

	if (low < high)
	{
		mid = (low + high) / 2;
		mergeSort(array, low, mid);
		mergeSort(array, mid + 1, high);
		merge(array, low, mid, high);
	}
}



int main()
{
	//int array[] = { 95, 45, 48, 98, 1, 485, 65, 478, 1, 2325 };
	//int n = sizeof(array) / sizeof(array[0]);

	std::cout << "Antes Quick Sort :" << std::endl;
	printArray(array, n);

	quickSort(array, 0, n);

	std::cout << "Despues Quick Sort :" << std::endl;
	printArray(array, n);

//	int n = sizeof(array) / sizeof(array[0]);

	std::cout << "Before Merge Sort :" << std::endl;
	printArray(array, n);
	mergeSort(array, 0, n - 1);
	std::cout << "After Merge Sort :" << std::endl;
	printArray(array, n);
	system("pause");
	return 0;
}