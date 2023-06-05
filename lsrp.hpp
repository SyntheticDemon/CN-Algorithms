#ifndef LSRPHPP
#define LSRPHPP
#include <vector>
#include "topology.hpp"
#include <sstream>
using namespace std;
#include <iostream>
#include <chrono>
#define INF (__INT_MAX__ - 1000)
using namespace std;

class LSRP
{
public:
    LSRP(vector<vector<int>> graph, int source_id);
    void lsrpAlgorithm(vector<vector<int>> graph, int source);
    double profile();
    double taken;
    int minimumDistance(vector<int> dist, vector<bool> sptSet);
    void ShortestPath(vector<int> distances, vector<int> parent, int source);
    void iterationLspr(vector<int> distances, int ItrNum);
};
#endif