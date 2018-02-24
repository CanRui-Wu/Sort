#include <iostream>
using namespace std;

template<typename T>
void bubbleSort(T *array,int length) {
	if(array == NULL || length <= 1)
		return;
	int ok = 0;
	for(int i = length-1;i > 0 && !ok;i--) { 
		ok = 1;
		for(int j = 0;j < i;j++) {
			if(array[j+1] < array[j]) {
				swap(array[j],array[j+1]);
				ok = 0;
			}
		}
	}
}

template<typename T>
void selectSort(T *array,int length) {
	if(array == NULL || length <= 1)
		return;
	for(int i = 0;i < length-1;i++) { 
		int min_index = i;
		T min_value = array[i];
		for(int j = i+1;j < length;j++) {
			if(array[j] < min_value) {
				min_value = array[j];
				min_index = j;
			}
		}
		swap(array[i],array[min_index]);
	}
}

template<typename T>
void insertSort(T *array,int length) {
	if(array == NULL || length <= 1)
		return;
	for(int i = 1;i < length;i++) {
		T temp = array[i];
		int insert_pos = i-1;
		while(temp < array[insert_pos]) {
			array[insert_pos+1] = array[insert_pos];
			insert_pos--;
		}
		array[insert_pos+1] = temp;
	}
}

int main() {
	int a[12] = {3,3,3,3,4,4,4,4,2,2,2,2};
	//bubbleSort(a,12);
	insertSort(a,12);
	for(int i = 0;i < 12;i++)
		cout << a[i] << " ";
	cout << endl;
}