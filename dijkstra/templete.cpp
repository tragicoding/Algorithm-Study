#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = 1e9; //무한대 값 설정

//[거리,노드]
vector<pair<int,int>> adj [20004]; //그래프의 인접 리스트 표현
vector<int> dist(20004,INF); //최단 거리 배열 

void dijkstra(int start)
{
    priority_queue<pair<int,int>
    , vector<pair<int,int>>
    , greater<pair<int,int>>> pq;//우선순위 큐의 선언(작은값 우선)
    //다음 노드 선택을 위한 우선순위 큐

    dist[start] = 0; 
    pq.push({0,start});//0은 거리, start는 지금의 정점

    while (!pq.empty())
    {
        int here_cost = pq.top().first;//현재 거리
        int u = pq.top().second;//현재 노드
        pq.pop();
        cout << "PQTOP\n";
        cout << u << "\n";

        if ( dist[u] != here_cost) continue;

        for (auto there : adj[u])
        {
            int new_cost = here_cost + there.first;

            //거리가 더 짧으면 이걸로 갱신.
            if (new_cost < dist[there.second])
            {
                dist[there.second] = new_cost;
                cout << there.second << ":" << new_cost << "\n";
                pq.push({new_cost , there.second});
            }
        }
    }

}