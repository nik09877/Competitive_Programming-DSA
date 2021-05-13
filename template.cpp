#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// template <class T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <class K, class V>
// using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

#include <bits/stdc++.h>
#include <stdio.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define rep1(i, n) for (int i = 1; i <= n; i++)
#define fo(i, a, n) for (int i = a; i <= n; i++)
#define repll(i, a, n) for (lli i = a; i <= n; i++)
#define mkp make_pair
#define pb emplace_back
#define ff first
#define ss second
#define ll long long
#define lli long long int
#define ii int, int
#define pii pair<int, int>
#define pll pair<long, long>
#define plli pair<long long int, long long int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vlli vector<long long int>
#define vpii vector<pair<int, int>>
#define vplli vector<pair<long long int, long long int>>
#define vvlli vector<vector<long long int>>
#define MAXLL 1e18
#define endl '\n'
#define sp ' '
#define dsort(v) sort(v.begin(), v.end(), greater<int>())
#define asort(v) sort(v.begin(), v.end())
#define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define all(v) v.begin(), v.end()
#define umap unordered_map
#define uset unordered_set
#define sz(x) ((int)(x).size())
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define pr(x) cout << x
#define prsp(x) cout << x << sp
#define prln(x) cout << x << endl
#define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
#define re(a, n)   \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
// DEBUG TEMPLATE STARTS HERE//
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
//DEBUG TEMPLATE ENDS HERE

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void compress(vi &a)
{
    //for fenwick tree
    int n = (int)a.size();
    map<ii> mpp, back;
    int idx = 1;
    rep(i, n)
    {
        if (mpp.find(a[i]) == mpp.end())
        {
            mpp.insert({a[i], idx});
            back.insert({idx, a[i]}); //to get back original values
            idx++;
        }
    }
    rep(i, n)
    {
        a[i] = mpp[a[i]];
    }
}
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    // umap<lli, lli, custom_hash> mp;
};

class LOG
{
public:
    //check if type iterable function
    template <typename C>
    struct is_iterable
    {
        typedef long false_type;
        typedef char true_type;

        template <class T>
        static false_type check(...);
        template <class T>
        static true_type check(int,
                               typename T::const_iterator = C().end());

