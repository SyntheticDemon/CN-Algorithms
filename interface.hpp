#ifndef INTERFACEHPP
#define INTERFACEHPP
#include  "topology.hpp" 
class Interface
{
private:
    Topology *topology;

public:
    int receive_toplogy();
    int start();
    int initialize();
    int show_toplogy();
    vector<string> rcv_txt_input();
    int apply_txt_input(vector<string> arguments);
};
#endif 