#include "MaximalFlow.h"

#include "VertexContainer.h"

MaximalFlow::MaximalFlow(Graph* sg): sourceGraph(sg) { }

void MaximalFlow::solve(const Vertex& so, const Vertex& si) {

    source = so;
    sink = si;
    newGraph = new Graph(*sourceGraph);

    Path path = findPath(newGraph, source, sink);
    paths.push_back(path);
    maximalFlow += path.second;
    recalculateNet(path, newGraph);
}

MaximalFlow::Path MaximalFlow::findPath(Graph* graph, const Vertex& source, const Vertex& sink) {
    VertexContainer vertices = graph->vertices();
}

void MaximalFlow::recalculateNet(Path path, Graph* graph) {

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


