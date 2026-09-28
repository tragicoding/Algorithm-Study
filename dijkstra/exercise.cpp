#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

int dijkstra(const vector<vector<int>> & graph)
{
    int start = 1;
    int destination = 5;

    vector<int> dist(6,INT_MAX);
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    //{거리,노드}

    dist[start] = 0;
    pq.push({0,start});
    
    while (!pq.empty())
    {
        int current_distance = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (current_distance > dist[current_node]) {continue;}

        for (int i = 0; i < graph.size() ; i ++)
        {
            int from = graph[i][0];
            int to = graph[i][1];
            int cost = graph[i][2];

            if (from != current_node) {continue;}
            
            int new_distance = current_distance + cost;

            if ( new_distance < dist[to] )
            {
                dist[to] = new_distance;
                pq.push(make_pair(new_distance,to));
            }
        }
        
    }

    if (dist[destination] == INT_MAX) { return -1; }

    return dist[destination];
}

int main()
{
    return 0;
}