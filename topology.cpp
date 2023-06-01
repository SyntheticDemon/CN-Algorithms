#include "topology.hpp"
using namespace std;
#include <iostream>
#define INF __INT_MAX__
Topology::Topology(int &max_columns)
{
    int max = max_columns;
    cout << "Max columns " << max_columns << endl;
    this->max_columns = max_columns;
    for (int i = 1; i <= max_columns; i++)
    {
        for (int j = 1; j <= max_columns; j++)
        {
            this->topology[i][j] = INF;
        }
        this->topology[i][i] = 0;
    }
    this->initialize_edges();
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
void Topology::initialize_edges()
{
    for (int i = 1; i <= this->max_columns; i++)
    {
        for (int j = i; j <= this->max_columns; j++)
        {
            int begin = i;
            int next_potential_hop = j;
            int weight = this->get_weight(begin, next_potential_hop);
            if (weight != INF)
            {
                tuple<int, int, int> edge;
                edge = make_tuple(begin, next_potential_hop, weight);
                this->edges.push_back(edge);
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
            cout << " " << itr_inner->second << " ";
        }
        cout << endl;
    }
    return 0;
}