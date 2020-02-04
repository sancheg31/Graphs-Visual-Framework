#include "Graph.h"

#include <algorithm>
#include <iterator>

#include "VertexIterator.h"
#include "EdgeIterator.h"

#include "ConstVertexIterator.h"
#include "ConstEdgeIterator.h"


Graph::Graph() { }

Graph::Graph(const Graph& ob): cont(ob.cont) {
}

Graph& Graph::operator=(const Graph& ob) {
    cont = ob.cont;
    return *this;
}

EdgeContainer Graph::edges(const Vertex& ob) const {
    return cont[ob.id()];
}

VertexContainer Graph::vertices() const {
    VertexContainer result;
    for (const auto & x: cont.keys())
        result.insert(x);
    return result;
}

const Edge& Graph::edge(const Vertex& ob1, const Vertex& ob2) const {
    const auto& tempCont = cont[ob1.id()];
    auto it = std::find_if(tempCont.begin(), tempCont.end(), [ob2](const Edge& edge) {
        return edge.adjacentVertices().second == ob2;
    });
    return *it;
}

void Graph::addEdge(const Edge& edge) {
    auto vertices = edge.adjacentVertices();
    cont[vertices.first.id()].push_back(edge);
    if (!edge.isOriented())
        cont[vertices.second.id()].push_back(edge);
}

void Graph::removeEdge(const Edge& edge) {
    auto vertices = edge.adjacentVertices();
    auto & tempCont = cont[vertices.first.id()];
    std::remove(tempCont.begin(), tempCont.end(), edge);
    if (!edge.isOriented()) {
        auto & tempCont = cont[vertices.second.id()];
        std::remove(tempCont.begin(), tempCont.end(), edge);
    }
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
    return EdgeIterator{this, ob, false};
}

auto Graph::begin(const Vertex& ob) const -> ConstEdgeIterator {
    return ConstEdgeIterator{this, ob, false};
}

Graph::EdgeIterator Graph::end(const Vertex& ob) {
    return EdgeIterator{this, ob, true};
}

auto Graph::end(const Vertex& ob) const -> ConstEdgeIterator {
    return ConstEdgeIterator{this, ob, true};
}
