#include "EdgeIterator.h"

namespace graph {
namespace iterators {

EdgeIterator::EdgeIterator(models::Graph* graph_, models::Vertex vertexId_, bool isEnded):
    graph(graph_), vertexId(vertexId_), ended(isEnded) {
    ended = (edgeNumber >= graph->cont[vertexId.id()].size());
}

auto EdgeIterator::operator++() -> self_type {
    incrementIterator();
    return *this;
}

auto EdgeIterator::operator++(int) -> self_type {
    self_type temp = *this;
    incrementIterator();
    return temp;
}

auto EdgeIterator::operator--() -> self_type {
    decrementIterator();
    return *this;
}

auto EdgeIterator::operator--(int) -> self_type {
    self_type temp = *this;
    decrementIterator();
    return temp;
}

auto EdgeIterator::operator*() -> value_type& {
    if (ended) {
        pointer ptr{nullptr};
        return *ptr;
    }
    return graph->cont[vertexId.id()][edgeNumber];
}
auto EdgeIterator::operator->() -> pointer {
    if (ended) {
        pointer ptr{nullptr};
        *ptr = *ptr;
        return ptr;
    }
    return &graph->cont[vertexId.id()][edgeNumber];
}

void EdgeIterator::incrementIterator() {
    ++edgeNumber;
    ended = edgeNumber >= graph->cont[vertexId.id()].size();
}

void EdgeIterator::decrementIterator() {
    --edgeNumber;
    ended = edgeNumber < 0;
}



} //iterators
} //graph

