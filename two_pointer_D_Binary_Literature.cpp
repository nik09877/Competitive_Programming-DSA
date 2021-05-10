#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;

//get the type of char whose freq_count is more
char getFC(string &st)
{
    int ar[] = {0, 0};

    for (char ch : st)
        ar[ch - '0']++;

    if (ar[0] > ar[1])
        return '0';
    else
        return '1';
}

int main()
{
    int t, n;
    string a, b, c;

    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> a >> b >> c;

        string x, y;
        char code;

        if (getFC(a) == getFC(b))
            x = a, y = b, code = getFC(a);
        else if (getFC(a) == getFC(c))
            x = a, y = c, code = getFC(a);
        else
            x = b, y = c, code = getFC(b);

        int l = 0, r = 0;

        while (l < x.size() && r < y.size())
        {
            while (l < x.size() && x[l] != code)
                cout << x[l++];
            if (l == x.size())
                break;

            while (r < y.size() && y[r] != code)
                cout << y[r++];
            if (r == y.size())
                break;

            cout << x[l], l++, r++;
        }

        while (l < x.size())
            cout << x[l++];

        while (r < y.size())
            cout << y[r++];

        cout << endl;
    }
}
// #include <bits/stdc++.h>
// #include <stdio.h>
// #define rep(i, n) for (int i = 0; i < n; i++)
// #define rrep(i, a, b) for (int i = a; i >= b; i--)
// #define rep1(i, n) for (int i = 1; i <= n; i++)
// #define fo(i, a, n) for (int i = a; i <= n; i++)
// #define repll(i, a, n) for (lli i = a; i <= n; i++)
// #define mkp make_pair
// #define pb emplace_back
// #define ff first
// #define ss second
// #define ll long long
// #define lli long long int
// #define ii int, int
// #define pii pair<int, int>
// #define pll pair<long, long>
// #define plli pair<long long int, long long int>
// #define vi vector<int>
// #define vvi vector<vector<int>>
// #define vlli vector<long long int>
// #define vpii vector<pair<int, int>>
// #define vplli vector<pair<long long int, long long int>>
// #define vvlli vector<vector<long long int>>
// #define MAXLL 1e18
// #define endl '\n'
// #define sp ' '
// #define dsort(v) sort(v.begin(), v.end(), greater<int>())
// #define asort(v) sort(v.begin(), v.end())
// #define uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
// #define all(v) v.begin(), v.end()
// #define umap unordered_map
// #define uset unordered_set
// #define sz(x) ((int)(x).size())
// #define yes cout << "YES\n"
// #define no cout << "NO\n"
// #define pr(x) cout << x
// #define prsp(x) cout << x << sp
// #define prln(x) cout << x << endl
// #define fastio ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0)
// #define read(a, n) \
//     rep(i, n)      \
//             cin >> \
//         a[i];
// using namespace std;

// // ///---------------Functions---------------------///
// // template <class T>
// // T gcd(T a, T b)
// // {
// //     if (a == 0)
// //         return b;
// //     return gcd(b % a, a);
// // }
// // template <class T>
// // T lcm(T a, T b)
// // {
// //     return (a * b) / __gcd(a, b);
// // }
// // template <class T>
// // T max(T a, T b)
// // {
// //     if (a > b)
// //         return a;
// //     else
// //         return b;
// // }
// // T min(T a, T b)
// // {
// //     if (a < b)
// //         return a;
// //     else
// //         return b;
// // }
// // template <class T>
// // T ceil(T numerator, T denominator)
// // {
// //     return (numerator + denominator - 1) / denominator;
// // }
// // template <class T>
// // bool isPrime(T N)
// // {
// //     for (T i = 2; i * i <= N; ++i)
// //     {
// //         if (N % i == 0)
// //             return false;
// //     }
// //     return true;
// // }
// // template <class T>
// // T cbrt(T x) //cuberoot
// // {
// //     T lo = 1, hi = min(2000000ll, x);
// //     while (hi - lo > 1)
// //     {
// //         T mid = (lo + hi) / 2;
// //         if (mid * mid * mid < x)
// //         {
// //             lo = mid;
// //         }
// //         else
// //             hi = mid;
// //     }
// //     if (hi * hi * hi <= x)
// //         return hi;
// //     else
// //         return lo;
// // }
// // template <class T>
// // T sqrt(T target)
// // {
// //     T l = 1, r = target;
// //     while (r > l + 1)
// //     {
// //         T m = (l + r) / 2;
// //         if (m * m <= target)
// //             l = m;
// //         else
// //             r = m;
// //     }
// //     return l;
// // }
// // void compress(vi &a)
// // {
// //     //for fenwick tree
// //     int n = sz(a);
// //     map<ii> mpp, back;
// //     int idx = 1;
// //     rep(i, n)
// //     {
// //         if (mpp.find(a[i]) == mpp.end())
// //         {
// //             mpp.insert({a[i], idx});
// //             back.insert({idx, a[i]}); //to get back original values
// //             idx++;
// //         }
// //     }
// //     rep(i, n)
// //     {
// //         a[i] = mpp[a[i]];
// //     }
// // }
// // ///---------------custom_hash---------------------///
// // class chash
// // {
// // public:
// //     static uint64_t splitmix64(uint64_t x)
// //     {
// //         x += 0x9e3779b97f4a7c15;
// //         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
// //         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
// //         return x ^ (x >> 31);
// //     }

