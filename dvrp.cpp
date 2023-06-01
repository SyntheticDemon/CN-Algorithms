#include <vector>
#include "topology.hpp"
using namespace std;
#include <iostream>
#define INF __INT_MAX__
using namespace std;
#include "dvrp.hpp"
#include <algorithm>
string shortest_path(vector<int> parents, int dest)
{
    string result = "[";
    int cur_place = dest;
    while (true)
    {

        int last_hop = parents[cur_place];
        if (last_hop == -1)
            break;
        cur_place = last_hop;
        result = result +  " <- " + to_string(last_hop);
    }
    result += "]";
    
    return result;
}
int next_hop(vector<int> parents, int source,int dest)
{
    int cur_place = dest;
    while (true)
    {

        int last_hop = parents[cur_place];
        if (last_hop == source)
            return cur_place;
        cur_place = last_hop;
    }
    return cur_place;
}
void DVRP::report()
{
    cout << "   Destination |"
         << "   Next Hop |"
         << "   Distance |"
         << "   Shortest Path " << endl;
    cout << "------------------------------------------------------------------" << endl;
    for (int i = parents.size() - 1; i > 1; i--)
    {
        cout<< "        " << i << "      | "
             << to_string(next_hop(parents,this->source,i))
             << "           | " << this->distances[i] << "       | " << shortest_path(this->parents, i) << endl;
    }
}

DVRP::DVRP(int node_count, int source, Topology *topology)
{
    this->topology = topology;
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
            int weight = std::get<2>(e);
            if (dist[v] + weight < dist[u])
            {
                dist[u] = dist[v] + weight;
                parents[u] = v;
                update_complete = true;
            }
        }
        if (!update_complete)
        {
            break;
        }
    }
    this->parents = parents;
    this->distances = dist;
    this->source=source;
}
