#pragma once

#include <QVector>

#include "Graph.h"
#include "EdgeContainer.h"
#include "Edge.h"
#include "Vertex.h"

using namespace graph::models;
using namespace graph::iterators;
using namespace graph::containers;

class MaximalFlow
{
public:
    MaximalFlow(Graph* graph);

    void solve(const Vertex& sink, const Vertex& source);

    int getMaximalFlow() const;
    QVector<QPair<EdgeContainer, int>> getPaths() const;
    QVector<QPair<Edge, int>> getMaximalFlowPerEdges() const;


private:

    using Path = QPair<EdgeContainer, int>;

    Path findPath(Graph*, const Vertex&, const Vertex&);
    void recalculateNet(Path, Graph*);
    void calculateMaximalFlowPerEdge(Graph* newg, Graph* oldg);
    EdgeContainer filterEdges(const EdgeContainer&, const QVector<Vertex>&);

    Graph* sourceGraph;
    Graph* newGraph;
    Vertex source;
    Vertex sink;

    QVector<Path> paths;
    QVector<QPair<Edge, int>> maximalFlowPerEdge;
    int maximalFlow{0};
};

