#pragma once

#include "Edge.h"
#include "Vertex.h"

#include "VertexContainer.h"
#include "EdgeContainer.h"

class GraphImplementation;

class Graph
{
protected:
    class VertexIterator;
    class EdgeIterator;

public:

    using iterator = VertexIterator;
    using const_iterator = const VertexIterator;

    Graph();
    Graph(const Graph&);
    Graph& operator=(const Graph&);

    EdgeContainer edges(const Vertex&) const;
    const Edge& edge(const Vertex&, const Vertex&) const;

    Edge& edge(const Vertex&, const Vertex&);

    VertexIterator begin();
    const VertexIterator begin() const;

    VertexIterator end();
    const VertexIterator end() const;

    EdgeIterator begin(const Vertex&);
    const EdgeIterator begin(const Vertex&) const;

    EdgeIterator end(const Vertex&);
    const EdgeIterator end(const Vertex&) const;

private:
    GraphImplementation impl;

};

