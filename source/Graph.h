#pragma once

#include <QVector>

#include "Edge.h"
#include "Vertex.h"

#include "VertexContainer.h"
#include "EdgeContainer.h"

namespace graph::iterators {
    class VertexIterator;
    class ConstVertexIterator;
    class EdgeIterator;
    class ConstEdgeIterator;
}

namespace graph {
namespace models {

class Graph
{
protected:

    friend iterators::VertexIterator;
    friend iterators::ConstVertexIterator;
    friend iterators::EdgeIterator;
    friend iterators::ConstEdgeIterator;

    using edge_container_type = QHash<QString, EdgeContainer>;
    using vertex_container_type = QHash<QString, Vertex>;

public:

    using vertex_iterator = iterators::VertexIterator;
    using const_vertex_iterator = const iterators::VertexIterator;
    using edge_iterator = iterators::EdgeIterator;
    using const_edge_iterator = iterators::ConstEdgeIterator;

    Graph();
    Graph(const Graph&);
    Graph& operator=(const Graph&);

    EdgeContainer edges(const Vertex&) const;
    VertexContainer vertices() const;
    const Edge& edge(const Vertex&, const Vertex&) const;


    void addVertex(const Vertex&);
    void removeVertex(const Vertex&);

    void addEdge(const Edge&);
    void removeEdge(const Edge&);

    vertex_iterator begin();
    const_vertex_iterator begin() const;

    vertex_iterator end();
    const_vertex_iterator end() const;

    edge_iterator begin(const Vertex&);
    const_edge_iterator begin(const Vertex&) const;

    edge_iterator end(const Vertex&);
    const_edge_iterator end(const Vertex&) const;

private:
    edge_container_type cont;
    vertex_container_type vert;
};

} //models
} //graph


