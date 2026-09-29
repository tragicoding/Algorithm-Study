#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <limits.h>

using namespace std;

vector<int> solution(
    int n,
    vector<vector<int>> paths,
    vector<int> gates,
    vector<int> summits)
{
    // 우선순위 큐: {intensity, node}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    // 각 노드까지 도달하는 최소 intensity
    vector<int> intensity(n + 1, INT_MAX);

    // gate와 summit 여부
    vector<bool> is_gate(n + 1, false);
    vector<bool> is_summit(n + 1, false);


    //gate와 summit 거르기
    for (int i = 0; i < gates.size(); i++)
    {
        is_gate[gates[i]] = true;
    }

    for (int i = 0; i < summits.size(); i++)
    {
        is_summit[summits[i]] = true;
    }

    // 인접 리스트 생성
    vector<vector<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < paths.size(); i++)
    {
        int from = paths[i][0];
        int to = paths[i][1];
        int cost = paths[i][2];

        // 양방향 등산로
        graph[from].push_back(make_pair(to, cost));
        graph[to].push_back(make_pair(from, cost));
    }

    // 모든 gate에서 동시에 시작
    for (int i = 0; i < gates.size(); i++)
    {
        int gate = gates[i];

        intensity[gate] = 0;
        pq.push(make_pair(0, gate));
    }

    // 다익스트라
    while (!pq.empty())
    {
        int current_intensity = pq.top().first;
        int current_node = pq.top().second;

        pq.pop();

        // 오래된 경로라면 건너뛰기
        if (current_intensity > intensity[current_node])
        {
            continue;
        }

        // 현재 노드가 산봉우리라면 더 이상 이동하지 않음
        if (is_summit[current_node])
        {
            continue;
        }

        // 현재 노드에서 연결된 모든 경로 확인
        for (int i = 0; i < graph[current_node].size(); i++)
        {
            int to = graph[current_node][i].first;
            int cost = graph[current_node][i].second;

            // 다른 gate를 중간에 방문하지 않도록 건너뛰기
            if (is_gate[to])
            {
                continue;
            }

            // 지금까지 지나온 간선 비용 중 최댓값
            int next_intensity =
                max(current_intensity, cost);

            // 더 작은 intensity로 갈 수 있다면 갱신
            if (next_intensity < intensity[to])
            {
                intensity[to] = next_intensity;

                pq.push(
                    make_pair(next_intensity, to)
                );
            }
        }
    }

    // intensity가 같으면 번호가 작은 산봉우리 선택
    sort(summits.begin(), summits.end());

    int max_intensity = INT_MAX;
    int summit_node = 0;

    for (int i = 0; i < summits.size(); i++)
    {
        int summit = summits[i];

        if (intensity[summit] < max_intensity)
        {
            max_intensity = intensity[summit];
            summit_node = summit;
        }
    }

    // 반환 순서: {산봉우리 번호, 최소 intensity}
    vector<int> result;

    result.push_back(summit_node);
    result.push_back(max_intensity);

    return result;
}