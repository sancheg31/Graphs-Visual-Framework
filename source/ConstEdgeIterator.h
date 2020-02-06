#pragma once

#include <iterator>

#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"


namespace graph {
namespace iterators {

class ConstEdgeIterator
{
public:

    using self_type = ConstEdgeIterator;
    using value_type = models::Edge;
    using reference = const models::Edge&;
    using pointer = const models::Edge*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference = int;

    ConstEdgeIterator(const models::Graph*, models::Vertex vertexId, bool ended = false);

    self_type operator++();
    self_type operator++(int);

    self_type operator--();
    self_type operator--(int);

    const value_type& operator*();
    pointer operator->();

    friend bool operator==(const self_type& ob1, const self_type& ob2) {
        bool isEqual = true;
        isEqual &= (ob1.ended == ob2.ended);
        isEqual &= (ob1.ended == true) || (ob1.graph == ob2.graph && ob1.vertexId == ob2.vertexId &&
                                           ob1.edgeNumber == ob2.edgeNumber);
        return isEqual;
    }

    friend bool operator!=(const self_type& ob1, const self_type& ob2) {
        return !(ob1 == ob2);
    }

private:

    void incrementIterator();
    void decrementIterator();

    const models::Graph* graph;
    models::Vertex vertexId;
    int edgeNumber{0};
    bool ended{false};
};

} // iterators
} //graph



