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

    ~GraphAL() {
        delete[] adj;
        adj = nullptr;
    }

    void add_edge(Vertex u, Vertex v) {
        if (u >= num_vertices || v >= num_vertices || u == v) {
            throw invalid_argument("Argumentos inválidos");
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
        num_edges++;
    }

    void remove_edge(Vertex u, Vertex v) {
        if (u >= num_vertices || v >= num_vertices || u == v) {
            throw invalid_argument("Argumentos inválidos");
        }
        adj[u].remove(v);
        adj[v].remove(u);
        num_edges--;
    }

    list<Vertex> get_adj(Vertex u) {
        if (u >= num_vertices) {
            throw invalid_argument("Vértice inválido");
        }
        return adj[u];
    }

    uint get_num_vertices() {
        return num_vertices;
    }

    uint get_num_edges() {
        return num_edges;
    }

};

void print_adjacency_list(GraphAL& g) {
    uint n = g.get_num_vertices();
    cout << "num_vertices: " << n << endl;
    cout << "num_edges: " << g.get_num_edges() << endl;

    for (uint u = 0; u < n; ++u) {
        list<Vertex> l = g.get_adj(u);
        cout << u << ": ";
        for (const auto& v : l) {
            cout << v << ", ";
        }
        cout << endl;
    }
}

int main() {
    uint n = 0;
    uint m = 0;
    cin >> n >> m;

    GraphAL graph(n);

    uint u = 0, v = 0;

    for (uint i = 0; i < m; ++i) {
        cin >> u >> v;
        try {
            graph.add_edge(u, v);
        } catch (const invalid_argument& e) {
            cout << "Aviso: Aresta (" << u << ", " << v << ") ignorada - " << e.what() << endl;
        }
    }
    print_adjacency_list(graph);

    return 0;
}