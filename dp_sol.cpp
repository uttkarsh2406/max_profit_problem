#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD 1000000007

bool static comp(vector<int> &a, vector<int> &b)
{
    if (b[3] > a[3])
        return true;
    return false;
}

vector<vector<int>> res;
vector<int> v(4);
int help(int t, int st, vector<int> &dp)
{
    if (st + 4 > t)
    {
        res.push_back(v);
        return 0;
    }
    if (dp[t] != -1)
        return dp[t];
    ll ans1 = 0, ans2 = 0, ans3 = 0;

    v[0]++;
    v[3] += (((t - st - 5) > 0 ? t - st - 5 : 0) * 1500);
    ans1 = (((t - st - 5) > 0 ? t - st - 5 : 0) * 1500) + help(t, st + 5, dp);
    v[0]--;
    v[3] -= (((t - st - 5) > 0 ? t - st - 5 : 0) * 1500);

    v[1]++;
    v[3] += (((t - st - 4) > 0 ? t - st - 4 : 0) * 1000);
    ans2 = (((t - st - 4) > 0 ? t - st - 4 : 0) * 1000) + help(t, st + 4, dp);
    v[1]--;
    v[3] -= (((t - st - 4) > 0 ? t - st - 4 : 0) * 1000);

    v[2]++;
    v[2] += (((t - st - 10) > 0 ? t - st - 10 : 0) * 3000);
    ans3 = (((t - st - 10) > 0 ? t - st - 10 : 0) * 3000) + help(t, st + 10, dp);
    v[2]--;

    // cout << ans1 << " " << ans2 << " " << ans3 << endl;
    if (ans1 == 0 && ans2 == 0 && ans3 == 0)
    {
        return dp[t] = 0;
    }
    if (ans1 >= ans2 && ans1 >= ans3)
    {
        return dp[t + 5] = max({ans1, ans2, ans3});
    }
    else if (ans2 >= ans1 && ans2 >= ans3)
    {

        return dp[t + 4] = max({ans1, ans2, ans3});
    }
    else
    {
        return dp[t + 10] = ans3;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    ll time = 0;
    cin >> time;
    vector<int> dp(time + 1, -1);
    sort(res.begin(), res.end(), comp);
    ll max_earning = help(time, 0, dp);
    cout << max_earning << endl;
    // for(auto i:res){
    //     cout<<i[3]<<" ";
    //     cout<<endl;
    // }

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i][3] < max_earning)
        {
            break;
        }
        cout << "T:" << res[i][0] << ',' << "P:" << res[i][1] << ',' << "C:" << res[i][2] << endl;
    }

    v.clear();
    res.clear();
    v.resize(4);
}
