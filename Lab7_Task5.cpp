#include<iostream>
using namespace std;

int partCount = 0;

void displayArray(int arr[], int n) {
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(int arr[], int n, int st, int end, int& comparisons) {
	partCount++;
	cout << "Partition " << partCount << ":" << endl;
	int pivot = arr[st];
	cout << "Pivot: " << pivot << endl;
	
	int i = st;
	for(int j=st+1; j<=end; j++) {
		comparisons++;
		if(arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i], arr[st]);
	cout << "Array: ";
	displayArray(arr, n);
	cout << endl;
	return i;
}

void quickSort(int arr[], int n, int st, int end, int& comparisons) {
	if(st >= end) {
		return;
	}
	int pivotIdx = partition(arr, n, st, end, comparisons);
	
	quickSort(arr, n, st, pivotIdx-1, comparisons);
	quickSort(arr, n, pivotIdx+1, end, comparisons);
}

int main() {
	int n = 7;
	int ids[n];
	for(int i=0; i<n; i++) {
		cout << "ID " << i+1 << ": ";
		cin >> ids[i];
	}
	cout << endl;
	
	int comparisons = 0;
	quickSort(ids, n, 0, n-1, comparisons);
	cout << "Total Element Comparisons: " << comparisons << endl;
	return 0;
}
