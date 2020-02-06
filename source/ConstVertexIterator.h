#pragma once

#include "Graph.h"
#include "Edge.h"

#include "VertexContainer.h"

namespace graph {
namespace iterators {

class ConstVertexIterator
{
public:
    using self_type = ConstVertexIterator;
    using value_type = models::Edge;
    using reference = const models::Edge&;
    using pointer = const models::Edge*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference = int;

    ConstVertexIterator(const models::Graph* graph, bool isEnded = false);

    self_type operator++();
    self_type operator++(int);

    self_type operator--();
    self_type operator--(int);

    pointer operator->();
    const value_type& operator*();

    friend bool operator==(const self_type& ob1, const self_type& ob2) {
        return (ob1.ended == ob2.ended && ((ob1.ended == true) ||
                (ob1.graph == ob2.graph && ob1.vertexId == ob2.vertexId && ob1.edgeNumber == ob2.edgeNumber)));
    }

    friend bool operator!=(const self_type& ob1, const self_type& ob2) {
        return !(ob1 == ob2);
    }

private:

    void incrementIterator();
    void decrementIterator();

    const models::Graph* graph;
    containers::VertexContainer vertices;
    containers::VertexContainer::iterator vertexId;
    int edgeNumber{0};
    bool ended;
};

} //iterators
}//graph

