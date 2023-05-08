#include <bits/stdc++.h>
using namespace std;
#define TAM 6

int partition(int arr[], int l, int r)
{
	int pivot = arr[r];

	int i = (l - 1);

	for (int j = l; j <= r - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

void quickSort(int arr[], int l, int r)
{
	if (l < r) {
		int p = partition(arr, l, r);

		quickSort(arr, l, p - 1);
		quickSort(arr, p + 1, r);
	}
}

int main()
{
	int arr[TAM] = { 10, 7, 8, 9, 1, 5 };

	quickSort(arr, 0, TAM - 1);
	cout << "Array ordenado: " << endl;
	for (int i = 0; i < TAM; i++)
		cout << arr[i] << " ";
	return 0;
}
