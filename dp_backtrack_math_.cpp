// dp[i][j] represents that is it possible to have the remainder j from 0 to i.

// let me explain to you with the example

// take the num 3454 for this number dp matrix will be of order 5*8

// for i = 1 : only possible rem is 3

// for i = 2 rem possible are: [3 for number 3] [2 for number 34]

// in case 34 rem 2 is possible only you take numbers 3 and 4 both, right! so newRem = (rem*10 + a[i])%8 => (3*10 + 4)%8 === 2. To have the rem is equal to 2 you have to check whether it is possible to have rem as 3 which comes for previous i. That's where dp[i-1][rem] comes into play.

// similarly, if you are not taking number 4 into account then rem == 3 which comes from prev number. So in this case too you have to check for dp[i-1][rem] is possible or not.

// for i = 3 rem possible are: [3 for num 3] [4 for num 4] [5 for num 5] [2 for num 34] [5 for num 45] [1 for num 345]

// You can observe that all the rem depends upon the prev values expect for the remainder of size 1 for that particular i that's why you take dp[i][a[i]%10] = 1.

// I hope you understand the concept well!

// for recursive print
// dp[i][a[i]] = 1;
// prev[i][a[i]] = -1;
// if (dp[i - 1][j] == 1 && dp[i][(j * 10 + a[i]) % 8] == 0){
//     dp[i][(j * 10 + a[i]) % 8] = 1;
//     prev[i][(j * 10 + a[i]) % 8] = j;
// }
// if (dp[i - 1][j] == 1 && dp[i][j]  == 0){
//     dp[i][j] = 1;
//     prev[i][j] = j;
// }
// When you are printing answer, you may do it recursively, like

// void recursive_print(int i, int j){
//     if (prev[i][j] == -1){
//         cout << a[i];
//         return;
//     }
//     int k = prev[i][j];
//     recursive_print(i - 1, k);
//     if ((k * 10 + a[i]) % 8 == j){
//         cout << a[i];
//     }

#include <bits/stdc++.h>
 
using namespace std;
 
#define sz(x) (int) x.size()
#define all(a) a.begin(), a.end()
#define prev sadasdjksgjkasjdklaj
 
const int MAXN = 105;
 
string s;
int n;
bool dp[MAXN][8];
int prev[MAXN][8];
 
int main() {
 
    getline(cin, s);
    n = sz(s);
 
    memset(prev, -1, sizeof(prev));
 
    dp[0][(s[0] - '0') % 8] = true;
 
    for (int i = 1; i < n; i++) {
        dp[i][(s[i] - '0') % 8] = true;
 
        for (int j = 0; j < 8; j++) {
            if (dp[i - 1][j]) {
                dp[i][(j * 10 + s[i] - '0') % 8] = true;
                prev[i][(j * 10 + s[i] - '0') % 8] = j;
 
                dp[i][j] = true;
                prev[i][j] = j;
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (dp[i][0]) {
            string ans = "";
            int curI = i, curJ = 0;
 
            while (true) {
                if (prev[curI][curJ] == -1 || prev[curI][curJ] != curJ) {
                    ans.append(1, s[curI]);
                }
 
                if (prev[curI][curJ] == -1) break;
 
                curJ = prev[curI][curJ];
                curI--;
            }
 
            puts("YES");
            reverse(all(ans));
            cout << ans << endl;
            return 0;
        }
    }
 
    puts("NO");
 
    return 0;
}