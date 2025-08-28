#include <iostream>
#include <stdexcept>
#include <list>
#include <vector>

typedef unsigned int Vertex;
typedef unsigned int uint;
typedef unsigned int Weight;
using namespace std;

class GraphAM {
 private:

    uint num_vertices;
    uint num_edges;
    vector<vector<Weight>> adj;

public:

    GraphAM(uint num_vertices) : num_vertices(num_vertices), num_edges(0), adj(num_vertices, vector<Weight>(num_vertices, 0)) {
    }

    ~GraphAM() {
      //Destrutor automático do próprio vector;
    }

    void add_edge(Vertex u, Vertex v) {
    if (u >= num_vertices || v >= num_vertices || u == v) {
        throw invalid_argument("Argumentos inválidos");
    }
    adj[u][v] = 1;
    adj[v][u] = 1;
    num_edges++;
    }

    uint get_num_vertices() {
        return num_vertices;
    }

    uint get_num_edges() {
        return num_edges;
    }

    list<Vertex> get_adj(Vertex u) {
        if (u >= num_vertices) {
            throw invalid_argument("Vértice inválido");
        }

    }

    vector<vector<Weight>> get_adj_matrix() {
      return adj;
    }

};

void print_adjacency_matrix(GraphAM graph) {

    cout << "num_vertices: " << n << endl;
    cout << "num_edges: " << graph.get_num_edges() << endl;
}

int main() {
  GraphAM graph;
}