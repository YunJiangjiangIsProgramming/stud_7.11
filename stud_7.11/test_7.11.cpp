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
	list<int>::const_iterator it = lt.begin();//const����const������ ֻ������д
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
	//1.����������
	list<int>::iterator it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	//2.��Χfor����
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
	lt1 = lt3;//��ֵ
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
		lt.insert(pos, 30);//list�Ĳ���ʮ�ָ�Ч����Ų������o(1)
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
	lt.reverse();//��������
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
			it = lt.erase(it);//eraseɾ��it֮�� it��������ʧЧ����ȥ����it�ͻ����erase();�ɹ�֮��ͻ᷵����һ�����
		}
		else
		{
			++it;
		}
			
	}
	print_list(lt);

}
// ����Person��
class Person {
public:
	int age;
	std::string name;

	Person(int age, std::string name) : age(age), name(name) {}

	// ����С����������������ǾͿ��ԱȽ�����Person����
	bool operator<(const Person& rhs) const {
		return age < rhs.age;
	}
};

// �ȽϺ���������sort()��������������
bool comparePersonByAge(const Person& lhs, const Person& rhs) {
	return lhs.age < rhs.age;
}
void test1()
{
	// ����Person�����vector
	std::vector<Person> people = {
		Person(25, "Alice"),
		Person(22, "Bob"),
		Person(28, "Charlie")
	};

	// ʹ���Զ���ȽϺ�����vector��������
	std::sort(people.begin(), people.end(), comparePersonByAge);//sort(�����������յ���������ȽϷ�ʽ)

	// ��ӡ������vector
	for (const auto& person : people) {
		std::cout << person.name << ": " << person.age << std::endl;
	}

	
}
//ɾ��������n����㣨ʹ�ÿ���ָ�룫����ͷ�ڵ㣩
class Solution1 {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* dummy = new ListNode(0, head);//��ͷ�ڵ�ǰ���������ͷ�ڵ�
		ListNode* fast = head;
		ListNode* slow = dummy;//fastָ��head��slowָ������ͷ�ڵ�
		while (n--)
		{
			fast = fast->next;
		}//fast���slow������n��
		while (fast != nullptr)
		{
			fast = fast->next;
			slow = slow->next;//fast��slowͬʱ������ƶ�ֱ��fastΪ��
		}
		slow->next = slow->next->next;
		return dummy->next;

	}
};
//�ϲ�������������
class Solution2 {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// ����һ������ڵ���Ϊ�ϲ��������ͷ�ڵ�
		ListNode* dummy = new ListNode(-1);
		ListNode* p = dummy;

		// ͬʱ�������������ȽϽڵ�ֵ��ѡ���С�Ľڵ���ӵ����������
		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val) {
				p->next = list1;
				list1 = list1->next;
			}
			else {
				p->next = list2;
				list2 = list2->next;
			}
			p = p->next;  // �ƶ�ָ�뵽����ӵĽڵ�
		}

		// ���list1���нڵ㣬�����Ǹ��ӵ���������ĩβ
		if (list1 != nullptr) {
			p->next = list1;
		}

		// ���list2���нڵ㣬�����Ǹ��ӵ���������ĩβ
		if (list2 != nullptr) {
			p->next = list2;
		}

		// ��������ͷ�ڵ����һ���ڵ㣬���ϲ��������ͷ�ڵ�
		return dummy->next;
	}
};
//�ָ�����
class Solution3 {
public:
	ListNode* partition(ListNode* head, int x) {
		// ������������ڵ㣬dummy1���ڴ洢����С��x�Ľڵ㣬dummy2���ڴ洢���д��ڻ����x�Ľڵ�
		ListNode* dummy1 = new ListNode(-1);
		ListNode* dummy2 = new ListNode(-1);

		// ��ʼ������ָ�룬p1ָ��dummy1��p2ָ��dummy2
		ListNode* p1 = dummy1;
		ListNode* p2 = dummy2;

		// ��pָ�����ԭ����
		ListNode* p = head;
		while (p != nullptr) {
			// �����ǰ�ڵ��ֵС��x��������ӵ�dummy1������
			if (p->val < x) {
				p1->next = p; // ����ǰ�ڵ����ӵ�p1����һ���ڵ�
				p1 = p1->next; // ����p1Ϊ��ǰ�ڵ㣬�Ա���һ������
			}
			// �����ǰ�ڵ��ֵ���ڻ����x��������ӵ�dummy2������
			else {
				p2->next = p; // ����ǰ�ڵ����ӵ�p2����һ���ڵ�
				p2 = p2->next; // ����p2Ϊ��ǰ�ڵ㣬�Ա���һ������
			}

			// �Ͽ���ǰ�ڵ���ԭ��������ӣ���ֹ�ɻ�
			ListNode* tmp = p->next;
			p->next = nullptr;
			p = tmp;
		}

		// �ϲ�����������dummy2���ӵ�dummy1��β��
		p1->next = dummy2->next;

		// ���طָ��������ͷ�ڵ㣬��dummy1����һ���ڵ�
		return dummy1->next;
	}
};

//������м�ڵ�
class Solution4 {
public:
	ListNode* middleNode(ListNode* head) {
		// ��ʼ������ָ�붼ָ�������ͷ�ڵ�
		ListNode* fast = head;
		ListNode* slow = head;

		// ����ָ��û�е�������ĩβ���ҿ�ָ�����һ���ڵ�Ҳ��Ϊ��ʱ
		while (fast != nullptr && fast->next != nullptr) {
			// ��ָ���ƶ�����
			fast = fast->next->next;
			// ��ָ���ƶ�һ��
			slow = slow->next;
		}

		// ����ָ�뵽������ĩβʱ����ָ���ָ��������м�ڵ�
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

