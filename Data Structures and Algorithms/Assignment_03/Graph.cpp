#include "Graph.h"

Graph::Graph() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }
}

int Graph::getCityIndex(string c) {
    for (int i = 0; i < MAX; i++) {
        if (cities[i] == c)
            return i;
    }
    return -1;
}

void Graph::addRoute(int u, int v, int distance) {
    if (u >= 0 && u < MAX && v >= 0 && v < MAX) {
        adj[u][v] = distance;
        adj[v][u] = distance; // Assuming undirected roads, though assignment implies directed flow, usually logistics are bi-directional.
    }
}

void Graph::removeRoute(int u, int v) {
    if (u >= 0 && u < MAX && v >= 0 && v < MAX) {
        adj[u][v] = 0;
        adj[v][u] = 0;
    }
}

void Graph::printRouteMap() {
    cout << "  ";
    for(int i=0; i<MAX; i++) cout << cities[i].substr(0,3) << " ";
    cout << endl;
    for (int i = 0; i < MAX; i++) {
        cout << cities[i].substr(0,3) << " ";
        for (int j = 0; j < MAX; j++) {
            cout << adj[i][j] << "   ";
        }
        cout << endl;
    }
}

void Graph::findShortestRoute(int src, int dest) {
    int dist[MAX];
    bool visited[MAX];
    int parent[MAX]; 

    for (int i = 0; i < MAX; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < MAX - 1; count++) {
        int min = INT_MAX, u = -1;
        
        for (int v = 0; v < MAX; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                u = v;
            }
        }

        if (u == -1) 

        visited[u] = true;

        for (int v = 0; v < MAX; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INT_MAX 
                && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
        }
    }

    if (dist[dest] == INT_MAX) {
        cout << "No route exists from " << cities[src] << " to " << cities[dest] << endl;
    } else {
        cout << "Shortest Route: ";
        
        int path[MAX];
        int pathIdx = 0;
        int crawl = dest;
        path[pathIdx++] = crawl;
        
        while (parent[crawl] != -1) {
            crawl = parent[crawl];
            path[pathIdx++] = crawl;
        }

        for (int i = pathIdx - 1; i >= 0; i--) {
            cout << cities[path[i]];
            if (i > 0) cout << " -> ";
        }
        cout << " (Distance: " << dist[dest] << " km)" << endl;
    }
}