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

void GRAPHshow(Graph G) {
    printf("=== LISTAS DE ADYACENCIA ===\n");
    for (vertex v = 0; v < G->V; v++) {
        printf("%d: ", v);
        for (link a = G->adj[v]; a != NULL; a = a->next)
            printf("%d ", a->w);
        printf("\n");
    }
}

// PROBLEMA 8:

void UGRAPHinsertEdge(Graph G, vertex v, vertex w) {
    if (v == w) return; // sin bucles

    // Verifica si la arista ya existe
    for (link a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;

    // Inserta en ambos sentidos
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->adj[w] = NEWnode(v, G->adj[w]);
    G->A++;
}


int main() {
    Graph G = GRAPHinit(5);

    UGRAPHinsertEdge(G, 0, 1);
    UGRAPHinsertEdge(G, 0, 4);
    UGRAPHinsertEdge(G, 1, 2);
    UGRAPHinsertEdge(G, 2, 3);
    UGRAPHinsertEdge(G, 3, 4);

    GRAPHshow(G);

    printf("\nNumero de aristas: %d\n", G->A);

    // Intento de insertar una arista ya existente
    printf("\nIntentando insertar (1 - 2) nuevamente...\n");
    UGRAPHinsertEdge(G, 1, 2);

    GRAPHshow(G);
    printf("Numero de aristas: %d\n", G->A);

    return 0;
}
