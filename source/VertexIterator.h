#pragma once

#include "Graph.h"

class Graph::VertexIterator
{
public:
    using self_type = Graph::VertexIterator;
    using value_type = Edge;
    using reference = Edge&;
    using pointer = Edge*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference = int;

    VertexIterator(Graph* graph_, bool isEnded = false);
    self_type operator++();
    self_type operator++(int);

    self_type operator--();
    self_type operator--(int);

    value_type& operator*();
    pointer operator->();

    friend bool operator==(const self_type& ob1, const self_type& ob2) {
        return (ob1.ended == ob2.ended && ((ob1.ended == true) || (ob1.graph == ob2.graph && ob1.vertexId == ob2.vertexId &&
                                            ob1.edgeNumber == ob2.edgeNumber)));
    }

    friend bool operator!=(const self_type& ob1, const self_type& ob2) {
        return !(ob1 == ob2);
    }

private:
    void incrementIterator();
    void decrementIterator();

    Graph* graph{nullptr};
    VertexContainer vertices;
    VertexContainer::iterator vertexId;
    int edgeNumber{0};
    bool ended{false};
};
