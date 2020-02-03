
#include "VertexIterator.h"

Graph::VertexIterator::VertexIterator(Graph* graph_, bool isEnded):
    graph(graph_), ended(isEnded) { }

auto Graph::VertexIterator::operator++() -> self_type {
    incrementIterator();
    return *this;
}

auto  Graph::VertexIterator::operator++(int) -> self_type {
    self_type temp = *this;
    incrementIterator();
    return temp;
}

auto Graph::VertexIterator::operator--() -> self_type {
    decrementIterator();
    return *this;
}

auto Graph::VertexIterator::operator--(int) -> self_type {
    self_type temp = *this;
    decrementIterator();
    return temp;
}

auto Graph::VertexIterator::operator*() -> value_type& {
    if (ended) {
        pointer ptr{nullptr};
        return *ptr;
    }
    return graph->cont[vertexId].second[edgeNumber];
}

auto Graph::VertexIterator::operator->() -> pointer {
    if (ended) {
        pointer ptr{nullptr};
        *ptr = *ptr;
        return ptr;
    }
    return &graph->cont[vertexId].second[edgeNumber];
}

void Graph::VertexIterator::incrementIterator() {
    ++edgeNumber;
    while (vertexId < graph->cont.size() && edgeNumber >= graph->cont[vertexId].second.size()) {
        ++vertexId;
        edgeNumber = 0;
    }
    ended = vertexId >= graph->cont.size();
}

void Graph::VertexIterator::decrementIterator() {
    --edgeNumber;
    while (vertexId >=0 && edgeNumber < 0 && edgeNumber >= graph->cont[vertexId].second.size()) {
        --vertexId;
        edgeNumber = 0;
    }
    ended = vertexId < 0;
}


