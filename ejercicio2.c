#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define vertex int

// ======= Estructuras =======

typedef struct node *link;
struct node {
    vertex w;
    link next;
};

typedef struct graph {
    int V;      // número de vértices
    int A;      // número de arcos
    link *adj;  // vector de listas de adyacencia
} *Graph;

// ======= Funciones base =======

static link NEWnode(vertex w, link next) {
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    return a;
}

Graph GRAPHinit(int V) {
    Graph G = malloc(sizeof(*G));
    G->V = V;
    G->A = 0;
    G->adj = malloc(V * sizeof(link));
    for (vertex v = 0; v < V; v++)
        G->adj[v] = NULL;
    return G;
}

void GRAPHinsertArc(Graph G, vertex v, vertex w) {
    // Evita duplicados
    for (link a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->A++;
}

// PROBLEMA 2

int GRAPHoutdeg(Graph G, vertex v) {
    int count = 0;
    for (link a = G->adj[v]; a != NULL; a = a->next)
        count++;
    return count;
}

int GRAPHindeg(Graph G, vertex v) {
    int count = 0;
    for (vertex u = 0; u < G->V; u++) {
        for (link a = G->adj[u]; a != NULL; a = a->next)
            if (a->w == v) count++;
    }
    return count;
}



int main() {
    Graph G = GRAPHinit(6); // Creamos un grafo con 6 vértices (0..5)

    // Insertamos algunos arcos
    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 5);
    GRAPHinsertArc(G, 1, 0);
    GRAPHinsertArc(G, 1, 5);
    GRAPHinsertArc(G, 2, 4);
    GRAPHinsertArc(G, 3, 1);
    GRAPHinsertArc(G, 5, 3);

    printf("\n=== GRADOS DE LOS VÉRTICES ===\n");
    for (vertex v = 0; v < G->V; v++) {
        printf("Vertice %d : outdeg = %d, indeg = %d\n",
               v, GRAPHoutdeg(G, v), GRAPHindeg(G, v));
    }

    return 0;
}
