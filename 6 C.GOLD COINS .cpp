#include<bits/stdc++.h>
using namespace std;
#define int long long //delete if causing problems
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define setbit(n) __builtin_popcount(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define fast  ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n" //delete if interactive
#define MOD 1000000007
const int inf = 1e18;
int power(int a, int b);


signed   main()
{
    fast
    int t = 1;
    //cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n + 1], pre[n + 1];

        pre[0] = 0;

        int sum = 0;


        for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + a[i];
        }

        int l = 1, r = a[n] - a[1], ans;

        auto check = [&](int val)
        {
            int prev = 1;

            int j = 2;


            for (int i = 1; i <= (k - 1); i++)
            {

                while (j <= n && a[j] - a[prev] < val)
                {
                    j++;

                }

                if (j > n) return false;

                prev = j;

            }

            return true;

        };

        while (r >= l)
        {
            int mid = (l + (r - l) / 2);

            if (check(mid))
            {
                ans = mid;
                l = mid + 1;

            }
            else {
                r = mid - 1;


            }
        }

        //dbg(check(10));


        cout << ans << endl;


    }
    return 0;
}

int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2) b-- , res = res * a;
        else b = b / 2 , a *= a;
    }
    return res;
}

/*
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
*/