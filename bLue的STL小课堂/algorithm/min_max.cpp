/*
by bLue
Last Updated: 03/23/2017
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct info {
	int p;
	double q;
	bool operator < (const info &cmp) const {
		if(p != cmp.p) return p < cmp.p;
		else return q > cmp.q;
	}
} b[5];

bool cmp(info a, info b) {
	if(a.p != b.p) return a.p < b.p;
	else return a.q > b.q;
}

int main(int argc, char const *argv[]) {
	// min(a, b), max(a, b) 返回 a, b 中的最大/最小值
	printf("min/max\n");
	int n1 = 3, n2 = 5;
	printf("int n1 = %d, n2 = %d\n", n1, n2);
	printf("min(n1, n2) = %d\n", min(n1, n2));
	printf("max(n1, n2) = %d\n", max(n1, n2));
	// 对于自定义结构体，可以写比较函数或重载小于号运算符来实现比较
	info n3 = (info){10, 2.5};
	info n4 = (info){20, 2.333333};
	printf("info n3 = {%d, %f}\n", n3.p, n3.q);
	printf("info n4 = {%d, %f}\n", n4.p, n4.q);
	info res_min = min(n3, n4);
	info res_max = max(n3, n4);
	printf("min(n3, n4) = {%d, %f}\n", res_min.p, res_min.q);
	printf("max(n3, n4) = {%d, %f}\n", res_max.p, res_max.q);
	printf("\n");

	// min_element(begin, end), max_element(begin, end) 返回最小的元素/最大的元素的迭代器
	printf("min_element/max_element\n");
	int a[5] = {1, 4, 5, 2, 3};
	printf("int 数组 a: ");
	for(int i=0; i<5; ++i) {
		if(i) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	printf("最小元素的下标：%ld\n", min_element(a, a+5)-a);
	printf("最大元素的下标：%ld\n", max_element(a, a+5)-a);
	b[0] = (info){1, 300.5};
	b[1] = (info){2, 200.875};
	b[2] = (info){3, 666.666666};
	b[3] = (info){5, 100.25};
	b[4] = (info){5, 2333.333333};
	printf("结构体数组 b:\n");
	for(int i=0; i<5; ++i) {
		printf("{%d, %f}\n", b[i].p, b[i].q);
	}
	printf("自定义小于的比较规则为：第一关键字 p 小于，第二关键字 q 大于\n");
	printf("最小元素的下标：%ld\n", min_element(b, b+5)-b);
	printf("最大元素的下标：%ld\n", max_element(b, b+5)-b);
	
	return 0;
}