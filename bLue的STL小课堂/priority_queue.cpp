/*
by bLue
Last Updated: 03/23/2017
*/

/*
常用函数
q.push(x)		// 入队
q.pop()			// 出队
q.top()			// 访问队首元素
q.empty()		// 判断是否为空
q.size()		// 返回元素数量
*/

#include <cstdio>
#include <queue>
using namespace std;

struct info {
	int p;
	int q;
	bool operator < (const info &cmp) const {
		return p < cmp.p;
	}
	bool operator > (const info &cmp) const {
		return p > cmp.p;
	}
};

int main(int argc, char const *argv[]) {
	// priority_queue<T> name
	printf("元素类型为 int 优先队列\n");
	priority_queue<int> q; // 创建一个大的先出队的优先队列
	// priority_queue<int, vector<int>, greater<int> > q; // 小的先出队
	printf("push: 1\n");
	q.push(1); // 1
	printf("当前队首为：%d，队中元素数量：%lu\n", q.top(), q.size());
	printf("push: 2\n");
	q.push(2); // 2 1
	printf("当前队首为：%d，队中元素数量：%lu\n", q.top(), q.size());
	printf("push: 5\n");
	q.push(5); // 5 2 1
	printf("当前队首为：%d，队中元素数量：%lu\n", q.top(), q.size());
	printf("pop: %d\n", q.top());
	q.pop(); // 2 1
	printf("当前队首为：%d，队中元素数量：%lu\n", q.top(), q.size());
	printf("push: 3\n");
	q.push(3); // 3 2 1
	printf("当前队首为：%d，队中元素数量：%lu\n", q.top(), q.size());
	printf("\n");

	printf("pop 至队空\n");
	while(!q.empty()) {
		printf("pop: %d\n", q.top());
		q.pop();
	}
	printf("清空后队中元素数量：%lu\n\n", q.size());

	printf("元素类型为自定义结构体的优先队列\n");
	// priority_queue<info> q2; // 需要重载小于号
	priority_queue<info, vector<info>, greater<info> > q2; // 需要重载大于号
	q2.push((info){1, 5});
	q2.push((info){2, 10});
	q2.push((info){3, 10});
	while(!q2.empty()) {
		printf("pop: {%d, %d}\n", q2.top().p, q2.top().q);
		q2.pop();
	}
	
	return 0;
}