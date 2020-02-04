#include "Graph.h"

#include <algorithm>
#include <iterator>

#include <QDebug>

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
    for (const auto & x: vert.values())
        result.insert(x);
    return result;
}

const Edge& Graph::edge(const Vertex& ob1, const Vertex& ob2) const {
    const auto& tempCont = cont[ob1.id()];
    auto it = std::find_if(tempCont.begin(), tempCont.end(), [ob2](const Edge& edge) {
        return edge.right().id() == ob2;
    });
    return *it;
}

void Graph::addVertex(const Vertex& v) {
    vert.insert(v.id(), v);
}

void Graph::removeVertex(const Vertex& v) {
    vert.remove(v.id());
}

void Graph::addEdge(const Edge& edge) {
    //qDebug() << "addEdge::size before: " << cont[edge.left().id()].size();
    cont[edge.left().id()].push_back(edge);
    if (!edge.isOriented()) {
        cont[edge.right().id()].push_back(edge);
    }
    //qDebug() << "edge added: " << edge.left().id() << " " << edge.right().id() << " " << edge.value();
    //qDebug() << "addEdge::size after: " << cont[edge.left().id()].size();
}

void Graph::removeEdge(const Edge& edge) {
    //qDebug() << "removeEdge::size before: " << cont[edge.left().id()].size();
    auto it = std::find(cont[edge.left().id()].begin(), cont[edge.left().id()].end(), edge);
    cont[edge.left().id()].remove(it);
    if (!edge.isOriented()) {
        std::remove(cont[edge.left().id()].begin(), cont[edge.left().id()].end(), edge);
    }
    //qDebug() << "edge removed: " << edge.left().id() << " " << edge.right().id() << " " << edge.value();
    //qDebug() << "removeEdge::size after: " << cont[edge.left().id()].size();
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
