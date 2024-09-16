#include <iostream>
using namespace std;

const int V=7;


int min_key(int key[], bool visited[])
{
    int min = 99999999;
    int min_index;

    for (int v = 0; v < V; v++){
        if (visited[v] == false && key[v] < min){
            min = key[v];
            min_index = v;}
    }

    return min_index;
}


void printMST(int parent[], int graph[V][V])
{
    int totalcost;
    cout << "Edges \t  Weight\n";
    for (int i = 1; i < V; i++){
        cout << parent[i] << " --> " << i << "\t    "
             << graph[i][parent[i]] <<" \n";
        totalcost+=graph[i][parent[i]];}
    cout<<"Total cost = "<<totalcost;
}


void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool visited[V];
    for (int i = 0; i < V; i++){
        key[i] = 999999;
        visited[i] = false;}
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++) {
        int i = min_key(key, visited);
        visited[i] = true;
        for (int v = 0; v < V; v++){
            if (graph[i][v] && visited[v] == false
                && graph[i][v] < key[v])
                parent[v] = i, key[v] = graph[i][v];}
    }
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = { { 0, 2, 4, 1, 0, 0, 0 },
                        { 2, 0, 0, 3, 10, 0, 0 },
                        { 4, 0, 0, 2, 0, 5, 0 },
                        { 1, 3, 2, 0, 7, 8, 4 },
                        { 0, 10, 0, 7, 0, 0, 6 },
                        { 0, 0, 5, 8, 0, 0, 1 },
                        { 0, 0, 0, 4, 6, 1, 0 }
                        };

    primMST(graph);
    return 0;
}