// //     size_t operator()(uint64_t x) const
// //     {
// //         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
// //         return splitmix64(x + FIXED_RANDOM);
// //     }
// //     // umap<lli, lli, custom_hash> mp;
// // };

// // ///---------------variables---------------------///
// // const int dx[4] = {-1, 1, 0, 0};
// // const int dy[4] = {0, 0, -1, 1};
// // int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
// // int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
// const int mod = 1000000007;

// void solve()
// {
//     int n;
//     cin >> n;
//     string s1, s2, s3, a, b;
//     cin >> s1 >> s2 >> s3;
//     int cnt1_s1(0), cnt0_s1(0);
//     int cnt1_s2(0), cnt0_s2(0);
//     int cnt1_s3(0), cnt0_s3(0);
//     for (char c : s1)
//     {
//         if (c == '0')
//             cnt0_s1++;
//         else
//             cnt1_s1++;
//     }
//     for (char c : s2)
//     {
//         if (c == '0')
//             cnt0_s2++;
//         else
//             cnt1_s2++;
//     }
//     for (char c : s3)
//     {
//         if (c == '0')
//             cnt0_s3++;
//         else
//             cnt1_s3++;
//     }
//     char type1, type2, type3, part_of_lcs;
//     if (cnt1_s1 > cnt0_s1)
//     {
//         type1 = '1';
//     }
//     else
//         type1 = '0';
//     if (cnt1_s2 > cnt0_s2)
//     {
//         type2 = '1';
//     }
//     else
//         type2 = '0';
//     if (cnt1_s3 > cnt0_s3)
//     {
//         type3 = '1';
//     }
//     else
//         type3 = '0';

//     if (type1 == type2)
//     {
//         a = s1, b = s2;
//         part_of_lcs = type1;
//     }
//     else if (type1 == type3)
//     {
//         a = s1, b = s3;
//         part_of_lcs = type1;
//     }
//     else
//     {
//         a = s2, b = s3;
//         part_of_lcs = type2;
//     }

//     int i(0), j(0);
//     string ans;
//     while (i < sz(a) and j < sz(b))
//     {
//         while (i < sz(a) and a[i] != part_of_lcs)
//         {
//             ans.push_back(a[i]);
//             i++;
//         }
//         if (i >= sz(a))
//             break;

//         while (j < sz(a) and b[j] != part_of_lcs)
//         {
//             ans.push_back(b[j]);
//             j++;
//         }
//         if (j >= sz(b))
//             break;

//         //part_of lcs is found ,so take only one ie a[i] and b[j] both point to the same character
//         ans.push_back(a[i]);
//         i++, j++;
//     }
//     while (i < sz(a))
//     {
//         ans.push_back(a[i]);
//         i++;
//     }
//     while (j < sz(b))
//     {
//         ans.push_back(b[j]);
//         j++;
//     }
//     prln(ans);
//     return;
// }
// int32_t main()
// {
//     fastio;
//     int t = 1;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }
