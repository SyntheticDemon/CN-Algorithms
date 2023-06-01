#include <vector>
#include "topology.hpp"
#define INF __INT_MAX__
using namespace std;
class DVRP
{
    int node_count;
    Topology *topology;
    DVRP(int node_count, int source);
};

DVRP::DVRP(int node_count, int source)
{
    vector<bool> nodes_updated(node_count + 1, false);
    vector<int> dist(node_count + 1, INF);
    vector<int> parents(node_count + 1, -1);
    dist[source] = 0; // Distance to source is always 0
    while (true)
    {
        bool update_complete = false;
        vector<tuple<int, int, int>> edges = this->topology->get_edges();
        for (tuple<int, int, int> e : edges)
        {
            int v = std::get<0>(e);
            int u = std::get<1>(e);
            int weight = std::get<1>(e);
            if (dist[v] + weight < dist[u])
            {
                dist[u] = dist[v] + weight;
                parents[u] = v;
                update_complete = true;
            }
        }
        if (update_complete)
        {
            break;
        }
    }
}
