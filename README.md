# CN-Algorithms

## How to run

You can run a simple test by executing test.sh

```
./test.sh
```

or
Build with

```
make
```

## Commands

### Record a topology for testing

```
topology <src,dest,cost>,<src_2,dest_2,cost_2>...
```

### Render an adjacency matrice for the toplogy

```
show 
```

### Remove a connection

```
remove <start,dst>
```

### Modify a connection

```
modify <start,dst,new_cost>
```

## Execution Results

```
./test.sh
```

#### Test.sh tests the LSRP and DVRP algorithms and reports their execution time

##### initial execution

<img alt="alt_text" src="images/run.png"/>

##### Adjacency renderation

<img alt="alt_text" src="images/show.png"/>

##### Running time for DVRP on all dests and sources

<img alt="alt_text" src="images/DVRP_out.png"/>

##### Running time for LSRP on all dests and sources

<img alt="alt_text" src="images/LSRP_out.png"/>

### Running the test that removes an edge 

```
sh test_edge_removal.sh
```

##### DVRP Results

<img alt="alt_text" src="images/DVRP_out.png"/>

##### DVRP With removal Results

<img alt="alt_text" src="images/DVRP_removal_out.png"/>

##### LSRP Results

<img alt="alt_text" src="images/LSRP_out.png"/>

##### LSRP With removal Results

<img alt="alt_text" src="images/LSRP_removal_out.png"/>


## Explaining the code 


### Interface
An interface is wrapped around the Algorithms, and the topology class which allows instantiation of their instances. 


<img alt="alt_text" src="images/Interface.png"/>

### Topology 

a utillity class designed to act as a container for the data, the only class that offers certain degree of mutabillity 

<img alt="alt_text" src="images/Topology.png"/>

### Algorithms and Their Implementations 
The algorithm look the same, both have implementations , reportage and profiling inside them .

##### The class supports the main functionalities mentioned
<img alt="alt_text" src="images/DVRP_class.png"/>

##### DVRP implementation follows a raw bellman ford approach

<img alt="alt_text" src="images/DVRP_impl.png"/>

##### The class supports the main functionalities mentioned
<img alt="alt_text" src="images/LSRP_class.png"/>



##### Implementation closely follow the djkistra algorithm
<img alt="alt_text" src="images/LSRP_impl.png"/>


## Explaining the results 

Linkstate algorithm whcih is based on  Djikstra algorithm  is actually O(V^3) but Bellman ford is of order O(E*V) and it's used by DVRP , now these orders are actually multiplied by v in our implementation , because they are for all nodes once, thus we expect the DVRP algorithm to have a better performance and our results adhere to that .