#include<iostream>
using namespace std;

void displayArray(int arr[], int n) {
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int getMax(int arr[], int n) {
	int max = arr[0];
	for(int i=1; i<n; i++) {
		if(arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

void countSort(int arr[], int n, int exp) {
	int output[n];
	int count[10] = {0};
	
	for(int i=0; i<n; i++) {
		++count[(arr[i] / exp) % 10];
	}
	cout << "Frequency Count: ";
	displayArray(count, 10);
	
	for(int i=1; i<10; i++) {
		count[i] += count[i-1];
	}
	cout << "Cumulative Count: ";
	displayArray(count, 10);
	
	for(int i=n-1; i>=0; i--) {
		output[--count[(arr[i] / exp) % 10]] = arr[i];
	}
	cout << "Output Array: ";
	displayArray(output, n);
	
	for(int i=0; i<n; i++) {
		arr[i] = output[i];
	}
	cout << "Output Array Copied into Original Array: ";
	displayArray(arr, n);
}

void radixSort(int arr[], int n, int& totalPasses) {
	int max = getMax(arr, n);
	
	for(int exp=1; max/exp>0; exp*=10) {
		cout << "Pass " << ++totalPasses << ":" << endl;
		countSort(arr, n, exp);
		cout << endl;
	}
}

int main() {
	int n = 12;
	int trackingIDs[n] = {4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100};
	
	cout << "Original Array: ";
	displayArray(trackingIDs, n);
	cout << endl;
	
	int totalPasses = 0;
	radixSort(trackingIDs, n, totalPasses);
	cout << "Total Digit Passes: " << totalPasses << endl;
	return 0;
}
