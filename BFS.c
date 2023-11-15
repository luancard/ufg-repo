#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Definição da estrutura de dados para representar o grafo.
typedef struct {
    int vertices[MAX_VERTICES][MAX_VERTICES];  // Matriz de adjacência representando as arestas entre vértices.
    int numVertices;                           // Número total de vértices no grafo.
    bool isDirected;                           // Indica se o grafo é direcionado (true) ou não (false) (stdbool).
} Graph;

// Definição da estrutura de dados para a fila usada no algoritmo de busca em largura (BFS).
typedef struct {
    int data[MAX_VERTICES];  // Array para armazenar os elementos na fila.
    int front;               // Índice da frente da fila.
    int rear;                // Índice do final da fila.
} Queue;

// Inicializa a estrutura do grafo com o número de vértices e se é direcionado ou não.
void initGraph(Graph *graph, int numVertices, bool isDirected) {
    graph->numVertices = numVertices;
    graph->isDirected = isDirected;

    // Inicializa a matriz de adjacência com zeros.
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            graph->vertices[i][j] = 0;
        }
    }
}

// Adiciona uma aresta entre os vértices "from" e "to" no grafo.
void addEdge(Graph *graph, int from, int to) {
    graph->vertices[from][to] = 1;
    if (!graph->isDirected) {
        graph->vertices[to][from] = 1; // Se não for direcionado, também adiciona a aresta inversa.
    }
}

// Realiza a busca em largura (BFS) a partir de um vértice de partida.
void bfs(Graph *graph, int startVertex) {
    bool visited[MAX_VERTICES] = { false }; // Array para controlar os vértices visitados.
    Queue queue;
    queue.front = queue.rear = -1; // Inicializa os índices da fila.

    queue.data[++queue.rear] = startVertex; // Coloca o vértice inicial na fila.
    visited[startVertex] = true; // Marca o vértice inicial como visitado.

    while (queue.front < queue.rear) {
        int currentVertex = queue.data[++queue.front]; // Pega o próximo vértice da fila.
        printf("%d ", currentVertex); // Imprime o vértice visitado.

        // Percorre os vértices adjacentes ao vértice atual.
        for (int i = 0; i < graph->numVertices; i++) {
            // Se existe uma aresta entre o vértice atual e o vértice i, e o vértice i não foi visitado.
            if (graph->vertices[currentVertex][i] == 1 && !visited[i]) {
                queue.data[++queue.rear] = i; // Coloca o vértice i na fila.
                visited[i] = true; // Marca o vértice i como visitado.
            }
        }
    }
}

int main() {
    int numVertices, numEdges, startVertex;
    bool isDirected;

    // Leitura dos parâmetros do grafo.
    printf("Informe o numero de vertices: ");
    scanf("%d", &numVertices);

    printf("Informe o numero de arestas: ");
    scanf("%d", &numEdges);

    printf("O grafo e direcionado? (1 para sim, 0 para nao): ");
    scanf("%d", &isDirected);

    Graph graph;
    initGraph(&graph, numVertices, isDirected);

    // Leitura das arestas.
    printf("Informe as arestas:\n");
    for (int i = 0; i < numEdges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        addEdge(&graph, from, to);
    }

    // Leitura do vértice de partida para a busca em largura.
    printf("Informe o vertice de inicio da busca: ");
    scanf("%d", &startVertex);

    // Realiza a busca em largura a partir do vértice de partida.
    printf("Busca em largura a partir do vertice %d: ", startVertex);
    bfs(&graph, startVertex);

    return 0;
}