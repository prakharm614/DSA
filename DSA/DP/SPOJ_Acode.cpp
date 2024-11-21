#include<iostream>
#define ll long long
using namespace std;
// string decode(string &input){
//     string res="";
//     if(input.size()==1){
//         res+=(char)(64+input[0]-'0');
//     }
//     else {
//         int num=(input[0]-'0')*10+(input[1]-'0');
//         res+=(char)(64+num);
//     }
//     return res;

// }

vector<ll> dp;

ll helper(string &str, int i)
{

    if (i <= 0)
        return 1;
    if (dp[i] != -1)
        return dp[i];
    ll ans = 0;
    if (str[i] - '0' > 0)
    {
        ans += helper(str, i - 1);
    }
    if (str[i - 1] - '0' > 0 and (str[i - 1] - '0') * 10 + (str[i] - '0') <= 26)
    {

        ans += helper(str, i - 2);
    }
    return dp[i] = ans;
}

ll bottomup(string &str)
{
    dp.resize(5005, 0);

    dp[0] = 1;
    if (str.size() > 1)
    {
        if (str[1] != '0')
            dp[1] += dp[0];
        if ((str[0] - '0') * 10 + (str[1] - '0') <= 26)
            dp[1]++;
    }
        for (int i = 2; i < str.size(); i++)
        {
            // copy paste from prev just replace by dp
            ll ans = 0;
            if (str[i] - '0' > 0)
            {
                ans += dp[i - 1];
            }
            if (str[i - 1] - '0' > 0 and (str[i - 1] - '0') * 10 + (str[i] - '0') <= 26)
            {

                ans += dp[i - 2];
            }
            dp[i] = ans;
        }
        return dp[str.size() - 1];
    
}

int main()

{
    string n;
    cin >> n;

    while (n[0] != '0')
    {
        dp.clear();          // imp
        dp.resize(5005, -1); // not needed in bottom up

        // in bottom up
        // cout<<bottomup(n)<<'\n';
        cout << helper(n, n.size() - 1) << "\n";
        cin >> n;
    }
    return 0;
}