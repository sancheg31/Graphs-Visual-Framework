#include "ConstVertexIterator.h"



Graph::ConstVertexIterator::ConstVertexIterator(const Graph* graph_, bool isEnded):
    graph(graph_), vertices(graph->vertices()), vertexId(vertices.begin()), ended(isEnded) { }

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
    return &graph->cont[vertexId->id()][edgeNumber];
}

auto Graph::ConstVertexIterator::operator*() -> const value_type& {
    if (ended) {
        pointer ptr{nullptr};
        return *ptr;
    }
    return graph->cont[vertexId->id()][edgeNumber];
}

void Graph::ConstVertexIterator::incrementIterator() {
    ++edgeNumber;
    while (vertexId != vertices.end() && edgeNumber >= graph->cont[vertexId->id()].size()) {
        ++vertexId;
        edgeNumber = 0;
    }
    ended = vertexId == vertices.end();
}

void Graph::ConstVertexIterator::decrementIterator() {
    --edgeNumber;
    while (vertexId != vertices.begin()-1 && edgeNumber < 0 && edgeNumber >= graph->cont[vertexId->id()].size()) {
        --vertexId;
        edgeNumber = 0;
    }
    ended = vertexId == vertices.begin()-1;
}
