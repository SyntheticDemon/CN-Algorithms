using namespace std;
#include <map>
#ifndef TOPOLOGYHPP
#define TOPOLOGYHPP
#include <vector>
#include <tuple>
using namespace std;
class Topology
{
private:
    map<int, map<int, int>> topology;
    vector<tuple<int, int, int>> edges;

public:
    int max_columns;
    Topology(int &max_columns);
    void initialize_edges();
    vector<tuple<int, int, int>> get_edges();
    int get_weight(int n_1, int n_2);
    int add_connection(int n_1, int n_2, int c);
    int remove_connection(int n_1, int n_2);
    int modify_connection(int n_1, int n_2, int c);
    int show();
};
#endif