#include "lsrp.hpp"
#include <queue>
#include <algorithm>
#include <sstream>
#include <iomanip>

void LSRP::iterationLspr(vector<int> distances, int ItrNum) {
    cout << "Iter " << ItrNum << ":" << endl;
    cout << "Dest ";
    for (int i = 0; i < distances.size(); i++){
        cout << i + 1 << " |";
    }
    cout << endl;
    cout << "Cost ";
    for (int i = 0; i < distances.size(); i++){
        cout << distances[i] << " |";
    }
    cout << endl;
    cout << "--------------------------" << endl;
}

void LSRP::ShortestPath(vector<int> distances, vector<int> parent, int source) {
    stringstream ss;
    ss << "Path [source] -> [destination] | Min-Cost | Shortest-Path\n";
    int i = 0;
    while (i < distances.size()) {
        if (i != source) {
            vector<int> route;
            int index = i;
            while (index != source) {
                route.push_back(index);
                index = parent[index];
            }
            route.push_back(source);
            reverse(route.begin(), route.end());
            
            string path_str = to_string(source + 1);
            int j = 1;
            while (j < route.size()) {
                path_str += "->" + to_string(route[j] + 1);
                j++;
            }
            ss << setw(3) << source + 1 << " | " << setw(3) << i + 1 << " | " << setw(7) << distances[i] << " | " << path_str << "\n";
        }
        i++;
    }
    cout << ss.str();
}

int LSRP::minimumDistance(vector<int> distances, vector<bool> visitedNodes) {
    int minimum_distance = 99999, minimum_index;
    int k = 0;
    while (k < distances.size()) {
        if (visitedNodes[k] == false && distances[k] <= minimum_distance) {
            minimum_distance = distances[k];
            minimum_index = k;
        }
        k++;
    }
    return minimum_index;
}


void LSRP::lsrpAlgorithm(vector<vector<int>> graph, int source) {
    vector<bool> visited(graph.size(), false);
    vector<int> distances(graph.size(), 99999);
    vector<int> parent(graph.size(), -1);
    distances[source] = 0;
    int i = 0;
    while (i < graph.size() - 1) {
        const int u = minimumDistance(distances, visited);
        visited[u] = true;
        int k = 0;
        while (k < graph.size()) {
            if (!visited[k] && graph[u][k] && distances[u] != 99999 && distances[u] + graph[u][k] < distances[k]) {
                distances[k] = distances[u] + graph[u][k];
                parent[k] = u;
            }
            ++k;
        }
        iterationLspr(distances, i + 1); 
        ++i;
    }
    ShortestPath(distances, parent, source);
}

void LSRP::profile()
{
    cout << "LSRP Took " << this->taken << endl;
}

LSRP::LSRP(vector<vector<int>> graph, int source_id) {
    auto start = chrono::steady_clock::now();
    this->lsrpAlgorithm(graph, source_id);
    auto finish = chrono::steady_clock::now();
    double taken = std::chrono::duration_cast<std::chrono::duration<double>>(finish - start).count();
    this->taken = taken; 
}