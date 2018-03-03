/*
by bLue
Last Updated: 03/23/2017
*/

/*
常用函数
v.at(idx)			// 返回下标为 idx 的元素，如果 idx 越界，抛出 out_of_range
v.clear()			// 清空所有元素
v.erase(pos)		// 删除 pos 位置的元素，返回下一个元素的位置
v.erase(begin, end)	// 删除 begin 到 end 的所有元素，返回下一个元素的位置
v.empty()			// 判断是否为空
v.front()			// 返回第一个元素
v.back() 			// 返回最后一个元素，不检查这个元素是否存在
v.pop_back()		// 删除最后一个元素
v.push_back(x)		// 在尾部加入一个元素
v.count(x)			// 返回某个元素出现的次数
v.size()			// 返回元素的个数
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
	// vector<T> name
	vector<int> v1; // 创建一个空的 vector
	printf("当前 vector v1 是否为空：%s\n", v1.empty()?"yes":"no");
	printf("向末尾加入 1\n");
	v1.push_back(1);
	printf("v1 当前长度：%lu\n", v1.size());
	printf("数组方式遍历 v1: ");
	for(int i=0; i<v1.size(); ++i) {
		if(i) printf(" ");
		printf("%d", v1[i]); // 可以像数组一样按下标访问
	}
	printf("\n");
	printf("向末尾加入 2\n");
	v1.push_back(2);
	printf("向末尾加入 3\n");
	v1.push_back(3);
	printf("迭代器方式遍历 v1: ");
	vector<int>::iterator it;
	for(it=v1.begin(); it!=v1.end(); ++it) {
		if(it != v1.begin()) printf(" ");
		printf("%d", *it); // 类似指针的方式访问元素的值
	}
	printf("\n\n");

	printf("创建另一个 vector v2: 3 1 2 4\n");
	vector<int> v2;
	v2.push_back(3);
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(4);
	printf("访问第一个元素的值：%d\n访问最后一个元素的值：%d\n", v2.front(), v2.back());
	printf("删除最后一个元素：");
	v2.pop_back();
	for(int i=0; i<v2.size(); ++i) {
		if(i) printf(" ");
		printf("%d", v2[i]);
	}
	printf("\n");
	printf("在下标为 1 处插入元素 4（后方元素后移）：");
	v2.insert(v2.begin()+1, 4);
	for(int i=0; i<v2.size(); ++i) {
		if(i) printf(" ");
		printf("%d", v2[i]);
	}
	printf("\n");
	printf("删除下标为 1 处的元素（后方元素前移）：");
	v2.erase(v2.begin()+1);
	for(int i=0; i<v2.size(); ++i) {
		if(i) printf(" ");
		printf("%d", v2[i]);
	}
	printf("\n");
	printf("对 v2 升序排序：");
	sort(v2.begin(), v2.end());
	for(int i=0; i<v2.size(); ++i) {
		if(i) printf(" ");
		printf("%d", v2[i]);
	}
	printf("\n\n");
	printf("比较 v1 和 v2 是否相等（长度、元素均一致）：%s\n", v1==v2?"yes":"no");
	printf("清空 v1\n");
	v1.clear();
	printf("清空后 v1 的长度：%lu\n", v1.size());
	
	return 0;
}