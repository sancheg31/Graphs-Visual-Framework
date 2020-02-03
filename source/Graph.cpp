#include "Graph.h"

#include <algorithm>
#include <iterator>

#include "VertexIterator.h"
#include "EdgeIterator.h"

#include "ConstVertexIterator.h"
#include "ConstEdgeIterator.h"


Graph::Graph() { }

Graph::Graph(const Graph& ob): cont(ob.cont) { }

Graph& Graph::operator=(const Graph& ob) {
    cont = ob.cont;
    return *this;
}

EdgeContainer Graph::edges(const Vertex& ob) const {
    return cont[ob.id()].second;
}

const Edge& Graph::edge(const Vertex& ob1, const Vertex& ob2) const {
    const auto& tempCont = cont[ob1.id()].second;
    auto it = std::find_if(tempCont.begin(), tempCont.end(), [ob2](const Edge& edge) {
        return edge.adjacentVertices().second == ob2;
    });
    return *it;
}

Edge& Graph::edge(const Vertex& ob1, const Vertex& ob2) {
    const auto& tempCont = cont[ob1.id()].second;
    auto it = std::find_if(tempCont.begin(), tempCont.end(), [ob2](const Edge& edge) {
        return edge.adjacentVertices().second == ob2;
    });
}

void Graph::addEdge(const Edge& edge) {
    auto vertices = edge.adjacentVertices();
    cont[vertices.first.id()].second.push_back(edge);
    if (!edge.isOriented())
        cont[vertices.second.id()].second.push_back(edge);
}

auto Graph::begin() -> VertexIterator {
    return VertexIterator{this, false};
}

auto Graph::begin() const -> ConstVertexIterator {
    return ConstVertexIterator{this, false};
}

auto Graph::end() -> VertexIterator {
    return VertexIterator{this, true};
}

auto Graph::end() const -> ConstVertexIterator {
    return ConstVertexIterator{this, true};
}

auto Graph::begin(const Vertex& ob) -> EdgeIterator {
    return EdgeIterator{this, ob.id(), false};
}

auto Graph::begin(const Vertex& ob) const -> ConstEdgeIterator {
    return ConstEdgeIterator{this, ob.id(), false};
}

Graph::EdgeIterator Graph::end(const Vertex& ob) {
    return EdgeIterator{this, ob.id(), true};
}

auto Graph::end(const Vertex& ob) const -> ConstEdgeIterator {
    return ConstEdgeIterator{this, ob.id(), true};
}
