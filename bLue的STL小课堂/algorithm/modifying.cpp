/*
by bLue
Last Updated: 03/23/2017
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
	int n1 = 2, n2 = 3;
	int a[3] = {1, 2, 3};

	// swap(a, b) 交换 2 个变量的值
	printf("swap\n");
	printf("直接交换两个变量的值\n");
	printf("交换前：n1 = %d, n2 = %d\n", n1, n2);
	swap(n1, n2);
	printf("交换后：n1 = %d, n2 = %d\n", n1, n2);
	printf("交换数组中的元素 a[0] 和 a[1]\n");
	printf("交换前：");
	for(int i=0; i<3; ++i) {
		if(i) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	swap(a[0], a[1]);
	printf("交换后：");
	for(int i=0; i<3; ++i) {
		if(i) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n\n");

	// reverse(begin, end) 反转
	printf("reverse\n");
	printf("反转前：");
	int b[5] = {1, 2, 3, 2, 5};
	for(int i=0; i<5; ++i) {
		if(i) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n");
	reverse(b, b+5);
	printf("反转后：");
	for(int i=0; i<5; ++i) {
		if(i) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n\n");

	// unique(begin, end) 去重，需要保证有序，返回去重后的 end
	printf("unique\n");
	printf("去重前：");
	int c[6] = {1, 2, 3, 2, 3, 2};
	sort(c, c+6);
	for(int i=0; i<6; ++i) {
		if(i) printf(" ");
		printf("%d", c[i]);
	}
	printf("\n");
	int new_len = unique(c, c+6)-c;
	printf("去重后：");
	for(int i=0; i<new_len; ++i) {
		if(i) printf(" ");
		printf("%d", c[i]);
	}
	printf("\n");
	printf("去重后数组 c 的长度：%d\n", new_len);
	
	return 0;
}