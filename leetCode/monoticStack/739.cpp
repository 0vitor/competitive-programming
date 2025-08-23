#include <vector>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define dbg(x) cout << #x << " " << x << endl;
#define forn(n, x)                   \
    cout << "[";                     \
    for (auto i = 0; i < n - 1; i++) \
    {                                \
        cout << x[i] << ", ";        \
    }                                \
    cout << x[n - 1] << "]" << endl;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    vector<int> res(temperatures.size());
    stack<pair<int, int>> stack;
    stack.push({0, temperatures[0]});
    for (int i = 1; i < temperatures.size(); i++)
    {
        while (!stack.empty() && temperatures[i] > stack.top().second)
        {
            res[stack.top().first] = i - stack.top().first;
            stack.pop();
        }
        stack.push({i, temperatures[i]});
    }

    return res;
}