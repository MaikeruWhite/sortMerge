#include <iostream>

using namespace std;

void merge(int A[], int low, int mid, int high)
{
	int i, j, k;
	int* c = new int[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (A[i] < A[j])
		{
			c[k] = A[i];
			k++;
			i++;
		}
		else
		{
			c[k] = A[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = A[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = A[j];
		k++;
		j++;
	}
	for (i = low, k = 0; i <= high; i++, k++)
	{
		A[i] = c[k];
	}
	delete c;
}

void sort(int a[], int low, int high) {
	if (low < high) {
		int mid;
		mid = (low + high) / 2;
		sort(a, low, mid);
		sort(a, mid + 1, high);
		merge(a, low, mid, high);
	}
	return;
}

int main() {
	int n;
	cout << "Enter array size: ";
	cin >> n;
	int* a = new int[n];
	cout << "Enter array values: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, 0, n - 1);
	cout << "Sorted array: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	delete a;
	return 0;
}