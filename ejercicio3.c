#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define vertex int

typedef struct node *link;
struct node {
    vertex w;
    link next;
};

typedef struct graph {
    int V;
    int A;
    link *adj;
} *Graph;

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
    for (link a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->A++;
}

// PROBLEMA 3:

bool GRAPHadjacent(Graph G, vertex v, vertex w) {
    for (link a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w)
            return true;
    return false;
}


int main() {
    Graph G = GRAPHinit(6);

    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 5);
    GRAPHinsertArc(G, 1, 0);
    GRAPHinsertArc(G, 1, 5);
    GRAPHinsertArc(G, 2, 4);
    GRAPHinsertArc(G, 3, 1);
    GRAPHinsertArc(G, 5, 3);


    printf("\n=== PRUEBA DE ADYACENCIA ===\n");
    printf("0 - 1? %s\n", GRAPHadjacent(G, 0, 1) ? "SI" : "No");
    printf("1 - 2? %s\n", GRAPHadjacent(G, 1, 2) ? "SI" : "No");
    printf("5 - 3? %s\n", GRAPHadjacent(G, 5, 3) ? "SI" : "No");
    printf("4 - 2? %s\n", GRAPHadjacent(G, 4, 2) ? "SI" : "No");

    return 0;
}
