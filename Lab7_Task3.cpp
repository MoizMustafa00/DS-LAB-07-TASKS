#include<iostream>
using namespace std;

void merge(int arr[], int st, int mid, int end, int& comparisons) {
	int tempSize = end - st + 1;
	int* temp = new int[tempSize];
	int tempIdx = 0;
	int i = st;
	int j = mid + 1;
	
	while(i <= mid && j <= end) {
		comparisons++;
		if(arr[i] <= arr[j]) {
			temp[tempIdx] = arr[i];
			tempIdx++;
			i++;
		}
		else {
			temp[tempIdx] = arr[j];
			tempIdx++;
			j++;	
		}
	}
	while(i <= mid) {
		temp[tempIdx] = arr[i];
		tempIdx++;
		i++;
	}
	while(j <= end) {
		temp[tempIdx] = arr[j];
		tempIdx++;
		j++;
	}
	for(int k=0; k<tempSize; k++) {
		arr[st + k] = temp[k];
	}
	delete[] temp;
}

void mergeSort(int arr[], int st, int end, int& recCalls, int& mergeOps, int& comparisons) {
	if(st >= end) {
		return;
	}
	int mid = st + (end - st) / 2;
	
	mergeSort(arr, st, mid, recCalls, mergeOps, comparisons);
	recCalls++;
	mergeSort(arr, mid+1, end, recCalls, mergeOps, comparisons);
	recCalls++;
	merge(arr, st, mid, end, comparisons);
	mergeOps++;
}

int main() {
	int n;
	cout << "Enter Number of Elements: ";
	cin >> n;
	if(n <= 0) {
		cout << "Invalid Number of Elements!" << endl;
		exit(1);
	}
	
	int* arr = new int[n];
	for(int i=0; i<n; i++) {
		cout << "Element " << i+1 << ": ";
		cin >> arr[i];
	}
	
	int st = 0;
	int end = n-1;
	int recursiveCalls = 0;
	int mergeOps = 0;
	int comparisons = 0;
	mergeSort(arr, st, end, recursiveCalls, mergeOps, comparisons);
	
	cout << "Sorted Array: ";
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Total Recursive Calls: " << recursiveCalls << endl;
	cout << "Total Merge Operations: " << mergeOps << endl;
	cout << "Total Element Comparisons: " << comparisons << endl;
	
	delete[] arr;
	return 0;
}
