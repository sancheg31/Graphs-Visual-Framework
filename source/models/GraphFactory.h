#pragma once

#include "Edge.h"
#include "Vertex.h"

#include "Graph.h"

namespace graph {
namespace models {

class GraphFactory
{
public:
    GraphFactory(const GraphFactory&) = delete;
    GraphFactory(GraphFactory&&) = delete;

    static GraphFactory* instance();

    models::Vertex* createVertex() const;
    Edge* createEdge() const;
    Graph* createGraph() const;

protected:
    GraphFactory();
};

} //models
} //graph


