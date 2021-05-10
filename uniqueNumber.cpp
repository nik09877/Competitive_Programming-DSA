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
// // int gcd(int a, int b)
// // {
// //     if (a == 0)
// //         return b;
// //     return gcd(b % a, a);
// // }
// // int lcm(int a, int b)
// // {
// //     return (a * b) / __gcd(a, b);
// // }
// // int max(int a, int b)
// // {
// //     if (a > b)
// //         return a;
// //     else
// //         return b;
// // }
// // int min(int a, int b)
// // {
// //     if (a < b)
// //         return a;
// //     else
// //         return b;
// // }
// // int ceil(int numerator, int denominator)
// // {
// //     return (numerator + denominator - 1) / denominator;
// // }
// // bool isPrime(int N)
// // {
// //     for (int i = 2; i * i <= N; ++i)
// //     {
// //         if (N % i == 0)
// //             return false;
// //     }
// //     return true;
// // }
// // int cbrt(int x) //cuberoot
// // {
// //     int lo = 1, hi = min(2000000ll, x);
// //     while (hi - lo > 1)
// //     {
// //         int mid = (lo + hi) / 2;
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
// // lli sqrt(lli target)
// // {
// //     lli l = 1, r = target;
// //     while (r > l + 1)
// //     {
// //         lli m = (l + r) / 2;
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
// bool comp(char a, char b)
// {
//     return a > b;
// }
// void solve()
// {
//     cout << "Enter a large number\n";
//     string s, ans;
//     cin >> s;
//     int n = sz(s);
//     rep(i, 10)
//     {
//         bool flag = false;
//         rep(j, n)
//         {
//             if (s[j] - '0' == i and !flag)
//             {
//                 ans.push_back(s[j]);
//                 flag = true;
//             }
//             else if (s[j] - '0' == i and flag)
//             {
//                 s[j] = '*';
//             }
//         }
//     }
//     cout << "The unique Digits Are:";
//     for (auto c : ans)
//     {
//         cout << c << ',';
//     }
//     sort(all(ans), comp);
//     int res = stoi(ans);
//     cout << "The Largest Number Possible Out Of These Unique Digits Is:";
//     cout << res << endl;

//     return;
// }
// int32_t main()
// {
//     fastio;
//     int t = 1;
//     while (t--)
//     {
//         solve();
//     }
// }

// import java.util.Scanner;

// class UniqueNumber
// {
// public
//     static void main(String args[])
//     {
//         System.out.println("Enter a large number");
//         Scanner sc = new Scanner(System.in);
//         String s, ans = "";
//         s = sc.nextLine();
//         int n = s.length();
//         for (int i = 0; i < 10; i++)
//         {
//             boolean flag = false;
//             for (int j = 0; j < n; j++)
//             {
//                 char ch = s.charAt(j);
//                 if (ch - '0' == i && !flag)
//                 {
//                     ans += ch;
//                     flag = true;
//                 }
//                 else if (ch - '0' == i && flag)
//                 {
//                     s.replace(s.charAt(j), '*');
//                 }
//             }
//         }
//         System.out.print("The unique Digits Are:");
//         for (int i = 0; i < ans.length(); i++)
//         {
//             System.out.print(ans.charAt(i) + " ");
//         }
//         System.out.println("\nThe Largest Number Possible Out Of These Unique Digits Is: ");
//         for (int i = ans.length() - 1; i >= 0; i--)
//         {
//             System.out.print(ans.charAt(i));
//         }
//     }
// }
