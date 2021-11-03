#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjLists;
};

struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);
void printGraph(struct Graph*);
void deleteG(struct Graph* graph, int ver_OTJ, int ver_OTJ1);
void rassh(struct Graph* graph, int ver_OTJ);
void sryg(struct Graph* graph, int ver_OTJ, int ver_OTJ1);

int main()
{
    setlocale(LC_ALL, "Rus");
    void styg(struct Graph* graph, int ver_OTJ, int ver_OTJ1);
    int versh, * a, i, ver, conect;
    int start, j;

    int size, ** graphM, n;

    struct Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 2, 0);
    addEdge(graph, 0, 3);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 4);
    /*cout << "Введите размерность: " << endl;
    cin >> size;


    srand(time(NULL));
    graphM = (int**)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        graphM[i] = (int*)malloc(size * sizeof(int));
    }
    bool* visited = new bool[size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < i + 1; j++) {
            int num = rand() % 2;
            graphM[i][j] = num;
            graphM[j][i] = num;
        }
    }


    cout << "Матрица смежности графа: " << endl;
    for (i = 0; i < size; i++)
    {
        visited[i] = false;
        for (j = 0; j < size; j++)
            cout << " " << graphM[i][j];
        cout << endl;
    }



        int  tmp;

        for (i = 0; i < size; i++)
        {
            for ( j = 0; j < size; j++)
            {
                if (graphM[i][j] == 0)
                {
                    addEdge(graph, i, j);
                }
            }
        }*/
    int ras, st1, st2, ot1, ot2;




    printf("______________________________________________________\nИзначальный граф");
    printGraph(graph);


    printf("______________________________________________________\nПосле стягивания ребера\n введите вершины");
    scanf_s("%d %d", &st1, &st2);
    sryg(graph, st1, st2);
    printGraph(graph);


    printf("______________________________________________________\nПосле отождествления вершин\n введите вершины ");
    scanf_s("%d %d", &ot1, &ot2);
    deleteG(graph, ot1, ot2);
    printGraph(graph);

    printf("______________________________________________________\n расщепление вершины\n введите вершину");
    scanf_s("%d", &ras);
    rassh(graph, ras);
    printGraph(graph);

    return 0;
}




struct node* createNode(int v)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    //graph->adjLists = (struct Graph*)malloc(vertices * sizeof(struct node*));
    graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));

    graph->visited = (int*)malloc(vertices * sizeof(int));


    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Список смежности вершины  %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void deleteG(struct Graph* graph, int ver_OTJ, int ver_OTJ1)
{
    int v = 0;
    struct node* temp = graph->adjLists[ver_OTJ];
    struct node* tempO = graph->adjLists[ver_OTJ1];


    for (v = 0; v < 5; v++) {
        temp = graph->adjLists[v];

        while (temp != NULL)
        {
            if (temp->vertex == ver_OTJ1 && v != ver_OTJ)
            {
                temp->vertex = ver_OTJ;
            }

            if (temp->vertex == ver_OTJ1 && v == ver_OTJ)
            {
                while (temp->next->next != NULL)
                {
                    temp->vertex = temp->next->vertex;
                    temp = temp->next;
                }
                temp->vertex = temp->next->vertex;
                free(temp->next);
                temp->next = NULL;
                delete temp->next;
            }

            temp = temp->next;

        }
    }
    tempO = graph->adjLists[ver_OTJ1];
    temp = graph->adjLists[ver_OTJ];
    while (tempO != NULL)
    {
        struct node* newNode = createNode(tempO->vertex);
        newNode->next = graph->adjLists[ver_OTJ];
        graph->adjLists[ver_OTJ] = newNode;
        tempO = tempO->next;

    }

    graph->adjLists[ver_OTJ1] = NULL;
    free(graph->adjLists[ver_OTJ1]);
    delete graph->adjLists[ver_OTJ1];
}

void sryg(struct Graph* graph, int ver_OTJ, int ver_OTJ1)
{
    int v = 0, drop = 0;
    struct node* temp = graph->adjLists[ver_OTJ];
    struct node* tempO = graph->adjLists[ver_OTJ1];
    while (temp->next != NULL)

    {

        if (temp->vertex == ver_OTJ1) {
            drop = -1;
        }
        temp = temp->next;
    }
    if (drop == -1)
    {
        for (v = 0; v < 5; v++) {
            temp = graph->adjLists[v];

            while (temp != NULL)
            {
                if (temp->vertex == ver_OTJ1 && v != ver_OTJ)
                {
                    temp->vertex = ver_OTJ;
                }

                if (temp->vertex == ver_OTJ1 && v == ver_OTJ)
                {
                    while (temp->next->next != NULL)
                    {
                        temp->vertex = temp->next->vertex;
                        temp = temp->next;
                    }
                    temp->vertex = temp->next->vertex;
                    free(temp->next);
                    temp->next = NULL;
                    delete temp->next;
                }

                temp = temp->next;

            }
        }
        tempO = graph->adjLists[ver_OTJ1];
        temp = graph->adjLists[ver_OTJ];
        while (tempO != NULL)
        {
            struct node* newNode = createNode(tempO->vertex);
            newNode->next = graph->adjLists[ver_OTJ];
            graph->adjLists[ver_OTJ] = newNode;
            tempO = tempO->next;

        }

        graph->adjLists[ver_OTJ1] = NULL;
        free(graph->adjLists[ver_OTJ1]);
        delete graph->adjLists[ver_OTJ1];

        struct node* temp = graph->adjLists[ver_OTJ];


        if (temp->vertex == ver_OTJ) {
            while (temp->next->next != NULL)
            {
                temp->vertex = temp->next->vertex;
                temp = temp->next;
            }
            temp->vertex = temp->next->vertex;
            free(temp->next);
            temp->next = NULL;
            delete temp->next;
        }
        temp = temp->next;
    }

    else printf("\nCтягивание не возможно\n");
}

void rassh(struct Graph* graph, int ver_OTJ)
{
    int v = 0;
    graph->numVertices = 6;

    graph->adjLists[5] = NULL;
    graph->visited[5] = 0;

    struct node* temp = graph->adjLists[5];
    struct node* tempO = graph->adjLists[ver_OTJ];
    while (tempO != NULL)
    {
        addEdge(graph, 5, tempO->vertex);
        tempO = tempO->next;
    }
    addEdge(graph, 5, ver_OTJ);


}
