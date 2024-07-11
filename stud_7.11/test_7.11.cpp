#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<list>
#include <vector>
#include <algorithm>


using namespace std;
#include"list.h"

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};
void print_list(const list<int>& lt)
{
	list<int>::const_iterator it = lt.begin();//const对象const迭代器 只读不可写
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_list1()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);
	lt1.push_back(6);
	//1.迭代器遍历
	list<int>::iterator it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	//2.范围for遍历
	list<int> lt2(lt1);
	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;
	list<int> lt3;
	lt3.push_back(10);
	lt3.push_back(20);
	lt3.push_back(30);
	lt3.push_back(40);
	lt3.push_back(50);
	lt3.push_back(60);
	lt1 = lt3;//赋值
	print_list(lt1);
	list<int>::reverse_iterator rit1 = lt1.rbegin();
	
	while (rit1 != lt1.rend())
	{
		cout << *rit1 << " ";
		++rit1;
	}
	cout << endl;
}

void test_list2()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_front(0);
	lt1.push_front(-1);
	lt1.pop_back();
	lt1.pop_front();
	print_list(lt1);

}
void test_list3()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(90);
	lt.push_back(1);
	lt.push_back(0);
	lt.push_back(20);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	lt.sort();
	
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	list<int>::iterator pos = find(lt.begin(),lt.end(),90);
	if (pos != lt.end())
	{
		lt.insert(pos, 30);//list的插入十分高效不用挪动数据o(1)
	}
	print_list(lt);
}

void test_list4()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(90);
	lt.push_back(1);
	lt.push_back(0);
	lt.push_back(20);
	lt.sort();
	print_list(lt);
	lt.reverse();//逆置链表
	print_list(lt);
}

void test_list5()
{
	list<int> lt;
	lt.push_back(10);
	lt.push_back(90);
	lt.push_back(1);
	lt.push_back(0);
	lt.push_back(20);
	lt.push_back(3);
	lt.push_back(9);
	lt.push_back(33);
	lt.sort();
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		if (*it % 2 == 0)
		{
			it = lt.erase(it);//erase删除it之后 it迭代器就失效了再去访问it就会出错erase();成功之后就会返回下一个结点
		}
		else
		{
			++it;
		}
			
	}
	print_list(lt);

}
// 定义Person类
class Person {
public:
	int age;
	std::string name;

	Person(int age, std::string name) : age(age), name(name) {}

	// 重载小于运算符，这样我们就可以比较两个Person对象
	bool operator<(const Person& rhs) const {
		return age < rhs.age;
	}
};

// 比较函数，用于sort()函数第三个参数
bool comparePersonByAge(const Person& lhs, const Person& rhs) {
	return lhs.age < rhs.age;
}
void test1()
{
	// 创建Person对象的vector
	std::vector<Person> people = {
		Person(25, "Alice"),
		Person(22, "Bob"),
		Person(28, "Charlie")
	};

	// 使用自定义比较函数对vector进行排序
	std::sort(people.begin(), people.end(), comparePersonByAge);//sort(起点迭代器，终点迭代器，比较方式)

	// 打印排序后的vector
	for (const auto& person : people) {
		std::cout << person.name << ": " << person.age << std::endl;
	}

	
}
//删除倒数第n个结点（使用快慢指针＋虚拟头节点）
class Solution1 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* dummy = new ListNode(0, head);//在头节点前面插入虚拟头节点
		ListNode* fast = head;
		ListNode* slow = dummy;//fast指向head，slow指向虚拟头节点
		while (n--)
		{
			fast = fast->next;
		}//fast相对slow先走了n步
		while (fast != nullptr)
		{
			fast = fast->next;
			slow = slow->next;//fast和slow同时向后面移动直到fast为空
		}
		slow->next = slow->next->next;
		return dummy->next;

	}
};
//合并两个有序链表
class Solution2 {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// 创建一个虚拟节点作为合并后链表的头节点
		ListNode* dummy = new ListNode(-1);
		ListNode* p = dummy;

		// 同时遍历两个链表，比较节点值并选择较小的节点添加到结果链表中
		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val) {
				p->next = list1;
				list1 = list1->next;
			}
			else {
				p->next = list2;
				list2 = list2->next;
			}
			p = p->next;  // 移动指针到新添加的节点
		}

		// 如果list1还有节点，将它们附加到结果链表的末尾
		if (list1 != nullptr) {
			p->next = list1;
		}

		// 如果list2还有节点，将它们附加到结果链表的末尾
		if (list2 != nullptr) {
			p->next = list2;
		}

		// 返回虚拟头节点的下一个节点，即合并后链表的头节点
		return dummy->next;
	}
};
//分隔链表
class Solution3 {
public:
	ListNode* partition(ListNode* head, int x) {
		// 创建两个虚拟节点，dummy1用于存储所有小于x的节点，dummy2用于存储所有大于或等于x的节点
		ListNode* dummy1 = new ListNode(-1);
		ListNode* dummy2 = new ListNode(-1);

		// 初始化两个指针，p1指向dummy1，p2指向dummy2
		ListNode* p1 = dummy1;
		ListNode* p2 = dummy2;

		// 用p指针遍历原链表
		ListNode* p = head;
		while (p != nullptr) {
			// 如果当前节点的值小于x，将其添加到dummy1链表中
			if (p->val < x) {
				p1->next = p; // 将当前节点连接到p1的下一个节点
				p1 = p1->next; // 更新p1为当前节点，以便下一次连接
			}
			// 如果当前节点的值大于或等于x，将其添加到dummy2链表中
			else {
				p2->next = p; // 将当前节点连接到p2的下一个节点
				p2 = p2->next; // 更新p2为当前节点，以便下一次连接
			}

			// 断开当前节点与原链表的连接，防止成环
			ListNode* tmp = p->next;
			p->next = nullptr;
			p = tmp;
		}

		// 合并两个链表，将dummy2连接到dummy1的尾部
		p1->next = dummy2->next;

		// 返回分割后的链表的头节点，即dummy1的下一个节点
		return dummy1->next;
	}
};

//链表的中间节点
class Solution4 {
public:
	ListNode* middleNode(ListNode* head) {
		// 初始化快慢指针都指向链表的头节点
		ListNode* fast = head;
		ListNode* slow = head;

		// 当快指针没有到达链表末尾，且快指针的下一个节点也不为空时
		while (fast != nullptr && fast->next != nullptr) {
			// 快指针移动两次
			fast = fast->next->next;
			// 慢指针移动一次
			slow = slow->next;
		}

		// 当快指针到达链表末尾时，慢指针就指向链表的中间节点
		return slow;
	}
};

int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	test_list5();
	//test1();
	return 0;
}

