#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <climits> 

using namespace std;

class Graph {
private:
    static const int MAX = 5; 
    string cities[MAX] = {"Lahore", "Islamabad", "Karachi", "Multan", "Peshawar"}; 
    int adj[MAX][MAX]; 

public:
    Graph();
    void addRoute(int u, int v, int distance);
    void removeRoute(int u, int v);
    void findShortestRoute(int src, int dest);  
    void printRouteMap();
    int getCityIndex(string c);
};

#endif