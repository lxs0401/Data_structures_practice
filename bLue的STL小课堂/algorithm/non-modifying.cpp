/*
by bLue
Last Updated: 03/23/2017
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
	int a[6] = {3, 2, 1, 2, 3, 3};

	// find(begin, end, key) 返回第一个等于 key 的元素的迭代器
	printf("find\n");
	printf("查找 1，下标为：%ld\n", find(a, a+6, 1)-a);
	printf("查找 2，下标为：%ld\n", find(a, a+6, 2)-a);
	printf("查找 3，下标为：%ld\n", find(a, a+6, 3)-a);
	printf("查找 4，下标为：%ld\n", find(a, a+6, 4)-a); // 找不到，返回 end（a[n]，已越界)

	// count(begin, end, key) 返回值为 key 的元素的数量
	printf("count\n");
	printf("查找 1，数量为：%ld\n", count(a, a+6, 1));
	printf("查找 2，数量为：%ld\n", count(a, a+6, 2));
	printf("查找 3，数量为：%ld\n", count(a, a+6, 3));
	printf("查找 4，数量为：%ld\n", count(a, a+6, 4));
	
	return 0;
}