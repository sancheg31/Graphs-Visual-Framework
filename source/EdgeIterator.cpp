#include "EdgeIterator.h"

Graph::EdgeIterator::EdgeIterator(Graph* graph_, Vertex vertexId_, bool isEnded):
    graph(graph_), vertexId(vertexId_), ended(isEnded) {
    ended = (edgeNumber >= graph->cont[vertexId.id()].size());
}

auto Graph::EdgeIterator::operator++() -> self_type {
    incrementIterator();
    return *this;
}

auto Graph::EdgeIterator::operator++(int) -> self_type {
    self_type temp = *this;
    incrementIterator();
    return temp;
}

auto Graph::EdgeIterator::operator--() -> self_type {
    decrementIterator();
    return *this;
}

auto Graph::EdgeIterator::operator--(int) -> self_type {
    self_type temp = *this;
    decrementIterator();
    return temp;
}

auto Graph::EdgeIterator::operator*() -> value_type& {
    if (ended) {
        pointer ptr{nullptr};
        return *ptr;
    }
    return graph->cont[vertexId.id()][edgeNumber];
}
auto Graph::EdgeIterator::operator->() -> pointer {
    if (ended) {
        pointer ptr{nullptr};
        *ptr = *ptr;
        return ptr;
    }
    return &graph->cont[vertexId.id()][edgeNumber];
}

void Graph::EdgeIterator::incrementIterator() {
    ++edgeNumber;
    ended = edgeNumber >= graph->cont[vertexId.id()].size();
}

void Graph::EdgeIterator::decrementIterator() {
    --edgeNumber;
    ended = edgeNumber < 0;
}

