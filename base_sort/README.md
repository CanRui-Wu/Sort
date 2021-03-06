基础排序
=======
一些思路最简单的排序，一般不会用上，里面蕴含一些高级排序的思想，是排序的发展过程。<br />

选择排序
=======
最简单，思路最直接的排序方法，最好，最坏以及平均时间复杂度都是O(n^2)。<br />
选择排序的思想为，每次选择出当前最小(大)元素，n-1次正确选择后，排序完成。<br />
分为有序区和无序区，初始有序区长度为0，无序区长度为n，有序区在左，无序区在右。<br />
每次从当前无序区选出最小元素，放到有序区末尾。<br />
选择排序不是稳定排序，序列\[2,2,1\]，第一个2会在第一轮选择中与1交换排到后面去。<br />
![链接已失效](https://github.com/CanRui-Wu/Sort/blob/master/base_sort/select_sort.gif)

插入排序
========
在数组基本有序时，速度基本上是最快的排序。<br />
插入排序的思路为，每次将当前元素插入到有序序列的正确位置,初始为一个元素，n-1次正确插入后，排序完成。<br />
分为有序区和无序区，初始有序区长度为0，无序区长度为n，有序区在左，无序区在右。<br />
每次将当前元素插入到有序区中的正确位置，该位置所有元素往后移一位。<br />
![链接已失效](https://github.com/CanRui-Wu/Sort/blob/master/base_sort/insert_sort.gif)

冒泡排序
========
冒泡排序和选择排序类似，每次确定当前序列最大(小)元素，但是它可以提前检测终止，最好时间复杂度为O(n)，不过交换次数远大于选择。<br />
冒泡排序为，从左向右对每一对相邻元素比较，如果前面比后面大，则交换它们，那么当前最大元素会出现则末尾，n-1轮冒泡后，排序完成。<br />
分为有序区和无序区，初始有序区长度为0，无序区长度为n，有序区在右，无序区在左。<br />
每次通过交换将无序区最大元素冒泡到有序区的头部前面（无序区的末尾)。<br />
![链接已失效](https://github.com/CanRui-Wu/Sort/blob/master/base_sort/bubble_sort.gif)




