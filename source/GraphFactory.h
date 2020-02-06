#pragma once

#include "Edge.h"
#include "Vertex.h"

#include "Graph.h"

using namespace graph::models;

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

