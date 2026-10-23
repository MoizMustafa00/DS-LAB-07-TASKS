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
	for(int i=1; i<10; i++) {
		count[i] += count[i-1];
	}
	for(int i=n-1; i>=0; i--) {
		output[--count[(arr[i] / exp) % 10]] = arr[i];
	}
	for(int i=0; i<n; i++) {
		arr[i] = output[i];
	}
}

void radixSort(int arr[], int n) {
	int max = getMax(arr, n);
	int pass = 0;
	
	for(int exp=1; max/exp>0; exp*=10) {
		countSort(arr, n, exp);
		cout << "Pass " << ++pass << ":" << endl;
		displayArray(arr, n);
		cout << endl;
	}
}

int main() {
	int n = 7;
	int arr[n] = {91, 8, 1024, 56, 305, 7, 120};
	radixSort(arr, n);
	return 0;
}
