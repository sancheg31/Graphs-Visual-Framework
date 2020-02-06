
#include "VertexIterator.h"

#include <QDebug>

namespace graph {
namespace iterators {

VertexIterator::VertexIterator(models::Graph* graph_, bool isEnded):
    graph(graph_), vertices(graph->vertices()) {
    vertexId = vertices.begin();
    ended = isEnded || (vertexId == vertices.end());
}

auto VertexIterator::operator++() -> self_type {
    incrementIterator();
    return *this;
}

auto  VertexIterator::operator++(int) -> self_type {
    self_type temp = *this;
    incrementIterator();
    return temp;
}

auto VertexIterator::operator--() -> self_type {
    decrementIterator();
    return *this;
}

auto VertexIterator::operator--(int) -> self_type {
    self_type temp = *this;
    decrementIterator();
    return temp;
}

auto VertexIterator::operator*() -> value_type& {
    if (ended) {
        pointer ptr{nullptr};
        return *ptr;
    }
    return graph->cont[vertexId->id()][edgeNumber];
}

auto VertexIterator::operator->() -> pointer {
    if (ended) {
        qDebug() << "disaster";
        pointer ptr{nullptr};
        *ptr = *ptr;
        return ptr;
    }
    return &graph->cont[vertexId->id()][edgeNumber];
}

void VertexIterator::incrementIterator() {
    ++edgeNumber;
    while (vertexId != vertices.end() && edgeNumber >= graph->cont[vertexId->id()].size()) {
        ++vertexId;
        edgeNumber = 0;
    }
    ended = vertexId == vertices.end();
}

void VertexIterator::decrementIterator() {
    --edgeNumber;
    while (vertexId != vertices.begin()-1 && edgeNumber < 0 && edgeNumber >= graph->cont[vertexId->id()].size()) {
        --vertexId;
        edgeNumber = 0;
    }
    ended = vertexId == vertices.begin()-1;
}

} //iterators
} //graph




