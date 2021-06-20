#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <iostream>
#include <functional>
#include <bitset>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pii, int> p3i;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<p3i> v3i;
typedef vector<vii> vvii;
typedef vector<p3i> vp3i;
typedef long double ld;
typedef vector<ld> vld;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define REPD(i, n) for (int(i) = (n)-1; (i) >= 0; (i)--)
#define FOR(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define FORD(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define rv(v) reverse(all(v))
#define CL(v, val) memset((v), (val), sizeof((v)))
#define SORT(a) sort(all(a))
#define un(v) SORT(v), (v).resize(unique(all(v)) - (v).begin())
#define eps 1.0e-9
#define X first
#define Y second
#define bit(n) (1 << (n))
#define bit64(n) (ll(1) << (n))
#define sqr(x) ((x) * (x))
#define sq5(x) ((x) * (x) * (x) * (x) * (x))
#define N 100005

char s[N];

int main(void)
{
    int t;
    scanf("%d", &t);
    REP(test, t)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        scanf("%s", &s);
        string S = (string)s;

        bool ok = 0;
        int price = 0;
        int k = 0;
        int pr = 0;
        REP(i, sz(S))
        {
            if (S[i] == '1')
            {
                if (pr == 0)
                {
                    if (ok)
                    {
                        if (k * b < a)
                        {
                            price += k * b;
                        }
                        else
                        {
                            price += a;
                        }
                    }
                    else
                    {
                        price += a;
                    }
                }

                pr = 1;
                ok = 1;
                k = 0;
            }
            else
            {
                k++;
                pr = 0;
            }
        }

        printf("%d\n", price);
    }
}
