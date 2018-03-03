/*
by bLue
Last Updated: 03/23/2017
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

struct info1 {
	int p;
	double q;
} c[5];

struct info2 {
	int p;
	char s[10];
	bool operator < (const info2 &cmp) const {
		if(p != cmp.p) return p < cmp.p;
		else return strcmp(s, cmp.s)<0;
	}
} d[5];

bool cmp(info1 a, info1 b) {
	if(a.p != b.p) return a.p < b.p;
	else return a.q > b.q;
}

int main(int argc, char const *argv[]) {
	int a[5] = {1, 5, 4, 2, 3};
	sort(a, a+5);
	printf("a[] 升序排序：\n");
	for(int i=0; i<5; ++i) {
		if(i) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n\n");

	int b[5] = {1, 5, 4, 2, 3};
	sort(b, b+5, greater<int>());
	printf("b[] 降序排序：\n");
	for(int i=0; i<5; ++i) {
		if(i) printf(" ");
		printf("%d", b[i]);
	}
	printf("\n\n");
	
	c[0] = (info1){1, 300.5};
	c[1] = (info1){2, 200.875};
	c[2] = (info1){5, 100.25};
	c[3] = (info1){3, 666.666666};
	c[4] = (info1){2, 2333.333333};
	printf("c[] 先按 p 升序排序，如果相同再按 q 降序排序（使用比较函数）：\n");
	sort(c, c+5, cmp);
	for(int i=0; i<5; ++i) {
		printf("%d %f\n", c[i].p, c[i].q);
	}
	printf("\n");

	d[0] = (info2){20, "abc"};
	d[1] = (info2){20, "abd"};
	d[2] = (info2){10, "ab"};
	d[3] = (info2){50, "abcde"};
	d[4] = (info2){10, "abc"};
	printf("d[] 先按 p 升序排序，如果相同再按 s 字典序升序排序（使用运算符重载）：\n");
	sort(d, d+5);
	for(int i=0; i<5; ++i) {
		printf("%d %s\n", d[i].p, d[i].s);
	}
	
	return 0;
}