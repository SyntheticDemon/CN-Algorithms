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

<img alt="alt_text" src="images/DVRP_removal_out.png"/>

##### LSRP Results

<img alt="alt_text" src="images/LSRP_removal_out.png"/>

