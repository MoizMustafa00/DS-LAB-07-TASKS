#include<iostream>
using namespace std;

void displayArray(int arr[], int n) {
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(int arr[], int n, int st, int end, int& partCount) {
	int pivot = arr[end];
	cout << "Pivot: " << pivot << endl;
	cout << "Subarray Start: " << st << endl;
	cout << "Subarray End: " << end << endl;
	
	int i = st - 1;
	for(int j=st; j<end; j++) {
		if(arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	i++;
	swap(arr[i], arr[end]);
	partCount++;
	cout << "Partition " << partCount << ":" << endl;
	displayArray(arr, n);
	cout << endl;
	return i;
}

void quickSort(int arr[], int n, int st, int end, int& partCount) {
	if(st >= end) {
		return;
	}
	int pivotIdx = partition(arr, n, st, end, partCount);
	
	quickSort(arr, n, st, pivotIdx-1, partCount);
	quickSort(arr, n, pivotIdx+1, end, partCount);
}

int main() {
	int n = 7;
	int marks[n];
	for(int i=0; i<n; i++) {
		cout << "Student " << i+1 << " Marks: ";
		cin >> marks[i];
	}
	cout << endl;
	
	int partitionCount = 0;
	quickSort(marks, n, 0, n-1, partitionCount);
	cout << "Total Partition Calls: " << partitionCount << endl;
	return 0;
}
