/*
by bLue
Last Updated: 03/23/2017
*/

#include <cstdio>
#include <utility>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
	// pair<first, second> name
	printf("通过构造器创建 pair：\n");
	pair<string, int> p1("abc", 1); // 通过 first, second 访问
	printf("%s %d\n", p1.first.c_str(), p1.second);
	printf("通过 make_pair() 创建 pair：\n");
	pair<int, int> p2 = make_pair(123, 456);
	printf("%d %d\n", p2.first, p2.second);
	
	return 0;
}