/*
by bLue
Last Updated: 03/23/2017
*/

/*
常用函数
s.push(x) 		// 入栈
s.pop()			// 出栈
s.top()			// 访问栈顶元素
s.empty()		// 判断是否为空
s.size()		// 返回元素数量
*/

#include <cstdio>
#include <stack>
using namespace std;

int main(int argc, char const *argv[]) {
	// stack<T> name
	stack<int> s; // 创建一个空的 stack
	printf("push: 1\n");
	s.push(1); // 1
	printf("当前栈顶为：%d，栈中元素数量：%lu\n", s.top(), s.size());
	printf("push: 2\n");
	s.push(2); // 1 2
	printf("当前栈顶为：%d，栈中元素数量：%lu\n", s.top(), s.size());
	printf("push: 5\n");
	s.push(5); // 1 2 5
	printf("当前栈顶为：%d，栈中元素数量：%lu\n", s.top(), s.size());
	printf("pop: %d\n", s.top());
	s.pop(); // 1 2
	printf("当前栈顶为：%d，栈中元素数量：%lu\n", s.top(), s.size());
	printf("push: 3\n");
	s.push(3); // 1 2 3
	printf("当前栈顶为：%d，栈中元素数量：%lu\n", s.top(), s.size());
	printf("\n");

	printf("pop 至栈空\n");
	while(!s.empty()) {
		printf("pop: %d\n", s.top());
		s.pop();
	}
	printf("清空后栈中元素数量：%lu\n", s.size());
	
	return 0;
}