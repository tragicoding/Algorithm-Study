#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

int dijkstra(vector<vector<int>> graph)
{
    vector<int> dist(6,INT_MAX); //거리 갱신 벡터 : 모두 무한대로 초기화.(노드번호를 인덱스 번호와 맞추기 위해.)
    priority_queue< pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq; //{거리,노드}

    int start = 1; //첫번째 노드 번호
    int destination = 5;
    
    dist[start] = 0;
    pq.push(pair(0,start));

    while (!pq.empty())
    {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;

        pq.pop();

        //이미 기록된 최단 거리가 방금 꺼낸 거리보다 짧다면, 무시
        //즉, 오래된 기록임. 
        //한 노드까지 가는 거리가 5 였다가 나중에 3으로 갱신 되었다면,
        //그 5도 아직 우선순위 큐에 있으므로 그 5가 등장하면 무시한다. 
        if (current_distance > dist[current_node]) {continue;}
        
        for (int i = 0; i < graph.size(); i++ )
        {
            int from = graph[i][0];
            int to   = graph[i][1];
            int cost = graph[i][2];
            
            if (from != current_node) {continue;} // 현재 노드만 처리
            
            int new_distance = current_distance + cost;
            
            if (new_distance < dist[to]) //더 작은 놈으로 갱신
            {
                dist[to] = new_distance;
                pq.push(pair(new_distance,to));
            }
        }
        
        
        //경로탐색이 모두 끝난뒤 최종 목적지 까지의 경로가 존재하는지 확인
        if (dist[destination] == INT_MAX)
        {
            return -1;
        }

        return dist[destination];
}

int main()
{

    return 0;
}