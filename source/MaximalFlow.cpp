#include "MaximalFlow.h"

#include <numeric>
#include <QDebug>

#include "VertexContainer.h"

using namespace graph;

MaximalFlow::MaximalFlow(Graph* sg): sourceGraph(sg) { }

void MaximalFlow::solve(const Vertex& so, const Vertex& si) {
    source = so;
    sink = si;
    newGraph = new Graph(*sourceGraph);

    for (Path path{{}, 1}; path.second != 0; ) {
        path = findPath(newGraph, source, sink);
        qDebug() << "path found, length is: " << path.second << '\n';
        if (path.second != 0) {
            paths.push_back(path);
            maximalFlow += path.second;
            qDebug() << "Total length is: " << maximalFlow << '\n';
            recalculateNet(path, newGraph);
        }

    }
    calculateMaximalFlowPerEdge(newGraph, sourceGraph);
}

#include <iostream>

MaximalFlow::Path MaximalFlow::findPath(Graph* graph, const Vertex& source, const Vertex& sink) {
    Path path{{}, std::numeric_limits<int>::max()};
    QVector<Vertex> vertexPath{source};
    QVector<Vertex> markedZero{};
    Vertex currentVertex = source;
    while (currentVertex != sink) {
        EdgeContainer edges = filterEdges(filterEdges(graph->edges(currentVertex), vertexPath), markedZero);
        Edge edge{};
        auto it = std::max_element(edges.begin(), edges.end(), [](const Edge& ob1, const Edge& ob2) -> bool {
            return ob1.value() < ob2.value();
        });
        if (it != edges.end())
            edge = *it;
        qDebug() << "max element for vertex: " << currentVertex.id() << " is: " << edge.left().id() << " " <<
        edge.right().id() << " " << edge.value();
        for (auto & v: vertexPath)
            std::cout << v.id().toStdString() << " ";
        std::cout << '\n';
        if (edge.value() == 0 && currentVertex == source) {
            return Path{{}, 0};
        }
        else if (edge.value() == 0) {
            vertexPath.removeLast();
            markedZero.push_back(currentVertex);
            currentVertex = vertexPath.last();
            path.first.remove(path.first.size()-1);
        }
        else {
            path.first.push_back(edge);
            path.second = std::min(path.second, edge.value());
            currentVertex = edge.right();
            vertexPath.push_back(currentVertex);
        }
    }
    return path;
}
EdgeContainer MaximalFlow::filterEdges(const EdgeContainer& oldEdges, const QVector<Vertex>& ids) {
    EdgeContainer edges = oldEdges;

    for (const auto & vertex: ids)
        edges.remove_if([&vertex](const Edge& e) { return vertex == e.right(); });
/*    std::cout << "indexes: ";
    for (const auto & vertex: ids)
        std::cout << vertex.id().toStdString() << " ";
    std::cout << '\n';
    std::cout << "edges: ";
    for (const auto& edge: edges)
        std::cout << edge.right().id().toStdString() << " ";
    std::cout << '\n';*/
    return edges;
}

void MaximalFlow::recalculateNet(Path path, Graph* graph) {
    for (auto & edge: path.first) {
        auto adjacentEdge = graph->edge(edge.right(), edge.left());
        graph->removeEdge(edge);
        graph->removeEdge(adjacentEdge);
        edge.setValue(edge.value() - path.second);
        adjacentEdge.setValue(adjacentEdge.value() + path.second);
        graph->addEdge(edge);
        graph->addEdge(adjacentEdge);
    }
}

void MaximalFlow::calculateMaximalFlowPerEdge(Graph* newg, Graph* oldg) {

}


int MaximalFlow::getMaximalFlow() const {
    return maximalFlow;
}

QVector<QPair<EdgeContainer, int>> MaximalFlow::getPaths() const {
    return paths;
}

QVector<QPair<Edge, int>> MaximalFlow::getMaximalFlowPerEdges() const {
    return maximalFlowPerEdge;
}


