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

    void remove_edge(Vertex u, Vertex v) {
        if (u >= num_vertices || v >= num_vertices || u == v) {
            throw std::invalid_argument("Argumentos inválidos");
        }
        adj[u][v] = 0;
        adj[v][u] = 0;
        num_edges--;
    }


    list<Vertex> get_adj(Vertex u) {
        if (u >= num_vertices) {
            throw std::invalid_argument("Vértice inválido");
        }
        list<Vertex> adjacentes;
        for (Vertex v = 0; v < num_vertices; v++) {
            if (adj[u][v] != 0) {
                adjacentes.push_back(v);
            }
        }
        return adjacentes;
    }

    vector<vector<Weight>> get_adj_matrix() {
      return adj;
    }

    uint get_num_vertices() const{
        return num_vertices;
    }

    uint get_num_edges() const{
        return num_edges;
    }

};

void print_adjacency_matrix(GraphAM& g) {
    uint n = g.get_num_vertices();
    cout << "num_vertices: " << n << endl;
    cout << "num_edges: " << g.get_num_edges() << endl;

    auto matrix = g.get_adj_matrix();
    for (uint u = 0; u < n; ++u) {
        for (uint v = 0; v < n; ++v) {
            cout << matrix[u][v];
            if (v < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    uint n = 0;
    uint m = 0;
    cin >> n >> m;

    GraphAM graph(n);

    Vertex u = 0, v = 0;

    for (uint i = 0; i < m; ++i) {
        cin >> u >> v;
        try {
            graph.add_edge(u, v);
        } catch (invalid_argument& e) {
            cout << "Aviso: Aresta (" << u << ", " << v << ") ignorada - " << e.what() << endl;
        }
    }

    print_adjacency_matrix(graph);

    return 0;
}