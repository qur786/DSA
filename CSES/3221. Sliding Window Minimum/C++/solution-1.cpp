#include <bits/stdc++.h>
using namespace std;

int getXorOfMinimums(vector<long long> &input, int k)
{
    int xo = 0;
    int size = input.size();
    deque<long long> dq;

    for (int i = 0; i < size; i++)
    {
        while (!dq.empty() && (i - dq.front()) >= k)
            dq.pop_front();
        while (!dq.empty() && (input[i] <= input[dq.back()]))
            dq.pop_back();
        dq.push_back(i);

        if (i >= (k - 1))
            xo ^= input[dq.front()];
    }

    return xo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, x, a, b, c;
    cin >> n >> k;
    cin >> x >> a >> b >> c;
    vector<long long> input;
    input.reserve(n);
    input.push_back(x);

    for (int i = 1; i < n; i++)
    {
        input.push_back((a * input[i - 1] + b) % c);
    }

    int xo = getXorOfMinimums(input, k);
    cout << xo;
    return 0;
}
