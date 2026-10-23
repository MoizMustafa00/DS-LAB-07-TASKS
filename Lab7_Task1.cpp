#include<iostream>
using namespace std;

void displayArray(int arr[], int n) {
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void merge(int arr[], int n, int st, int mid, int end) {
	int tempSize = end - st + 1;
	int temp[tempSize];
	int tempIdx = 0;
	int i = st;
	int j = mid+1;
	while(i <= mid && j <= end) {
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
	cout << "Merged [" << st << " - " << end << "]: ";
	displayArray(arr, n);
}

void mergeSort(int arr[], int n, int st, int end, int& countMerge) {
	if(st >= end) {
		return;
	}
	int mid = st + (end - st) / 2;
	
	mergeSort(arr, n, st, mid, countMerge);
	mergeSort(arr, n, mid+1, end, countMerge);
	merge(arr, n, st, mid, end);
	countMerge++;
}

int main() {
	int arr[8] = {78, 45, 92, 63, 45, 88, 51, 70};
	int n = sizeof(arr) / sizeof(int);
	int start = 0;
	int end = n-1;
	int countMerge = 0;
	
	mergeSort(arr, n, start, end, countMerge);
	cout << "Total Merge Operations: " << countMerge << endl;
	return 0;
}
