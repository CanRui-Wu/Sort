#include <iostream>
#include <random>
#include <ctime>
using namespace std;

template<typename T> //Every type with operator "<" can be used this function to sort.
void quickSort(T *array,int length) {
	static default_random_engine e(time(0));
	if(array == NULL || length <= 1)
		return;
	uniform_int_distribution<unsigned> u(0,length-1);
	int random_index = u(e);
	swap(array[random_index],array[length-1]);
	int left = 0,right = length-1;
	bool left_or_right = true;
	while(left < right) { //In the whole iteration,left < right,and they both fall in [0,lenght-1]
		if(left_or_right) {
			if(array[length-1] < array[left]) 
				left_or_right = !left_or_right;
			else
				left++;
		} else {
			right--;
			if(array[right] < array[length-1]) { //Right should not move after swap. This ensures array[left] >= array[length-1] after iteration.
				left_or_right = !left_or_right;
				swap(array[left],array[right]);
			}
		}
	}
	swap(array[left],array[length-1]);
	quickSort(array,left);
	quickSort(array+left+1,length-left-1);
}

int main () {
	double a[9] = {2,2,2,2,2,2,2,2,2};
	quickSort(a,9);
	cout << "***Final Result***" << endl;
	for(int i = 0;i < 9;i++)
		cout << a[i] << endl;
}