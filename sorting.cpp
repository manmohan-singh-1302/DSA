#include <bits/stdc++.h>
using namespace std;
class node
{
public:
	int id;
	int amount;
	node(int _id, int _amount)
		: id(_id), amount(_amount)
	{
	}
};

bool operator>(const node &p1, const node &p2)
{
	if (p1.amount > p2.amount)
		return true;
	else if (p1.amount < p2.amount)
		return false;
	return p1.id < p2.id;
}
struct trans
{
	int from;
	int to;
	int amount;
};
void sol(vector<pair<int, int>> &lent, vector<pair<int, int>> &borrowed)
{
	map<int, long long> mp;
	for (auto v : lent)
		mp[v.first] += v.second;
	for (auto v : borrowed)
		mp[v.first] -= v.second;
	priority_queue<node, vector<node>, greater<node>> pq_giver;
	priority_queue<node, vector<node>, greater<node>> pq_taker;
	for (auto f : mp)
	{
		if (f.second > 0)
			pq_taker.push(node(f.first, f.second));
		if (f.second < 0)
			pq_giver.push(node(f.first, f.second));
	}
	vector<trans> ans;
	while (pq_giver.size() || pq_taker.size())
	{
		node from = pq_giver.top();
		node to = pq_taker.top();
		pq_giver.pop();
		pq_taker.pop();
		if (from.amount > to.amount)
		{
			ans.push_back({from.id, to.id, to.amount});
			from.amount -= to.amount;
			pq_giver.push(from);
		}
		else
		{
			if (from.amount < to.amount)
			{
				ans.push_back({from.id, to.id, from.amount});
				to.amount -= from.amount;
				pq_taker.push(to);
			}
			else
			{
				ans.push_back({from.id, to.id, to.amount});
			}
		}
	}
	cout << ans.size() << endl;
	for (auto a : ans)
	{
		cout << a.from << ' ' << a.to << ' ' << a.amount << endl;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> lent(100);
	vector<pair<int, int>> borrowed(100);
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		int l, b;
		int x, y;
		cin >> l >> b;
		for (int i = 0; i < l; i++)
		{
			cin >> x >> y;
			lent.push_back({x, y});
		}
		for (int i = 0; i < b; i++)
		{
			cin >> x >> y;
			borrowed.push_back({x, y});
		}
	}
	sol(lent, borrowed);
	return 0;
}