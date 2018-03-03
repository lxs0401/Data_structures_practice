/*
by bLue
Last Updated: 03/23/2017
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
	int a[8] = {1, 6, 4, 2, 3, 2, 3, 3};
	sort(a, a+8); // 二分查找函数需要首先保证有序
	printf("当前数组：\n");
	for(int i=0; i<8; ++i) {
		if(i) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n\n");

	// binary_search(begin, end, key) 如果能找到返回真，否则返回假
	printf("binary_search\n");
	printf("查找 3: %s\n", binary_search(a, a+8, 3)?"yes":"no");
	printf("查找 8: %s\n", binary_search(a, a+8, 8)?"yes":"no");
	printf("\n");

	// lower_bound(begin, end, key) 返回第一个大于等于 key 的元素的迭代器
	printf("lower_bound\n");
	printf("查找 2，下标为：%ld\n", lower_bound(a, a+8, 2)-a); // 可以理解为返回了地址，转换为下标需 -a
	printf("查找 3，下标为：%ld\n", lower_bound(a, a+8, 3)-a);
	printf("查找 5，下标为：%ld\n", lower_bound(a, a+8, 5)-a); // 找到了第一个 6 的位置
	printf("查找 8，下标为：%ld\n", lower_bound(a, a+8, 8)-a); // 找不到，返回 end（a[n]，已越界)
	printf("\n");

	// upper_bound(begin, end, key) 返回第一个大于 key 的元素的迭代器
	printf("upper_bound\n");
	printf("查找 2，下标为：%ld\n", upper_bound(a, a+8, 2)-a); // 找到了第一个 3 的位置
	printf("查找 3，下标为：%ld\n", upper_bound(a, a+8, 3)-a); // 找到了第一个 4 的位置
	printf("查找 5，下标为：%ld\n", upper_bound(a, a+8, 5)-a); // 找到了第一个 6 的位置
	printf("查找 8，下标为：%ld\n", upper_bound(a, a+8, 8)-a);
	
	return 0;
}