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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode *prev = nullptr, *curr = head, *next = nullptr;
    ListNode *before = nullptr, *after = nullptr;
    ListNode *headLeft = nullptr, *tailRight = nullptr;

    while (curr && left > 1)
    {
        next = curr->next;
        prev = curr;
        curr = next;
        left--;
        right--;
    }

    before = prev;
    headLeft = curr;

    next = curr->next;
    prev = curr;
    curr = next;
    // reverse slice
    while (curr && right > 1)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        right--;
    }

    tailRight = curr;
    after = next;

    before->next = tailRight;
    headLeft->next = after;

    return head;
}
