#pragma once

#include <QVector>

#include "Edge.h"
#include "Vertex.h"

#include "VertexContainer.h"
#include "EdgeContainer.h"


class Graph
{
protected:

    class VertexIterator;
    class ConstVertexIterator;
    class EdgeIterator;
    class ConstEdgeIterator;

    using container_type = QVector<QPair<Vertex, EdgeContainer>>;

public:

    using vertex_iterator = VertexIterator;
    using const_vertex_iterator = const VertexIterator;
    using edge_iterator = EdgeIterator;
    using const_edge_iterator = ConstEdgeIterator;

    Graph();
    Graph(const Graph&);
    Graph& operator=(const Graph&);

    EdgeContainer edges(const Vertex&) const;
    const Edge& edge(const Vertex&, const Vertex&) const;
    Edge& edge(const Vertex&, const Vertex&);

    void addEdge(const Edge&);

    VertexIterator begin();
    ConstVertexIterator begin() const;

    VertexIterator end();
    ConstVertexIterator end() const;

    EdgeIterator begin(const Vertex&);
    ConstEdgeIterator begin(const Vertex&) const;

    EdgeIterator end(const Vertex&);
    ConstEdgeIterator end(const Vertex&) const;

private:
    container_type cont;

};

