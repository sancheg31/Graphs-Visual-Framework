#pragma once

#include "Edge.h"
#include "Vertex.h"

class GraphFactory
{
public:
    GraphFactory(const GraphFactory&) = delete;
    GraphFactory(GraphFactory&&) = delete;
    GraphFactory* instance();

    Vertex* createVertex() const;
    Edge* createEdge() const;

protected:
    GraphFactory();
};

