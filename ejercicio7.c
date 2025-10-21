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

void GRAPHshow(Graph G) {
    printf("=== LISTAS DE ADYACENCIA ===\n");
    for (vertex v = 0; v < G->V; v++) {
        printf("%d: ", v);
        for (link a = G->adj[v]; a != NULL; a = a->next)
            printf("%d ", a->w);
        printf("\n");
    }
}

// PROBLEMA 7:

bool GRAPHundir(Graph G) {
    for (vertex v = 0; v < G->V; v++) {
        for (link a = G->adj[v]; a != NULL; a = a->next) {
            vertex w = a->w;
            bool found = false;
            for (link b = G->adj[w]; b != NULL; b = b->next) {
                if (b->w == v) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
    }
    return true;
}


int main() {
    Graph G = GRAPHinit(4);

    // Creamos un grafo NO dirigido
    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 1, 0);
    GRAPHinsertArc(G, 1, 2);
    GRAPHinsertArc(G, 2, 1);
    GRAPHinsertArc(G, 2, 3);
    GRAPHinsertArc(G, 3, 2);

    GRAPHshow(G);
    printf("\nEl grafo es no dirigido? %s\n", GRAPHundir(G) ? "Si" : "No");

    // Ahora quitamos un arco para romper la simetría
    GRAPHinsertArc(G, 0, 2); // 0→2 pero no 2→0

    printf("\nDespues de insertar 0 - > 2:\n");
    GRAPHshow(G);
    printf("El grafo es no dirigido? %s\n", GRAPHundir(G) ? "Si" : "No");

    return 0;
}
