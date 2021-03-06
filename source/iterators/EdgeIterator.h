#pragma once

#include "models/Graph.h"
#include "models/Vertex.h"

namespace graph {
namespace iterators {

class EdgeIterator
{
public:
    using self_type = EdgeIterator;
    using value_type = models::Edge;
    using reference = models::Edge&;
    using pointer = models::Edge*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference = int;

    EdgeIterator(models::Graph* graph_, models::Vertex vertexId_, bool isEnded = false);
    self_type operator++();
    self_type operator++(int);

    self_type operator--();
    self_type operator--(int);

    value_type& operator*();
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

    models::Graph* graph{nullptr};
    models::Vertex vertexId;
    int edgeNumber{0};
    bool ended{false};

};


} // iterators
} //graph

