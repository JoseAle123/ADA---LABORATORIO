#include <stdio.h>
#include <stdlib.h>

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

// Inserta arista no dirigida (v–w)
void UGRAPHinsertEdge(Graph G, vertex v, vertex w) {
    if (v == w) return;

    for (link a = G->adj[v]; a != NULL; a = a->next)
        if (a->w == w) return;

    G->adj[v] = NEWnode(w, G->adj[v]);
    G->adj[w] = NEWnode(v, G->adj[w]);
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

// PROBLEMA 10:

int UGRAPHdegrees(Graph G) {
    int maxDegree = 0;

    for (vertex v = 0; v < G->V; v++) {
        int degree = 0;
        for (link a = G->adj[v]; a != NULL; a = a->next)
            degree++;

        if (degree > maxDegree)
            maxDegree = degree;
    }

    return maxDegree;
}

// ======= MAIN DE PRUEBA =======
int main() {
    Graph G = GRAPHinit(5);

    UGRAPHinsertEdge(G, 0, 1);
    UGRAPHinsertEdge(G, 0, 4);
    UGRAPHinsertEdge(G, 1, 2);
    UGRAPHinsertEdge(G, 2, 3);
    UGRAPHinsertEdge(G, 3, 4);
    UGRAPHinsertEdge(G, 4, 1);

    GRAPHshow(G);

    int max = UGRAPHdegrees(G);
    printf("\nEl grado maximo del grafo es: %d\n", max);

    return 0;
}
