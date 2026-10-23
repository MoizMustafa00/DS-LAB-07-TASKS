#include<iostream>
using namespace std;

void displaySubarrays(int arr[], int st, int mid, int end) {
	cout << "Left Subarray: ";
	for(int i=st; i<=mid; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	cout << "Right Subarray: ";
	for(int j=mid+1; j<=end; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
}

void merge(int arr[], int st, int mid, int end, int& comparisons) {
	displaySubarrays(arr, st, mid, end);

	int tempSize = end - st + 1;
	int temp[tempSize];
	int tempIdx = 0;
	int i = st;
	int j = mid+1;
	
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
}

void mergeSort(int arr[], int st, int end, int& comparisons) {
	if(st >= end) {
		return;
	}
	int mid = st + (end - st) / 2;
	
	mergeSort(arr, st, mid, comparisons);
	mergeSort(arr, mid+1, end, comparisons);
	merge(arr, st, mid, end, comparisons);
}

int main() {
	int prices[8] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
	int n = sizeof(prices) / sizeof(int);
	int start = 0;
	int end = n-1;
	int comparisons = 0;
	
	mergeSort(prices, start, end, comparisons);
	cout << "Sorted Prices: ";
	for(int i=0; i<n; i++) {
		cout << prices[i] << " ";
	}
	cout << endl;
	cout << "Total Comparisons: " << comparisons << endl;
	return 0;
}
