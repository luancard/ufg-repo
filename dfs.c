#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Estrutura de um nó para a lista de adjacência.
typedef struct Node {
    int vertex;         // Vértice adjacente.
    struct Node* next;  // Próximo nó na lista.
} Node;

// Estrutura para representar o grafo.
typedef struct Graph {
    Node* adjacencyList[MAX_VERTICES];  // Lista de adjacência para cada vértice.
    bool visited[MAX_VERTICES];         // Array para controlar os vértices visitados.
} Graph;

// Estrutura de pilha para auxiliar na DFS.
typedef struct Stack {
    int data[MAX_VERTICES];
    int top;
} Stack;

// Função para criar um novo grafo com o número especificado de vértices.
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    for (int i = 0; i < vertices; ++i) {
        graph->adjacencyList[i] = NULL;   // Inicializa a lista de adjacência.
        graph->visited[i] = false;        // Inicializa os vértices como não visitados.
    }
    return graph;
}

// Função para adicionar uma aresta ao grafo.
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;               // Define o vértice de destino da nova aresta.
    newNode->next = graph->adjacencyList[src];  // Insere o novo nó no início da lista de adjacência.
    graph->adjacencyList[src] = newNode;
}

// Função para empilhar um valor na pilha.
void push(Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

// Função para desempilhar um valor da pilha.
int pop(Stack* stack) {
    return stack->data[stack->top--];
}

// Função para verificar se a pilha está vazia.
bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

// Função de busca em profundidade (DFS).
void dfs(Graph* graph, int vertex, Stack* stack) {
    graph->visited[vertex] = true;
    Node* adjNode = graph->adjacencyList[vertex];
    while (adjNode != NULL) {
        if (!graph->visited[adjNode->vertex]) {
            dfs(graph, adjNode->vertex, stack);   // Realiza DFS no vértice adjacente não visitado.
        }
        adjNode = adjNode->next;
    }
    push(stack, vertex);  // Empilha o vértice após visitar todos os seus vizinhos.
}

// Função para transpor o grafo (trocar direções das arestas).
void transposeGraph(Graph* graph, Graph* transposedGraph, int vertices) {
    for (int v = 0; v < vertices; ++v) {
        Node* adjNode = graph->adjacencyList[v];
        while (adjNode != NULL) {
            addEdge(transposedGraph, adjNode->vertex, v);  // Inverte as direções das arestas (para realizar o DFS pela segunda vez)
            adjNode = adjNode->next;
        }
    }
}

// Função para imprimir um componente conectado.
void printDFS(Graph* graph, int vertex) {
    printf("%d ", vertex);
    graph->visited[vertex] = true;
    Node* adjNode = graph->adjacencyList[vertex];
    while (adjNode != NULL) {
        if (!graph->visited[adjNode->vertex]) {
            printDFS(graph, adjNode->vertex);  // Realiza a impressão DFS no vértice adjacente não visitado.
        }
        adjNode = adjNode->next;
    }
}

// Função para imprimir os componentes fortemente conexos.
void printStronglyConnectedComponents(Graph* graph, int vertices) {
    Stack stack;
    stack.top = -1;

    // Realiza a DFS em todos os vértices não visitados.
    for (int v = 0; v < vertices; ++v) {
        if (!graph->visited[v]) {
            dfs(graph, v, &stack);
        }
    }

    // Cria o grafo transposto e realiza a DFS novamente usando a pilha.
    Graph* transposedGraph = createGraph(vertices);
    transposeGraph(graph, transposedGraph, vertices);

    // Reinicializa a marcação de vértices como não visitados.
    for (int i = 0; i < vertices; ++i) {
        graph->visited[i] = false;
    }

    // Imprime os componentes fortemente conexos.
    while (!isStackEmpty(&stack)) {
        int vertex = pop(&stack);
        if (!transposedGraph->visited[vertex]) {
            printf("Componente: ");
            printDFS(transposedGraph, vertex);
            printf("\n");
        }
    }

    // Libera a memória alocada para o grafo transposto.
    free(transposedGraph);
}

int main() {
    int vertices, edges;
    printf("Informe o numero de vertices: ");
    scanf("%d", &vertices);
    printf("Informe o numero de arestas: ");
    scanf("%d", &edges);

    // Cria um novo grafo.
    Graph* graph = createGraph(vertices);

    printf("Informe as arestas (inicio -> destino):\n");
    // Adiciona as arestas ao grafo.
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Componentes fortemente conexos:\n");
    // Encontra e imprime os componentes fortemente conexos.
    printStronglyConnectedComponents(graph, vertices);

    // Libera a memória alocada para o grafo.
    free(graph);

    return 0;
}