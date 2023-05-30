#include "topology.hpp"


int Topology::add_connection(int n_1,int n_2 , int cost){
    this->topology[n_1][n_2] = cost;
    return 0;
}
int Topology::modify_connection(int n_1, int n_2, int cost)
{
    this->topology[n_1][n_2] = cost;
    return 0;
}
int Topology::remove_connection(int n_1, int n_2)
{
    this->topology[n_1].erase(this->topology[n_1].find(n_2),this->topology[n_1].find(n_2));
    return 0;
}

int Topology::show(){
    

}