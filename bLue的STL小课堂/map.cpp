/*
by bLue
Last Updated: 03/23/2017
*/

/*
常用函数
m[k] = v		// 插入一对元素
m.insert(k, v)	// 插入一对元素
m.clear()		// 清空所有元素
m.erase(x)		// 删除指定元素
m.empty()		// 判断是否为空
m.count(x)		// 返回某个元素出现的次数
m.size()		// 返回元素个数
*/

#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
	// map<key, value> name
	// map 会按照 key 自动排序
	map<string, int> m1; // 创建一个 string->int 映射的空 map
	printf("当前 map m1 是否为空：%s\n", m1.empty()?"yes":"no");
	printf("插入键值对\n");
	m1["abc"] = 1; // 数组方式访问
	m1["aaa"] = 3;
	m1["abc"]++;
	m1["aaa123"] = 0;
	printf("m1 当前长度：%lu\n", m1.size());
	printf("迭代器方式遍历 m1:\n");
	map<string, int>::iterator it1;
	for(it1=m1.begin(); it1!=m1.end(); ++it1) {
		// 使用 first, second 访问键和值
		printf("%s -> %d\n", it1->first.c_str(), it1->second); // 类似指针的方式访问元素的值
	}
	printf("\n");

	printf("查找键 \"abc\" 是否存在于 m1：%s\n", m1.count("abc")?"yes":"no");
	printf("查找键 \"QAQ\" 是否存在于 m1：%s\n", m1.count("QAQ")?"yes":"no");
	printf("二分查找第一个字典序大于等于 \"bbb\" 的键：%s\n", m1.upper_bound("bbb")==m1.end()?"not found":"found");
	printf("二分查找第一个字典序大于 \"aaa\" 的键：%s\n", m1.upper_bound("aaa")->first.c_str());
	printf("\n");

	printf("创建另一个 long long -> int 的 map m2:\n");
	map<long long, int> m2;
	map<long long, int>::iterator it2;
	m2[123456789012345] = 666;
	m2[2333333333333333] = 2333;
	m2.insert(make_pair(666666666666, 1));
	for(it2=m2.begin(); it2!=m2.end(); ++it2) {
		printf("%lld -> %d\n", it2->first, it2->second); // 类似指针的方式访问元素的值
	}
	printf("\n");
	printf("从 m2 中删除键 123456789012345:\n");
	m2.erase(123456789012345);
	for(it2=m2.begin(); it2!=m2.end(); ++it2) {
		printf("%lld -> %d\n", it2->first, it2->second); // 类似指针的方式访问元素的值
	}
	printf("\n");
	printf("清空 m2\n");
	m2.clear();
	printf("清空后 m2 的长度：%lu\n", m2.size());
	
	return 0;
}