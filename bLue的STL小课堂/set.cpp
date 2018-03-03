/*
by bLue
Last Updated: 03/23/2017
*/

/*
常用函数
s.insert(x)		// 插入一个元素
s.clear()		// 清空所有元素
s.erase(x)		// 删除指定元素
s.empty()		// 判断是否为空
s.count(x)		// 返回某个元素出现的次数
s.size()		// 返回元素个数
*/

#include <cstdio>
#include <set>
using namespace std;

int main(int argc, char const *argv[]) {
	// set<T> name
	// set 会自动排序
	set<int> s; // 创建一个空的 set
	// set<int, greater<int> > s; // 创建一个空的 set（降序）
	printf("当前 set s 是否为空：%s\n", s.empty()?"yes":"no");
	printf("插入 2 次 3\n");
	s.insert(3);
	s.insert(3);
	printf("插入 1\n");
	s.insert(1);
	printf("插入 2\n");
	s.insert(2);	
	printf("s 当前长度：%lu\n", s.size());
	printf("迭代器方式遍历 s: ");
	set<int>::iterator it;
	for(it=s.begin(); it!=s.end(); ++it) {
		if(it != s.begin()) printf(" ");
		printf("%d", *it); // 类似指针的方式访问元素的值
	}
	printf("\n\n");

	printf("查找 3 是否存在于 s：%s\n", s.count(3)?"yes":"no");
	printf("查找 4 是否存在于 s：%s\n", s.count(4)?"yes":"no");
	printf("二分查找第一个大于等于 1 的值：%d\n", *s.lower_bound(1));
	printf("二分查找第一个大于等于 4 的值：%s\n", s.lower_bound(4)==s.end()?"not found":"found");
	printf("二分查找第一个大于 1 的值：%d\n", *s.upper_bound(1));
	printf("\n");

	printf("删除 2: ");
	s.erase(2);
	for(it=s.begin(); it!=s.end(); ++it) {
		if(it != s.begin()) printf(" ");
		printf("%d", *it);
	}
	printf("\n\n");
	printf("清空 s\n");
	s.clear();
	printf("清空后 s 的长度：%lu\n", s.size());
	
	return 0;
}