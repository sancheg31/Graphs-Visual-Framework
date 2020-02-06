#pragma once

#include <QVector>

#include "Graph.h"
#include "EdgeContainer.h"
#include "Edge.h"
#include "Vertex.h"

namespace graph {
namespace algorithms {

class MaximalFlow
{
public:
    MaximalFlow(models::Graph* graph);

    void solve(const models::Vertex& sink, const models::Vertex& source);

    int getMaximalFlow() const;
    QVector<QPair<containers::EdgeContainer, int>> getPaths() const;
    QVector<QPair<models::Edge, int>> getMaximalFlowPerEdges() const;

private:

    using Path = QPair<containers::EdgeContainer, int>;

    Path findPath(const models::Graph*, const models::Vertex&, const models::Vertex&);
    void recalculateNet(Path, models::Graph*);
    void calculateMaximalFlowPerEdge(const models::Graph* newg, const models::Graph* oldg);
    containers::EdgeContainer filterEdges(const containers::EdgeContainer&, const QVector<models::Vertex>&);

    models::Graph* sourceGraph;
    models::Graph* newGraph;
    models::Vertex source;
    models::Vertex sink;

    QVector<Path> paths;
    QVector<QPair<models::Edge, int>> maximalFlowPerEdge;
    int maximalFlow{0};
};

} //algorithms
} //graph



