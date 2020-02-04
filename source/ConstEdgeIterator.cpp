
#include "ConstEdgeIterator.h"

Graph::ConstEdgeIterator::ConstEdgeIterator(const Graph* graph_, Vertex vertexId_, bool isEnded):
    graph(graph_), vertexId(vertexId_), ended(isEnded) {
    ended = (edgeNumber >= graph->cont[vertexId.id()].size());
}

auto Graph::ConstEdgeIterator::operator++() -> self_type {
    incrementIterator();
    return *this;
}

auto Graph::ConstEdgeIterator::operator++(int) -> self_type {
    self_type temp = *this;
    incrementIterator();
    return temp;
}

auto Graph::ConstEdgeIterator::operator--() -> self_type {
    decrementIterator();
    return *this;
}

auto Graph::ConstEdgeIterator::operator--(int) -> self_type {
    self_type temp = *this;
    decrementIterator();
    return temp;
}

auto Graph::ConstEdgeIterator::operator*() -> const value_type& {
    if (ended) {
        pointer ptr{nullptr};
        return *ptr;
    }
    return graph->cont[vertexId.id()][edgeNumber];
}

auto Graph::ConstEdgeIterator::operator->() -> pointer {
    if (ended) {
        pointer ptr{nullptr};
        return &*ptr;
    }
    return &graph->cont[vertexId.id()][edgeNumber];
}

void Graph::ConstEdgeIterator::incrementIterator() {
    ++edgeNumber;
    ended = edgeNumber >= graph->cont[vertexId.id()].size();
}

void Graph::ConstEdgeIterator::decrementIterator() {
    --edgeNumber;
    ended = edgeNumber < 0;
}










