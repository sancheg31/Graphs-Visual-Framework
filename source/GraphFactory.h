#pragma once

#include "Edge.h"
#include "Vertex.h"

#include "Graph.h"

class GraphFactory
{
public:
    GraphFactory(const GraphFactory&) = delete;
    GraphFactory(GraphFactory&&) = delete;

    static GraphFactory* instance();

    Vertex* createVertex() const;
    Edge* createEdge() const;
    Graph* createGraph() const;

protected:
    GraphFactory();
};

