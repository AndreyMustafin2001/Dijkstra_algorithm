#include <iostream>
#include <vector>
#include <limits>

void updateDist(std::vector<std::vector<int>> &graph,int v,std::vector<int> &dist)
{
    for (int u = 0;u < graph.size();u++)
    {
        if (graph[v][u] != -1)
        {
            if (dist[u] == -1 || dist[u] > dist[v] + graph[v][u])
            {
                dist[u] = dist[v] + graph[v][u];
            }
        }
    }
}

int minDistVertex(std::vector<int> &dist,std::vector<bool> &visited)
{
    int minIndex = -1;
    int minDist = std::numeric_limits<int>::max();

    for (int i = 0;i < dist.size();i++)
    {
        if (!visited[i] && (minIndex == -1 || dist[i] < minDist))
        {
            minIndex = i;
            minDist = dist[i];
        }
    }

    return minIndex;
}

void dijkstra( std::vector<std::vector<int>>& graph,int start)
{
    int n = graph.size();
    std::vector<int> dist(n, -1);
    std::vector<bool> visited(n,false);

    dist[start] = 0;

    int count = 0;
    while (count < n)
    {
        int v = minDistVertex(dist,visited);

        if (v == -1)
            break;

        visited[v] = true;
        updateDist(graph,v,dist);

        count++;
    }

    for (int i = 0;i < n;i++)
    {
        std::cout << "Shortest distance from " << start << " to " << i << " is " << dist[i] << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> graph = {
        {1, 5, 3, -1},
        {5, 1, 2, 1},
        {3, 2, 1, 4},
        {-1, 1, 4, 1}
    };

    int start = 0;
    dijkstra(graph,start);

    return 0;
}
