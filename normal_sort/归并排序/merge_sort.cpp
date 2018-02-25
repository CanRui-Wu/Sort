#include <iostream>
using namespace std;

template<typename T>
void mergeSortMain(T *array,T *sup_array,int length) {
	if(array == NULL || length <= 1)
		return;
	int mid = (length-1)/2;
	mergeSortMain(array,sup_array,mid+1);
	mergeSortMain(array+mid+1,sup_array,length-mid-1);
	int left = 0,right = mid+1;
	for(int i = 0;i < length;i++)
		sup_array[i] = array[i];
	for(int i = 0;i < length;i++) { //使用额外的空间合并两个有序的数组
		if(right != length && sup_array[right] < sup_array[left] || left == mid+1) {
			array[i] = sup_array[right];
			right++;
		} else {
			array[i] = sup_array[left];
			left++;
		}
	}
}

template<typename T>
void mergeSort(T *array,int length) {
	if(array == NULL || length <= 1)
		return;
	T *sup_array = new T[length];
	mergeSortMain(array,sup_array,length);
	delete sup_array;
}

int main() {
	int a[15] = {1,9,8,5,6,7,8,9};
	mergeSort(a,15);
	cout << "***Final result" << endl;
	for(int i = 0;i < 15;i++)
		cout << a[i] << endl;
}