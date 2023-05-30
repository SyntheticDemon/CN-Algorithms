using namespace std;
#include <map>
#ifndef TOPOLOGYHPP
#define TOPOLOGYHPP

#include <vector>
using namespace std;
class Topology
{
private:
    map<int,map<int,int>> topology;
    int max_columns;
public:
    Topology(int& max_columns);
    int add_connection(int n_1,int n_2,int c);
    int remove_connection(int n_1,int n_2);
    int modify_connection(int n_1,int n_2 , int c);
    int show();
};
#endif