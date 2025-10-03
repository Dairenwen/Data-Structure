#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<list>
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include<string> // 添加此头文件以修复 getline 未定义的问题
using namespace std;
class Polynomial
{
	typedef list<pair<int, int>> List;
public:
	Polynomial()
	{

	}

	/*Polynomial(const List& _ls)
		:ls(_ls)
	{

	}*/

	void push(int exp, int coe)
	{
		if (exp != 0) ls.push_back({ exp,coe });
	}

	List Add(const Polynomial& p)
	{
		List ret;
		auto n = ls.end();
		auto m = p.ls.end();
		auto s1 = ls.begin();
		auto s2 = p.ls.begin();
		while (s1 != n && s2 != m)
		{
			if (s1->second > s2->second)
			{
				if (s1->first != 0) ret.push_back({ s1->first, s1->second });
				s1++;
			}
			else if (s1->second < s2->second)
			{
				if (s2->first != 0) ret.push_back({ s2->first, s2->second });
				s2++;
			}
			else
			{
				int tmp = s1->first + s2->first;
				if (tmp) ret.push_back({ tmp ,s1->second });
				s1++; s2++;
			}
		}
		while (s1 != n)
		{
			if (s1->first != 0) ret.push_back({ s1->first, s1->second });
			s1++;
		}
		while (s2 != m)
		{
			if (s2->first != 0) ret.push_back({ s2->first, s2->second });
			s2++;
		}
		return ret;
	}

	List TwolsAdd(const List& l1, const List& l2)
	{
		List ret;
		auto n = l1.end();
		auto m = l2.end();
		auto s1 = l1.begin();
		auto s2 = l2.begin();
		while (s1 != n && s2 != m)
		{
			if (s1->second > s2->second)
			{
				if (s1->first != 0) ret.push_back({ s1->first, s1->second });
				s1++;
			}
			else if (s1->second < s2->second)
			{
				if (s2->first != 0) ret.push_back({ s2->first, s2->second });
				s2++;
			}
			else
			{
				int tmp = s1->first + s2->first;
				if (tmp) ret.push_back({ tmp ,s1->second });
				s1++; s2++;
			}
		}
		while (s1 != n)
		{
			if (s1->first != 0) ret.push_back({ s1->first, s1->second });
			s1++;
		}
		while (s2 != m)
		{
			if (s2->first != 0) ret.push_back({ s2->first, s2->second });
			s2++;
		}
		return ret;
	}

	List Multiply(const Polynomial& p)
	{
		vector<List> tmp;
		List ret;
		int n = ls.size(), m = p.ls.size();
		auto s1 = ls.begin();
		for (int i = 0; i < n; i++)
		{
			auto s2 = p.ls.begin();
			List ele;
			for (int j = 0; j < m; j++)
			{
				int mul = (s1->first) * (s2->first);
				if (mul) ele.push_back({ mul,(s1->second) + (s2->second) });
				s2++;
			}
			tmp.push_back(ele);
			s1++;
		}
		for (int i = 0; i < tmp.size(); i++)
		{
			ret = TwolsAdd(ret, tmp[i]);
		}
		return ret;
	}

	List differentiate(const Polynomial& p)
	{
		List ret;
		int n = p.ls.size();
		auto begin = p.ls.begin();
		while (begin != p.ls.end())
		{
			if (begin->second != 0)
			{
				int exppush = (begin->first) * (begin->second);
				if (exppush) ret.push_back({ exppush,(begin->second) - 1 });
			}
			begin++;
		}
		return ret;
	}

	void print(const List& l)
	{
		if (l.empty())
		{
			cout << "0 0";
			return;
		}
		int n = l.size();
		auto s = l.begin();
		for (int i = 0; i < n; i++)
		{
			if (s->first != 0) cout << s->first << " " << s->second;
			if (i != n - 1) cout << " ";
			s++;
		}
	}
	~Polynomial()
	{

	}
private:
	List ls;//存储多项式，第一个数系数，第二个指数
};

//int main()
//{
//	Polynomial p1, p2;
//	int num = 0, exp = 0, coe = 0;
//	cin >> num;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> exp >> coe;
//		p1.push(exp, coe);
//	}
//	cin >> num;
//	for (int i = 0; i < num; i++)
//	{
//		cin >> exp >> coe;
//		p2.push(exp, coe);
//	}
//	list<pair<int, int>> l1 = p1.Multiply(p2);
//	list<pair<int, int>> l2 = p1.Add(p2);
//	p1.print(l1);
//	cout << endl;
//	p2.print(l2);
//	return 0;
//}

struct Compare
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		if (p1.second == p2.second) return p1.first > p2.first;
		else return p1.second > p2.second;
	}
};

int main()
{
	int waitmax = -1, lasttime = 0;
	double totaltime = 0;
	vector<int> count;
	vector<pair<int, int>> c;
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> heap;
	int n = 0; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t = 0, p = 0;
		cin >> t >> p;
		p = min(p, 60);
		c.push_back({ t,p });
	}
	int k = 0; cin >> k;
	count.resize(k, 0);
	for (int i = 0; i < k; i++) heap.push({ i,0 });
	for (int i = 0; i < c.size(); i++)
	{
		pair<int, int> front = heap.top(); heap.pop();
		int start_time = max(front.second, c[i].first);
		int wait_time = start_time - c[i].first;
		int finish_time = start_time + c[i].second;
		totaltime += wait_time;
		waitmax = max(waitmax, wait_time);
		lasttime = max(lasttime, finish_time);
		heap.push({ front.first, finish_time });
		count[front.first]++;
	}
	printf("%.1f %d %d\n", totaltime / n, waitmax, lasttime);
	for (int i = 0; i < k; i++)
	{
		cout << count[i];
		if (i != k - 1) cout << " ";
	}
	return 0;
}