        enum
        {
            value = sizeof(check<C>(0)) == sizeof(true_type)
        };
    };
    //string print
    static void print_value(string starting, string value, string ending = "\n")
    {
        cout << starting << "\"" << value << "\"" << ending;
    }
    //main print function
    template <class T>
    static void print_value(string starting, T value, string ending = "\n")
    {
        //if iterable than recursevly print ech value
        if constexpr (is_iterable<T>::value)
        {
            typename T ::iterator it = value.begin();
            cout << starting << "{";
            while (it != value.end())
            {
                print_value("", *it, (next(it, 1) == value.end() ? "" : ", "));
                it++;
            }
            cout << "}";
        }
        else
        {
            // else we probably have char, int, long long, and etc.
            cout << starting << value;
        }
        cout << ending;
    }
    //pair print
    template <class T, class M>
    static void print_value(string starting, pair<T, M> value, string ending = "\n")
    {
        cout << starting << "{";
        print_value("", value.ff, "");
        cout << ", ";
        print_value("", value.ss, "");
        cout << "}" << ending;
    }
    //map recursive print
    template <class T, class M>
    static void print_value(string starting, map<T, M> value, string ending = "\n")
    {
        cout << starting << "{" << endl;
        ll cur = 0;
        for (pair<T, M> v : value)
        {
            print_value("  {", v.ff, ": ");
            print_value("", v.ss, (cur == value.size() - 1 ? "}" : "},"));
            cur++;
            cout << endl;
        }
        cout << "}" << ending;
    }
    //array print
    /*
    ARRAY PRINT DOES'T WORK CORRECTLY
      I HIGHLY RECOMMEND TO NOT USE IT
    */
    template <class T>
    static void print_value(string starting, vector<size_t> len, T *value, int dim)
    {
        if (len.size() == 1)
        {
            for (long long i = 0; i < len[0]; i++)
            {
                cout << *(value + i) << " ";
            }
        }
        if (len.size() == 2)
        {
            for (long long i = 0; i < len[0]; i++)
            {
                for (long long j = 0; j < len[1]; j++)
                {
                    cout << *(*(value + i) + j) << " ";
                }
                cout << endl;
            }
        }
        if (len.size() == 3)
        {
            for (long long i = 0; i < len[0]; i++)
            {
                for (long long j = 0; j < len[1]; j++)
                {
                    for (long long z = 0; z < len[2]; z++)
                    {
                        cout << *(*(*(value + i) + j) + z) << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
        if (len.size() == 4)
        {
            for (long long i = 0; i < len[0]; i++)
            {
                for (long long j = 0; j < len[1]; j++)
                {
                    for (long long z = 0; z < len[2]; z++)
                    {
                        for (long long x = 0; x < len[3]; x++)
                        {
                            cout << (*(*(*(value + i) + j) + z) + x) << " ";
                        }
                        cout << endl;
                    }
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
};
//!DEBUG EXAMPLES
// now the examples:

// #include<bits/stdc++.h>
// using namespace std;
// //----LOG class code---
// int main(){
//     vector<long long> v(5);
//     for (long long i = 0; i < 5; i++){
//         cin >> v[i];
//     }
//     LOG::print_value ("starting string ", v, " ending string");
// }
// this is for all types exept arrays(like this: a[5]) now for arrays:

// #include<bits/stdc++.h>
// using namespace std;
// //----LOG class code---
// int main(){
//     long long v[5][3];
//     for (long long i = 0; i < 5; i++){
//         for (long long j = 0; i < 3; j++){
//             cin >> v[i][j];
//         }
//     }
//     LOG::print_value ("starting string ", {5, 3}, a, 0);
// // starting string, vector of lengths, variable name, starting dimension index
// }
//!END

void solve()
{
    //  #ifndef ONLINE_JUDGE
    //         freopen("input.txt", "r" ,stdin);
    //         freopen("output.txt", "w" ,stdout);
    //     #endif
    // int n;
    // cin >> n;
    vector<string> v = {"january", "february", "march", " april ", " may ", " june ", " july ", " august ", "september", "october", "november", "december"};
    sort(all(v));
    // ordered_set<array<int, 2>> s;
    for (auto s : v)
    {
        cout << s << endl;
    }
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
//!IMP NOTES AND TRICKS
//1->note that sometimes while using sets  u can use negative values to manipulate the ways they are sorted
//2-> ans = max({ans,a,b,c}); instead of ans = max(max(ans,a),max(b,c));

// template <class T>
// using minpq = priority_queue<T, vector<T>, greater<T>>;

//std:: next,std:: prev
// multiset<int>se;
// se.erase(prev(se.end()));
// ll val = *prev(se.end());

//custom hash table by neal
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
// Now we can simply define our unordered_map or our gp_hash_table as follows:
// unordered_map<long long, int, custom_hash> safe_map;
// gp_hash_table<long long, int, custom_hash> safe_hash_table;

//!SOME NUMBER THEORY FUNCTIONS
///---------------Functions---------------------///
// ll advceil(ll num, ll den) { return (num % den == 0 ? num / den : num / den + 1); }
// ll lstbt(ll val)
// {
//     ll msk = val & (val - 1);
//     return log2(val ^ msk);
// }
// ll modmul(ll a, ll b)
// {
//     a %= MOD;
//     b %= MOD;
//     ll res = 0;
//     while (b > 0)
//     {
//         if (b & 1)
//             res = (res + a) % MOD;
//         a = (a * 2) % MOD;
//         b /= 2;
//     }
//     return res;
// }
// ll modexpo(ll a, ll b)
// {
//     ll res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//             res = modmul(res, a);
//         a = modmul(a, a);
//         b /= 2;
//     }
//     return res;
// }
// ll gcd(ll a, ll b) { return a == 0 ? b : gcd(b % a, a); }
// vll CALCfactor(ll n)
// {
//     vll factor(n + 2, 0);
//     for (ll i = 4; i <= n; i += 2)
//         factor[i] = 2;
//     for (ll j = 3; j <= n; j += 2)
//     {
//         if (factor[j])
//             continue;
//         for (ll i = 2 * j; i <= n; i += j)
//             factor[i] = j;
//     }
//     return factor;
// }
// vll CALCprimeNUM(ll n)
// {
//     vll factor = CALCfactor(n);
//     vll primeNUM;
//     primeNUM.reserve(n + 2);
//     cf(i, 2, n) if (!factor[i]) primeNUM.pb(i);
//     return primeNUM;
// }
// vll CALCprimeFACTOR(ll n)
// {
//     vll factor = CALCfactor(n);
//     vll ans;
//     while (factor[n] != 0)
//     {
//         ans.pb(factor[n]);
//         n /= factor[n];
//     }
//     if (n > 1)
//         ans.pb(n);
//     return ans;
// }
// vll unique(vll x)
// {
//     sort(all(x));
//     set<ll> s;
//     vll ans;
//     ans.reserve(szv(x));
//     for (auto elem : x)
//         s.insert(elem);
//     for (auto elem : s)
//         ans.pb(elem);
//     return ans;
// }
// pair<vll, vll> getFact(ll n)
// {
//     vll fact(n + 1, 1), invfact(n + 1, 1);
//     cf(i, 1, n) fact[i] = (i * (fact[i - 1])) % MOD;
//     cf(i, 1, n) invfact[i] = (modexpo(i, MOD - 2) * invfact[i - 1]) % MOD;
//     return {fact, invfact};
// }
// void compress(vll &arr, ll n)
// {
//     map<ll, vll> pos;
//     cf(i, 1, n) pos[arr[i]].pb(i);
//     ll cnt = 1;
//     for (auto itr : pos)
//     {
//         for (auto elem : itr.ss)
//             arr[elem] = cnt;
//         cnt++;
//     }
// }
// ///---------x------------x----------x-----------///

//!SOME USEFUL STL FUNCTIONS
//Time measure
// auto begin = std::chrono::high_resolution_clock::now();

// auto end = std::chrono::high_resolution_clock::now();
//     auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
//     printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);

//TIMER
//     auto start1 = high_resolution_clock::now();
//     // solve();
//     test(solve);
//     auto stop1 = high_resolution_clock::now();
//     auto duration = duration_cast<microseconds>(stop1 - start1);
//     #ifndef ONLINE_JUDGE
//         cerr << "Time: " << duration.count() / 1000.0 << endl;
//         cout<<duration.count()/1000.0<<endl;
//     #endif

/*std::any_of

This is a very useful function that returns true iff any of the elements in the range [first, last) satisfies some condition. Let's say you want to figure out if an array contains at least one 9. You could just write the naive loop and waste time in contest.

bool ok = any_of(a.begin(), a.end(), [](int x) { return x == 9; });

std::all_of
This is another useful function that functions similar to std::any_of. The difference is that it returns true iff all the elements in the range [first, last) follow some condition.

Let's say you want to find if the array consists of all 9's.

bool ok = all_of(a.begin(), a.end(), [](int x) { return x == 9; });

std::none_of
This is yet another function that is close relatives of the two mentioned above. This function returns true iff all the elements does not follow some condition.

Let's say you want to find if the array doesn't contain 9.

Pros would do:

bool ok = none_of(a.begin(), a.end(), [](int x) { return x == 9; });

std::count
This functions counts the number of elements in the range [first, last) that are equal to some variable val.

int cnt = count(a.begin(), a.end(), x);

std::find
This function returns the first iterator that compares equal to val.

int hld = find(a.begin(), a.end(), x) - a.begin();*/

// std::for_each
// std::accumulate-: int sum = accumulate(all(a),0);

// Another one .. function to count numbers greater than or equal to x
// int count_x = count_if(v.begin(), v.end(), [](int a) { return (a >= x); });
typedef unsigned long long ull;
typedef long double lld;
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}