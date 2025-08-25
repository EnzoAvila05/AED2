#include <iostream>
#include <stdexcept>
#include <list>
typedef unsigned int uint;
typedef unsigned int Vertex;
using namespace std;

class GraphAL {
private:
    uint num_vertices;
    uint num_edges;
    list<Vertex>  *adj;

public:
    GraphAL() : num_vertices(0), num_edges(0) {}

    GraphAL(uint num_vertices) : num_vertices(num_vertices), num_edges(0) {
        adj = new list<Vertex>[num_vertices];
    }

    void add_edge(Vertex u, Vertex v) {
        if (u >= num_vertices || v >= num_vertices || u == v) {
            throw invalid_argument("Argumentos inválidos");
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
        num_edges++;
    }

    list<Vertex> get_adj(Vertex u) {
        return adj[u];
    }

    uint get_num_vertices() {
        return num_vertices;
    };

};

void print_graph(GraphAL g) {
    for (int u = 0; u < g.get_num_vertices(); ++u) {
        list<Vertex> adj_u = g.get_adj(u);
        for (const auto& v : adj_u) {
            cout << v << ", ";
        }
        cout << endl;
    }
}

int main() {
    GraphAL g(4);

    try {
        g.add_edge(0, 1);
        g.add_edge(1, 2);
        g.add_edge(2, 3);
        g.add_edge(3, 0);


        print_graph(g);
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }


    return 0;
}