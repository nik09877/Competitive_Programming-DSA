#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    //rev[i] is reverse or transpose graph
    //adj[i] is the actual graph
    vector<pair<int, int>> rev[100000], adj[100000];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
        rev[b - 1].push_back({a - 1, c});
    }
    priority_queue<pair<long long, int>> q; //(-price, city)
    bool visited[100000]{};

    //find the price to go from city 1 to all other cities
    long long dist1[100000];
    fill(dist1, dist1 + n, 1e18);
    dist1[0] = 0;
    q.push({0, 0});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (visited[a])
            continue;
        visited[a] = true;
        for (auto i : adj[a])
        {
            int b = i.first, w = i.second;
            if (dist1[a] + w < dist1[b])
            {
                dist1[b] = dist1[a] + w;
                q.push({-dist1[b], b});
            }
        }
    }

    //find the price to go from each city to city n
    long long distn[100000];
    fill(distn, distn + n, 1e18);
    fill(visited, visited + n, false);
    distn[n - 1] = 0;
    q.push({0, n - 1});
    while (!q.empty())
    {
        int a = q.top().second;
        q.pop();
        if (visited[a])
            continue;
        visited[a] = true;
        for (auto i : rev[a])
        {
            int b = i.first, w = i.second;
            if (distn[a] + w < distn[b])
            {
                distn[b] = distn[a] + w;
                q.push({-distn[b], b});
            }
        }
    }

    //take the minimum cost after using the coupon over all pairs of cities
    long long cost = dist1[n - 1];
    for (int a = 0; a < n; a++)
    {
        for (auto i : adj[a])
        {
            int b = i.first, w = i.second;
            cost = min(cost, dist1[a] + distn[b] + w / 2);
        }
    }
    cout << cost << endl;
    return 0;
}

/*
EDITORIAL

Alternatively, we can run Dijkstra's and modify our distance array slightly to
track whether the discount has been used or not.

dist[i][0] will represent the shortest distance from the start node
to node i, without using the discount. dist[i][1] will represent
the shortest distance after using the discount.


// Author: Nikhil Kumar Mishra
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll,ll>;
#define f first
#define s second

// create a struct to store data in a priority_queue
struct Item {
	int node;
	ll cost;
	bool discount;

	Item(int _node, ll _cost, bool _discount) {
		node = _node;
		cost = _cost;
		discount = _discount;
	}

	inline const bool operator<(const Item& other) const {
		if (discount == other.discount) {
			return cost > other.cost;
		}
		return discount > other.discount;
	}
};

const int MN = 100005;

int N, M;
vector<pll> adj[MN];
ll dist[MN][2];
// dist[i][0] represents the shortest distance without discount
// dist[i][1] represents the shortest distance with a discount

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i=0; i<M; ++i) {
		ll u, v, c;
		cin >> u >> v >> c;
		--u; --v;
		adj[u].emplace_back(v, c);
	}

	// initialize dist
	for (int i=0; i<N; ++i) {
		dist[i][0] = dist[i][1] = 1e18;
	}

	priority_queue<Item> pq;
	pq.emplace(0, 0, false);

	while (pq.size() > 0) {
		Item cur = pq.top(); pq.pop();

		if (cur.node == N-1 && cur.discount) {
			cout << cur.cost << '\n';
			return 0;
		}

		for (pll nxt: adj[cur.node]) {
			// travel without a discount
			if (dist[nxt.f][cur.discount] > cur.cost + nxt.s) {
				dist[nxt.f][cur.discount] = cur.cost + nxt.s;
				pq.emplace(nxt.f, dist[nxt.f][cur.discount], cur.discount);
			}
			// if we haven't used the discount yet, try using it on this edge
			if (cur.discount == false) {
				if (dist[nxt.f][true] > cur.cost + nxt.s / 2) {
					dist[nxt.f][true] = cur.cost + nxt.s / 2;
					pq.emplace(nxt.f, dist[nxt.f][true], true);
				}
			}
		}
	}

	// it is guaranteed that we can reach our destination, so this should never happen
	assert(false);
}
*/