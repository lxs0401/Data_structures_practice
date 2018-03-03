/*
by bLue
Last Updated: 03/23/2017
*/

/*
常用函数
q.push(x)		// 入队
q.pop()			// 出队
q.front()		// 访问队首元素
q.back()		// 访问队尾元素
q.empty()		// 判断是否为空
q.size()		// 返回元素数量
*/

#include <cstdio>
#include <queue>
using namespace std;

int main(int argc, char const *argv[]) {
	// queue<T> name
	queue<int> q; // 创建一个空的 queue
	printf("push: 1\n");
	q.push(1); // 1
	printf("当前队首为：%d，队尾为：%d，队中元素数量：%lu\n", q.front(), q.back(), q.size());
	printf("push: 2\n");
	q.push(2); // 1 2
	printf("当前队首为：%d，队尾为：%d，队中元素数量：%lu\n", q.front(), q.back(), q.size());
	printf("push: 5\n");
	q.push(5); // 1 2 5
	printf("当前队首为：%d，队尾为：%d，队中元素数量：%lu\n", q.front(), q.back(), q.size());
	printf("pop: %d\n", q.front());
	q.pop(); // 2 5
	printf("当前队首为：%d，队尾为：%d，队中元素数量：%lu\n", q.front(), q.back(), q.size());
	printf("push: 3\n");
	q.push(3); // 2 5 3
	printf("当前队首为：%d，队尾为：%d，队中元素数量：%lu\n", q.front(), q.back(), q.size());
	printf("\n");

	printf("pop 至队空\n");
	while(!q.empty()) {
		printf("pop: %d\n", q.front());
		q.pop();
	}
	printf("清空后队中元素数量：%lu\n", q.size());
	
	return 0;
}