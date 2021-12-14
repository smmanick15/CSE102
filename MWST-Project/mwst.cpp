// C++ program to find the Minimum Weight Spanning Tree
// of a given weight connected (undirected graph) 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <iomanip>      
#include <math.h> 
using namespace std;
  
// create integer pair
typedef pair<int, int> intPair;
  
// structure to represent a graph
struct Graph
{
    int V, E;
    // vector to store edges and weights
    vector < pair <intPair, intPair> > edges;
  
    // Constructor
    Graph(int V, int E)
    {
        this->V = V;    // V = number of vertices
        this->E = E;    // E = number of edges
    }
  
    // Utility function to add an edge
    // u = first vertice point
    // v = second vertice point
    // w = weight of edge
    // p = position (label for output)
    void addEdge(int u, int v, int w, int p)
    {
        intPair new_edge = make_pair(u, v);
        intPair new_wp = make_pair(w, p);        
        edges.push_back(make_pair(new_wp, new_edge));

    }
  
    // Function to find MST using Kruskal's
    // MST algorithm
    int kruskalMST(char *pointer); // pointer = output file
};
  
// to represent disjoint sets
struct DisjointSets
{
    int *parent, *rank;
    int n;
  
    // constructor
    DisjointSets(int n)
    {
        // allocate memory
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];
  
        // all vertices are in different sets and have rank 0
        for (int i = 0; i <= n; i++)
        {
            rank[i] = 0;
  
            //every element is parent of itself
            parent[i] = i;
        }
    }
  
    // find parent of node 'u'
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
  

    void merge(int x, int y)
    {
        x = find(x), y = find(y);
  
        if (rank[x] > rank[y])
            parent[y] = x;
        else 
            parent[x] = y;
  
        if (rank[x] == rank[y])
            rank[y]++;
    }
};
  
 
// function that writes output to output file  
int Graph::kruskalMST(char *pointer)
{
    float mwst_weight = 0; // initialize mwst weight
  
    // sort edges in increasing order of weight
    sort(edges.begin(), edges.end());
  
    // create disjoint sets
    DisjointSets ds(V);

  
    // iterate through sorted edges
    vector< pair<intPair, intPair> >::iterator it;
    FILE *write_out = NULL;
    write_out = fopen(pointer, "w");
    if (write_out == NULL) {
        return 0;
    }

    for (it=edges.begin(); it!=edges.end(); it++)
    {
        int w = it->first.first;
        int p = it->first.second;
        int u = it->second.first;
        int v = it->second.second;
  
        int set_u = ds.find(u);
        int set_v = ds.find(v);
  
        // check if selected edge creates a cycle
        if (set_u != set_v)
        {

            // current edge will be in MWST
            float weight = w;
            // write the edge, weight, and label to output file
            fprintf(write_out, "%4d: (%d, %d) %0.1f\n", p, u, v, weight);
  
            // update MST weight
            mwst_weight += it->first.first;
  
            // merge two sets
            ds.merge(set_u, set_v);
        }

       
    }

    // write out the total weight for the MWST
    fprintf(write_out, "Total Weight = %0.2f\n", mwst_weight);

    // close output file
    fclose(write_out);
  
    return mwst_weight;
}
  

int main(int argc, char **argv)
{
    FILE *read_input = NULL;
    bool open_file = false;

    if (argc > 1) {
        open_file = true;
    }

    // open input file from command line argument
    if (open_file == true) {
        read_input = fopen(argv[1], "r");
        if (read_input == NULL) {
            return 0;
        } 
    }

    int V;
    int E;

    fscanf(read_input, "%d", &V);
    fscanf(read_input, "%d", &E);

    int u;
    int v;
    int w;

    Graph g(V, E); // create graph for given Vertices and Edges

    int p = 0;
    // loop to read through edges and weights
    while (fscanf(read_input, "%d %d %d", &u, &v, &w) != EOF) {
        p += 1;
        g.addEdge(u, v, w, p);  // add edges to graph
    }

    // write output to output file in the following function call
    // and calculate the total weight of MWST
    float mwst_weight = g.kruskalMST(argv[2]);


    fclose(read_input);
  
    mwst_weight += 1; //to silence unused variable warning
    
    return 0;
}
