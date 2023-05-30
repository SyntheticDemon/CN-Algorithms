#ifndef INTERFACEHPP
#define INTERFACEHPP
#include  "topology.hpp" 
#include <string>
class Interface
{
private:
    Topology *topology;

public:
    int receive_toplogy();
    int start();
    int initialize();
    vector<string> rcv_txt_input();
    int apply_txt_input(vector<string> arguments);
};
#endif 