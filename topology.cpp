#include "topology.hpp"
using namespace std;
#include <iostream>
#define INF (__INT_MAX__ - 1000)
Topology::Topology(int &max_columns)
{
    cout << "Max columns " << max_columns << endl;
    this->max_columns = max_columns;
    for (int i = 1; i <= max_columns; i++)
    {
        for (int j = 1; j <= max_columns; j++)
        {
            this->topology[j][i] = INF;
            this->topology[i][j] = INF;
        }
        this->topology[i][i] = 0;
    }
}
int Topology::add_connection(int n_1, int n_2, int cost)
{
    this->topology[n_1][n_2] = cost;
    this->topology[n_2][n_1] = cost;
    return 0;
}
int Topology::get_weight(int n_1, int n_2)
{
    return this->topology[n_1][n_2];
}
int Topology::modify_connection(int n_1, int n_2, int cost)
{
    if (n_1 > max_columns || n_2 > max_columns)
    {
        cout << "Node or connection doesnt exist " << max_columns << endl;
        return 1;
    }
    if (this->topology[n_1][n_2] == INF)
    {
        cout << "Connection never existed in the first place " << endl;
        return 1;
    }
    this->topology[n_1][n_2] = cost;
    return 0;
}
vector<tuple<int, int, int>> Topology::get_edges()
{
    return this->edges;
}
vector<vector<int>> Topology::get_adjacency_edges()
{
    vector<vector<int>> adjacency_topology;
    for (int i = 0; i < this->max_columns; i++)
    {
        vector<int> row;
        for (int j = 0; j < this->max_columns; j++)
        {
            row.push_back(0);
        }
        adjacency_topology.push_back(row);
    }
    for (int i = 0; i < this->topology.size(); i++)
    {
        for (int j = 0; j < this->topology.size(); j++)
        {
            if (this->topology[i + 1][j + 1] == INF)
                continue;
            adjacency_topology[i][j] = this->topology[i + 1][j + 1];
            adjacency_topology[j][i] = this->topology[i + 1][j + 1];
        }
    }
    return adjacency_topology;
}
void Topology::initialize_edges()
{
    for (int i = 1; i <= this->max_columns; i++)
    {
        for (int j = 1; j <= this->max_columns; j++)
        {
            int begin = i;
            int next_potential_hop = j;
            int weight = this->get_weight(begin, next_potential_hop);
            if (weight != INF)
            {
                tuple<int, int, int> edge;
                tuple<int, int, int> edge_2;
                edge = make_tuple(begin, next_potential_hop, weight);
                edge_2 = make_tuple(next_potential_hop, begin, weight);

                this->edges.push_back(edge);
                this->edges.push_back(edge_2);

                // cout <<"Edge : " << std::get<0>(edge) << " " << std::get<1>(edge) << " " << std::get<2>(edge) << endl;
            }
        }
    }
}
int Topology::remove_connection(int n_1, int n_2)
{
    if (n_1 > max_columns || n_2 > max_columns)
    {
        cout << "Node or connection doesnt exist " << max_columns << endl;
        return 1;
    }
    if (this->topology[n_1][n_2] == INF)
    {
        cout << "Connection never existed in the first place " << endl;
        return 0;
    }
    this->topology[n_1][n_2] = INF;
    this->topology[n_2][n_1] = INF;

    return 0;
}

int Topology::show()
{
    map<int, map<int, int>>::iterator itr;
    map<int, int>::iterator itr_inner;
    cout << "  | ";
    for (itr = this->topology.begin(); itr != this->topology.end(); ++itr)
    {
        cout << " " << itr->first << " ";
    }

    cout << endl
         << "------------------------------------------------" << endl;
    for (itr = this->topology.begin(); itr != this->topology.end(); ++itr)
    {
        cout << itr->first << " | ";
        for (itr_inner = itr->second.begin(); itr_inner != itr->second.end(); ++itr_inner)
        {
            if (itr_inner->second == INF)
            {
                cout << " "
                     << "INF"
                     << " ";
            }
            else
            {

                cout << " " << itr_inner->second << " ";
            }
        }
        cout << endl;
    }
    return 0;
}