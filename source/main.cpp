
#include <iostream>
#include <fstream>

#include "Graph.h"
#include "GraphFactory.h"
#include "MaximalFlow.h"

#include "Vertex.h"
#include "Edge.h"

#include <QDebug>

#include <iostream>

using namespace std;

int main() {

    ifstream in;
    in.open("D:/Projects/Qt/Graphs/source/input.txt", ios::in);
    int numOfVertex, numOfEdge;
    int sourceVertex, destinationVertex;
    Graph* graph = new Graph();
    GraphFactory* factory = GraphFactory::instance();
    MaximalFlow maxFlow(graph);

    in >> numOfVertex >> numOfEdge;            // считываем количество вершин и ребер
    in >> sourceVertex >> destinationVertex;   // считываем источник и сток
    for (int i = 0, u, v, cap; i < numOfEdge; i++) {
        in >> u >> v >> cap;
        graph->addEdge(Edge(Vertex(QString::number(u)), Vertex(QString::number(v)), cap, Edge::Orientation::LeftToRight));
        graph->addVertex(Vertex(QString::number(u)));
        graph->addVertex(Vertex(QString::number(v)));
        graph->addEdge(Edge(Vertex(QString::number(v)), Vertex(QString::number(u)), 0, Edge::Orientation::LeftToRight));
    }

    in.close();
    maxFlow.solve(Vertex(QString::number(sourceVertex)), Vertex(QString::number(destinationVertex)));
    cout << maxFlow.getMaximalFlow() << endl;
    for (auto & edges: maxFlow.getPaths()) {
        for (auto & edge: edges.first)
            std::cout << edge.left().id().toStdString() << " -> " << edge.right().id().toStdString() << " ; ";
        std::cout << " : " << edges.second << '\n';
    }
    return 0;
}














