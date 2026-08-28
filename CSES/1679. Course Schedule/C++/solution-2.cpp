#include <bits/stdc++.h>
using namespace std;

vector<int> courseSchedule(int n, vector<vector<int>> courses)
{
    vector<vector<int>> adj(n);
    vector<int> inDegrees(n, 0);
    vector<int> result;
    result.reserve(n);

    for (const auto &course : courses)
    {
        adj[course[0] - 1].push_back(course[1] - 1);
        inDegrees[course[1] - 1]++;
    }

    queue<int> nodes;

    for (int i = 0; i < n; i++)
    {
        if (!inDegrees[i])
            nodes.push(i);
    }

    while (!nodes.empty())
    {
        int front = nodes.front();
        nodes.pop();
        result.push_back(front + 1);

        for (int child : adj[front])
        {
            inDegrees[child]--;
            if (!inDegrees[child])
                nodes.push(child);
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;
    vector<vector<int>> courses(m, vector<int>(2, 0));

    for (int i = 0; i < m; i++)
    {
        cin >> courses[i][0] >> courses[i][1];
    }

    vector<int> result = courseSchedule(n, courses);

    if (result.size() != n)
        cout << "IMPOSSIBLE";
    else
    {
        for (int value : result)
            cout << value << " ";
    }
    return 0;
}
