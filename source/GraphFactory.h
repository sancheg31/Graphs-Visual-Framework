#pragma once

#include "Edge.h"
#include "Vertex.h"

#include "Graph.h"

class GraphFactory
{
public:
    GraphFactory(const GraphFactory&) = delete;
    GraphFactory(GraphFactory&&) = delete;
    GraphFactory* instance();

    Vertex* createVertex() const;
    Edge* createEdge() const;
    Graph* createGraph() const;

protected:
    GraphFactory();
};

