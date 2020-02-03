#pragma once

#include <QVector>

#include "Edge.h"
#include "Vertex.h"

#include "VertexContainer.h"
#include "EdgeContainer.h"

class GraphImplementation;

class Graph
{
protected:
    class VertexIterator;
    class ConstVertexIterator;
    class EdgeIterator;
    class ConstEdgeIterator;

    using container_type = QVector<QPair<Vertex, EdgeContainer>>;
public:

    using iterator = VertexIterator;
    using const_iterator = const VertexIterator;

    Graph();
    Graph(const Graph&);
    Graph& operator=(const Graph&);

    EdgeContainer edges(const Vertex&) const;
    const Edge& edge(const Vertex&, const Vertex&) const;
    Edge& edge(const Vertex&, const Vertex&);

    void setEdge(const Edge&);

    VertexIterator begin();
    VertexIterator begin() const;

    VertexIterator end();
    VertexIterator end() const;

    EdgeIterator begin(const Vertex&);
    EdgeIterator begin(const Vertex&) const;

    EdgeIterator end(const Vertex&);
    EdgeIterator end(const Vertex&) const;

private:
    QVector<QPair<Vertex, EdgeContainer>> cont;

};

