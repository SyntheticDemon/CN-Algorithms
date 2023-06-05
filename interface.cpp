#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "utils.hpp"
#include "interface.hpp"
#include "dvrp.hpp"
#include "lsrp.hpp"
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
    if (func == "topology")
    {
        int max_columns = 0;
        for (int i = 1; i < arguments.size(); i++)
        {
            vector<string> topology_node;
            topology_node = tokenizeee(arguments[i], '-');
            int first = atoi(topology_node[0].c_str());
            int second = atoi(topology_node[1].c_str());
            int determinant = max(first, second);
            max_columns = max(determinant, max_columns);
        }
        Topology *this_topology = new Topology(max_columns);
        this->topology = this_topology;
        for (int i = 1; i < arguments.size(); i++)
        {
            vector<string> topology_node;
            topology_node = tokenizeee(arguments[i], '-');
            int first = atoi(topology_node[0].c_str());
            int second = atoi(topology_node[1].c_str());
            int cost = atoi(topology_node[2].c_str());
            this->topology->add_connection(first, second, cost);
        }
        cout << "Recorded Topology : " << endl;
        this->topology->initialize_edges();
        this->topology->show();
    }
    else if (func == "modify")
    {
        vector<string> topology_node;
        topology_node = tokenizeee(arguments[1], '-');
        int first = atoi(topology_node[0].c_str());
        int second = atoi(topology_node[1].c_str());
        int cost = atoi(topology_node[2].c_str());
        int was_succesful = this->topology->modify_connection(first, second, cost);
        if (was_succesful == 1)
        {
            cout << "ERROR" << endl;
        }
        else if (was_succesful == 0)
        {
            cout << "OK" << endl;
        }
    }
    else if (func == "remove")
    {
        vector<string> one_and_two;
        one_and_two = tokenizeee(arguments[1], '-');
        int first = atoi(one_and_two[0].c_str());
        int second = atoi(one_and_two[1].c_str());
        int result = this->topology->remove_connection(first, second);
        if (!result)
        {

            cout << "OK" << endl;
        }
        else
        {
            cout << "ERROR" << endl;
        }
    }
    else if (func == "show")
    {
        this->topology->show();
    }
    else if (func == "dvrp")
    {
        double total_test_time = 0;
        cout << "Running DVRP " << endl;
        if (arguments.size() == 2)
        {
            // Runs for the source node
            int source_id = atoi(arguments[1].c_str());
            DVRP *Ran_DVRP = new DVRP(this->topology->max_columns, source_id, this->topology);
            Ran_DVRP->report();
            total_test_time += Ran_DVRP->profile();
        }
        else if (arguments.size() == 1)
        {

            for (int i = 1; i < this->topology->max_columns; i++)
            {
                cout << "DVRP for " << to_string(i) << endl;
                int source_id = i;
                DVRP *Ran_DVRP = new DVRP(this->topology->max_columns, source_id, this->topology);
                Ran_DVRP->report();
                total_test_time += Ran_DVRP->profile();
            }
            cout << "DVRP Total Running Time " << total_test_time << endl;
            // Runs for all nodes
        }
    }
    else if (func == "lsrp")
    {
        double total_test_time = 0;
        cout << "Running LSRP " << endl;
        vector<vector<int>> adj = this->topology->get_adjacency_edges();
        if (arguments.size() == 2)
        {
            // Runs for the source node
            int source_id = atoi(arguments[1].c_str());
            LSRP *Ran_LSRP = new LSRP(adj, source_id - 1);
            total_test_time += Ran_LSRP->profile();
        }
        else if (arguments.size() == 1)
        {
            for (int i = 0; i < this->topology->max_columns; i++)
            {
                cout << "LSRP for " << to_string(i + 1) << endl;
                int source_id = i;
                LSRP *Ran_LSRP = new LSRP(adj, source_id);
                total_test_time += Ran_LSRP->profile();
            }
            cout << "LSRP Total running time " << total_test_time << endl;
            // Runs for all nodes
        }
    }
    return 0;
}

int Interface::start()
{
    cout << "Enter Topology " << endl;
    vector<string> inputs;
    inputs = Interface::rcv_txt_input();
    Interface::apply_txt_input(inputs);
    // cout << "Enter rest of your commands " << endl;
    while (true)
    {
        vector<string> inputs_2;
        inputs_2 = Interface::rcv_txt_input();
        Interface::apply_txt_input(inputs_2);
    }

    return 0;
}