
#include "ConstEdgeIterator.h"

namespace graph {
namespace iterators {

ConstEdgeIterator::ConstEdgeIterator(const models::Graph* graph_, models::Vertex vertexId_, bool isEnded):
    graph(graph_), vertexId(vertexId_), ended(isEnded) {
    ended = (edgeNumber >= graph->cont[vertexId.id()].size());
}

auto ConstEdgeIterator::operator++() -> self_type {
    incrementIterator();
    return *this;
}

auto ConstEdgeIterator::operator++(int) -> self_type {
    self_type temp = *this;
    incrementIterator();
    return temp;
}

auto ConstEdgeIterator::operator--() -> self_type {
    decrementIterator();
    return *this;
}

auto ConstEdgeIterator::operator--(int) -> self_type {
    self_type temp = *this;
    decrementIterator();
    return temp;
}

auto ConstEdgeIterator::operator*() -> const value_type& {
    if (ended) {
        pointer ptr{nullptr};
        return *ptr;
    }
    return graph->cont[vertexId.id()][edgeNumber];
}

auto ConstEdgeIterator::operator->() -> pointer {
    if (ended) {
        pointer ptr{nullptr};
        return &*ptr;
    }
    return &graph->cont[vertexId.id()][edgeNumber];
}

void ConstEdgeIterator::incrementIterator() {
    ++edgeNumber;
    ended = edgeNumber >= graph->cont[vertexId.id()].size();
}

void ConstEdgeIterator::decrementIterator() {
    --edgeNumber;
    ended = edgeNumber < 0;
}

} //iterators
} //graph












