#include <iostream>
using namespace std;

template<typename T>
void shellSort(T *array,int length) {
	if(array == NULL || length <= 1)
		return;
	int gap = length/2;
	while(gap != 0) {
		for(int i = gap;i < length;i++) {
			T temp = array[i];
			int current = i;
			while(current-gap >= 0 && temp < array[current-gap]) {
				array[current] = array[current-gap];
				current -= gap;
			}
			array[current] = temp;
		}
		gap = gap/2;
	}
}

int main () {
	int a[10] = {3,2,5,6,6,2,1,1,1};
	shellSort(a,10);
	for(int i = 0;i < 10;i++)
		cout << a[i] << " ";
	cout << endl;
}