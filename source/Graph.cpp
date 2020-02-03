#include "Graph.h"

#include <algorithm>
#include <iterator>

#include "VertexIterator.h"
#include "EdgeIterator.h"





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

void Graph::setEdge(const Edge& edge) {
    auto vertices = edge.adjacentVertices();
    cont[vertices.first.id()].second.push_back(edge);
    if (!edge.isOriented())
        cont[vertices.second.id()].second.push_back(edge);
}

auto Graph::begin() -> VertexIterator {
    return VertexIterator{this, false};
}

auto Graph::begin() const -> VertexIterator {
    return VertexIterator{const_cast<Graph*>(this), false};
}

auto Graph::end() -> VertexIterator {
    return VertexIterator{this, true};
}

auto Graph::end() const -> VertexIterator {
    return VertexIterator{const_cast<Graph*>(this), true};
}

Graph::EdgeIterator Graph::begin(const Vertex& ob) {
    return EdgeIterator{this, ob.id(), false};
}

Graph::EdgeIterator Graph::begin(const Vertex& ob) const {
    return EdgeIterator{const_cast<Graph*>(this), ob.id(), false};
}

Graph::EdgeIterator Graph::end(const Vertex& ob) {
    return EdgeIterator{const_cast<Graph*>(this), ob.id(), true};
}

Graph::EdgeIterator Graph::end(const Vertex& ob) const {
    return EdgeIterator{const_cast<Graph*>(this), ob.id(), true};
}
