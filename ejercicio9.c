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

// Inserta una arista (no dirigida)
void UGRAPHinsertEdge(Graph G, vertex v, vertex w) {
    if (v == w) return;

    for (link a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;

    G->adj[v] = NEWnode(w, G->adj[v]);
    G->adj[w] = NEWnode(v, G->adj[w]);
    G->A++;
}

// PROBLEMA 9: 

void GRAPHremoveArc(Graph G, vertex v, vertex w) {
    link prev = NULL;
    link a = G->adj[v];
    while (a != NULL) {
        if (a->w == w) {
            if (prev == NULL)
                G->adj[v] = a->next;
            else
                prev->next = a->next;
            free(a);
            return;
        }
        prev = a;
        a = a->next;
    }
}

// PROBLEMA 9:
void UGRAPHremoveEdge(Graph G, vertex v, vertex w) {
    if (v == w) return;

    GRAPHremoveArc(G, v, w);
    GRAPHremoveArc(G, w, v);

    G->A--;
}


int main() {
    Graph G = GRAPHinit(5);

    UGRAPHinsertEdge(G, 0, 1);
    UGRAPHinsertEdge(G, 0, 4);
    UGRAPHinsertEdge(G, 1, 2);
    UGRAPHinsertEdge(G, 2, 3);
    UGRAPHinsertEdge(G, 3, 4);

    printf("ANTES DE ELIMINAR:\n");
    GRAPHshow(G);
    printf("Numero de aristas: %d\n", G->A);

    printf("\nEliminando arista (2 - 3)...\n");
    UGRAPHremoveEdge(G, 2, 3);

    printf("\nDESPUES DE ELIMINAR:\n");
    GRAPHshow(G);
    printf("Numero de aristas: %d\n", G->A);

    return 0;
}
