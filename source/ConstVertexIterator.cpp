#include "ConstVertexIterator.h"


namespace graph {
namespace iterators {

ConstVertexIterator::ConstVertexIterator(const models::Graph* graph_, bool isEnded):
    graph(graph_), vertices(graph->vertices()), vertexId(vertices.begin()), ended(isEnded) {
    ended = (vertexId == vertices.end());
}

auto ConstVertexIterator::operator++() -> self_type {
    incrementIterator();
    return *this;
}

auto ConstVertexIterator::operator++(int) -> self_type {
    self_type temp = *this;
    incrementIterator();
    return temp;
}

auto ConstVertexIterator::operator--() -> self_type {
    decrementIterator();
    return *this;
}

auto ConstVertexIterator::operator--(int) -> self_type {
    self_type temp = *this;
    decrementIterator();
    return temp;
}

auto ConstVertexIterator::operator->() -> pointer {
    if (ended) {
        pointer ptr{nullptr};
        return &*ptr;
    }
    return &graph->cont[vertexId->id()][edgeNumber];
}

auto ConstVertexIterator::operator*() -> const value_type& {
    if (ended) {
        pointer ptr{nullptr};
        return *ptr;
    }
    return graph->cont[vertexId->id()][edgeNumber];
}

void ConstVertexIterator::incrementIterator() {
    ++edgeNumber;
    while (vertexId != vertices.end() && edgeNumber >= graph->cont[vertexId->id()].size()) {
        ++vertexId;
        edgeNumber = 0;
    }
    ended = vertexId == vertices.end();
}

void ConstVertexIterator::decrementIterator() {
    --edgeNumber;
    while (vertexId != vertices.begin()-1 && edgeNumber < 0 && edgeNumber >= graph->cont[vertexId->id()].size()) {
        --vertexId;
        edgeNumber = 0;
    }
    ended = vertexId == vertices.begin()-1;
}

} //iterators
} //graph


