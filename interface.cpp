#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "utils.hpp"
#include "interface.hpp"
using namespace std;

vector<string> Interface::rcv_txt_input()
{
    string input_string;
    getline(std::cin, input_string);
    vector<string> tokens = tokenizeee(input_string, ' ');
    return tokens;
}

int Interface::apply_txt_input(vector<string> arguments)
{
    string func = arguments[0];
    Topology this_topology;
    this->topology = &this_topology;
    if (func == "topology")
    {

        for (int i = 1; i < arguments.size(); i++)
        {
            cout << "Instantiating the first connection";
            vector<string> topology_node;
            topology_node = tokenizeee(arguments[i], '-');
            int first = atoi(topology_node[0].c_str());
            int second = atoi(topology_node[1].c_str());
            int cost = atoi(topology_node[2].c_str());
            this_topology.add_connection(first, second, cost);
        }
    }
    else if (func == "modify")
    {
    }
    else if (func == "remove")
    {
    }
    return 0;
}

int Interface::start()
{
    cout << "Enter Topology " << endl;
    vector<string> inputs;
    inputs = Interface::rcv_txt_input();
    Interface::apply_txt_input(inputs);
    return 0;
}