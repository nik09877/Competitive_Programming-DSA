//YOU CAN KEEP TRACK OF ELEMENTS USING QUEUE
// void solve()
// {
//     int n, k;
//     cin >> n >> k;
//     queue<int> q;
//     ordered_set<int> ms;
//     rep(i, n)
//     {
//         int a;
//         cin >> a;
//         if (q.size() == k)
//         {
//             if (k & 1)
//             {
//                 prsp(*(ms.find_by_order(k / 2)));
//             }
//             else
//             {
//                 prsp(*(ms.find_by_order((k - 1) / 2)));
//             }
//             int val = q.front();
//             ms.erase(ms.find_by_order(ms.order_of_key(val)));
//             q.pop();
//         }
//         q.push(a);
//         ms.insert(a);
//     }
//     if (k & 1)
//     {
//         prsp(*(ms.find_by_order(k / 2)));
//     }
//     else
//     {
//         prsp(*(ms.find_by_order((k - 1) / 2)));
//     }
// }
#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class K, class V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
#define rep(i, n) for (int i = 0; i < n; i++)

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ordered_set<pair<int, int>> s;
    int l = 0, r = 0;

    for (; r < k; r++)
    {
        s.insert({a[r], r});
    }

    //MAINTAIN L,R like this
    for (; r <= n; r++, l++)
    {
        int median = (*s.find_by_order((k - 1) / 2)).first;
        cout << median << " ";

        if (r == n)
            break;

        s.erase({a[l], l});
        s.insert({a[r], r});
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}