#include <iostream>
using namespace std;

//左右子树都是最大堆，从上至下调整使得最大堆, root是要调整的树的根节点，length是无序区的长度
template<typename T>
void adjust(T *array,int root,int length) {
	if(length == 0)
		return;
	int left_child = 2*root+1;
	int right_child = 2*root+2;
	int left_adjust = 1,right_adjust = 1;
	if(left_child >= length || !(array[root] < array[left_child]))
		left_adjust = 0;
	if(right_child >= length || !(array[root] < array[right_child]))
		right_adjust = 0;
	if(left_adjust+right_adjust == 0)
		return;
	else if(left_adjust*right_adjust == 1) {
		if(array[left_child] >= array[right_child])
			right_adjust = 0;
		else
			left_adjust = 0;
	}
	if(left_adjust) {
		swap(array[left_child],array[root]);
		adjust(array,left_child,length);
	} else {
		swap(array[right_child],array[root]);
		adjust(array,right_child,length);
	}
}

//heapsort主递归，每一次将无序区最后一个元素与堆顶元素交换
//将堆顶元素加入有序区，因此有序区加1,无序区减1，无序区只剩一个元素的时候递归终止
template<typename T>
void heapSortMain(T *array,int length) {
	if(length <= 1)
		return;
	swap(array[0],array[length-1]);
	adjust(array,0,length-1);
	heapSortMain(array,length-1);
}

//入口函数，array是待排序的数组，length是其长度
template<typename T>
void heapSort(T *array,int length) {
	if(array == NULL || length <= 1)
		return;
	for(int i = (length-2)/2;i >= 0;i--)
		adjust(array,i,length);
	heapSortMain(array,length);
}

int main() {
	int a[10] = {7,6,3,4,5,8};
	heapSort(a,10);
	for(int i = 0;i < 10;i++)
		cout << a[i] << " ";
	cout << endl;
}