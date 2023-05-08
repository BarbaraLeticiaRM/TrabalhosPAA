#include <bits/stdc++.h>
using namespace std;
#define TAM 12

int partition(int arr[], int l, int r)
{
	int pivot = arr[r];

	int i = l;

	for (int j = l; j <= r - 1; j++) {
		if (arr[j] < pivot) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i], arr[r]);
	return i;
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
	int arr[TAM] = { 10, 7, 8, 9, 1, 5, 9, 17, 19, 25, 38, 42 };

	quickSort(arr, 0, TAM - 1);
	cout << "Array ordenado: " << endl;
	for (int i = 0; i < TAM; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
