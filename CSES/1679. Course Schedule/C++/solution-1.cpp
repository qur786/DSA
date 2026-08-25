#include <bits/stdc++.h>
using namespace std;

vector<int> getCourseOrder(int n, vector<vector<int>> requirements)
{
    vector<vector<int>> adj(n);
    vector<int> inDegrees(n, 0);

    for (const auto &requirement : requirements)
    {
        const int topic1 = requirement[0] - 1, topic2 = requirement[1] - 1;
        adj[topic1].push_back(topic2);
        inDegrees[topic2]++;
    }

    queue<int> nodes;
    vector<int> answer;
    answer.reserve(n);

    for (int i = 0; i < n; i++)
        if (!inDegrees[i])
            nodes.push(i);

    while (!nodes.empty())
    {
        const int front = nodes.front();
        nodes.pop();
        answer.push_back(front + 1);

        for (int value : adj[front])
        {
            inDegrees[value]--;
            if (!inDegrees[value])
                nodes.push(value);
        }
    }

    if (answer.size() < n)
        return {};

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> requirements(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> requirements[i][0] >> requirements[i][1];
    }
    vector<int> output = getCourseOrder(n, requirements);

    if (output.empty())
        cout << "IMPOSSIBLE";
    else
    {
        for (int n : output)
            cout << n << " ";
    }

    return 0;
}
