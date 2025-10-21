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

// PROBLEMA 5:

void GRAPHdestroy(Graph G) {
    if (G == NULL) return;

    for (vertex v = 0; v < G->V; v++) {
        link a = G->adj[v];
        while (a != NULL) {
            link temp = a;
            a = a->next;
            free(temp);
        }
    }

    free(G->adj);
    free(G);
}


int main() {
    Graph G = GRAPHinit(6);

    GRAPHinsertArc(G, 0, 1);
    GRAPHinsertArc(G, 0, 5);
    GRAPHinsertArc(G, 1, 5);
    GRAPHinsertArc(G, 3, 1);
    GRAPHinsertArc(G, 5, 3);

    GRAPHshow(G);

    // Liberamos la memoria del grafo
    GRAPHdestroy(G);
    printf("\nGrafo destruido y memoria liberada correctamente.\n");

    return 0;
}
