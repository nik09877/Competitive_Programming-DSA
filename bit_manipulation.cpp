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
#define read(a, n) \
    rep(i, n)      \
            cin >> \
        a[i];
using namespace std;
const int mod = 1000000007;
class Bit
{
    // int cnt = __builtin_popcount(num);
public:
    bool check_ith_bit_set(unsigned int n, unsigned int i)
    {
        if (n & (1 << i))
            return true;
        return false;
    }
    bool power_of_two(unsigned int n)
    {
        if (n && !(n & (n - 1)))
            return true;
        return false;
    }
    unsigned int cnt_set_bit_of_a_num(unsigned int n)
    {
        unsigned int cnt = 0;
        while (n > 0)
        {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }
    unsigned int get_msb(unsigned int n)
    {
        int pos = 0;
        while (n > 1)
        {
            pos++;
            n >>= 1;
        }
        return pos;
        // fo(i, 31, 0)
        // {
        // if (n & (1 << i))
        // return i;
        // }
        // return 0;
    }
    unsigned int cnt_set_bit_upto_a_num(unsigned int A)
    { /*If we observe bits from rightmost side at distance i than bits get inverted after 2^i position in vertical sequence. 
        for example n = 5; 
        0 = 0000 
        1 = 0001 
        2 = 0010 
        3 = 0011 
        4 = 0100 
        5 = 0101
        Observe the right most bit (i = 0) the bits get flipped after (2^0 = 1) 
        Observe the 3rd rightmost bit (i = 2) the bits get flipped after (2^2 = 4) 
        So, We can count bits in vertical fashion such that at i’th right most position bits will be get flipped after 2^i iteration;*/
        if (A == 0)
        {
            return 0;
        }
        A = A + 1; //calculating from 0 to A so A+1 numbers are there
        ll int ans = 0;
        int pos = get_msb(A);
        for (int i = 0; i <= pos; i++)
        {
            ll int max_set_bits_possible_in_a_contiguous_substring = pow(2, i);
            ll int num_periods = (A / max_set_bits_possible_in_a_contiguous_substring);

            ll int num_periods_in_which_bits_are_set = num_periods / 2;
            ans += (num_periods_in_which_bits_are_set)*max_set_bits_possible_in_a_contiguous_substring;

            if (num_periods & 1)
            {
                ans += A % max_set_bits_possible_in_a_contiguous_substring;
            }
            if (ans > mod)
            {
                ans = ans % mod;
            }
        }

        return ans % mod;
    }
};

void solve()
{
    int n;
    cin >> n;
    Bit b;
    // cout << b.cnt_set_bit_upto_a_num(n) << endl;
    cout << b.get_msb(n);
    return;
}
int32_t main()
{
    fastio;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
