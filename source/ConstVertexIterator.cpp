#include "ConstVertexIterator.h"



Graph::ConstVertexIterator::ConstVertexIterator(const Graph* graph_, bool isEnded): graph(graph_), ended(isEnded) { }

auto Graph::ConstVertexIterator::operator++() -> self_type {
    incrementIterator();
    return *this;
}

auto Graph::ConstVertexIterator::operator++(int) -> self_type {
    self_type temp = *this;
    incrementIterator();
    return temp;
}

auto Graph::ConstVertexIterator::operator--() -> self_type {
    decrementIterator();
    return *this;
}

auto Graph::ConstVertexIterator::operator--(int) -> self_type {
    self_type temp = *this;
    decrementIterator();
    return temp;
}

auto Graph::ConstVertexIterator::operator->() -> pointer {
    if (ended) {
        pointer ptr{nullptr};
        return &*ptr;
    }
    return &graph->cont[vertexId].second[edgeNumber];
}

auto Graph::ConstVertexIterator::operator*() -> const value_type& {
    if (ended) {
        pointer ptr{nullptr};
        return *ptr;
    }
    return graph->cont[vertexId].second[edgeNumber];
}

void Graph::ConstVertexIterator::incrementIterator() {
    ++edgeNumber;
    while (vertexId < graph->cont.size() && edgeNumber >= graph->cont[vertexId].second.size()) {
        ++vertexId;
        edgeNumber = 0;
    }
    ended = vertexId >= graph->cont.size();
}

void Graph::ConstVertexIterator::decrementIterator() {
    --edgeNumber;
    while (vertexId >=0 && edgeNumber < 0 && edgeNumber >= graph->cont[vertexId].second.size()) {
        --vertexId;
        edgeNumber = 0;
    }
    ended = vertexId < 0;
}
