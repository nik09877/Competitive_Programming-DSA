#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n <= 5)
        puts("-1");
    else
    {
        for (int i = 2; i <= 4; i++)
            printf("1 %d\n", i);
        for (int i = 5; i <= n; i++)
            printf("2 %d\n", i);
    }
    for (int i = 2; i <= n; i++)
        printf("1 %d\n", i);
}