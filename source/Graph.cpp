#include "Graph.h"

#include <algorithm>
#include <iterator>



class Graph::VertexIterator
{
public:
    using self_type = Graph::VertexIterator;
    using value_type = Edge;
    using reference = Edge&;
    using pointer = Edge*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference = int;

    VertexIterator(Graph* graph_, bool isEnded = false): graph(graph_), ended(isEnded) { }
    self_type operator++() {
        incrementIterator();
        return *this;
    }
    self_type operator++(int) {
        self_type temp = *this;
        incrementIterator();
        return temp;
    }
    value_type& operator*() {
        if (ended) {
            pointer ptr{nullptr};
            return *ptr;
        }
        return graph->cont[vertexId].second[edgeNumber];
    }
    pointer operator->() {
        if (ended) {
            pointer ptr{nullptr};
            *ptr = *ptr;
            return ptr;
        }
        return &graph->cont[vertexId].second[edgeNumber];
    }

    friend bool operator==(const self_type& ob1, const self_type& ob2) {
        return (ob1.ended == ob2.ended) || (ob1.graph == ob2.graph && ob1.vertexId == ob2.vertexId &&
                                            ob2.edgeNumber == ob2.edgeNumber);
    }

    friend bool operator!=(const self_type& ob1, const self_type& ob2) {
        return !(ob1 == ob2);
    }

private:
    void incrementIterator() {
        ++edgeNumber;
        while (vertexId < graph->cont.size() && edgeNumber >= graph->cont[vertexId].second.size()) {
            ++vertexId;
            edgeNumber = 0;
        }
        ended = vertexId >= graph->cont.size();
    }
    Graph* graph;
    int vertexId{0};
    int edgeNumber{0};
    bool ended{false};
};


class Graph::EdgeIterator
{
public:
    using self_type = Graph::EdgeIterator;
    using value_type = Edge;
    using reference = Edge&;
    using pointer = Edge*;
    using iterator_category = std::bidirectional_iterator_tag;
    using difference = int;

    EdgeIterator(Graph* graph_, int vertexId_, bool isEnded = false): graph(graph_), vertexId(vertexId_), ended(isEnded) { }
    self_type operator++() {
        incrementIterator();
        return *this;
    }
    self_type operator++(int) {
        self_type temp = *this;
        incrementIterator();
        return temp;
    }
    value_type& operator*() {
        if (ended) {
            pointer ptr{nullptr};
            return *ptr;
        }
        return graph->cont[vertexId].second[edgeNumber];
    }
    pointer operator->() {
        if (ended) {
            pointer ptr{nullptr};
            *ptr = *ptr;
            return ptr;
        }
        return &graph->cont[vertexId].second[edgeNumber];
    }

    friend bool operator==(const self_type& ob1, const self_type& ob2) {
        return (ob1.ended == ob2.ended) || (ob1.graph == ob2.graph && ob1.vertexId == ob2.vertexId &&
                                            ob1.edgeNumber == ob2.edgeNumber);
    }

    friend bool operator!=(const self_type& ob1, const self_type& ob2) {
        return !(ob1 == ob2);
    }

private:
    void incrementIterator() {
        ++edgeNumber;
        ended = edgeNumber >= graph->cont[vertexId].second.size();
    }
    Graph* graph;
    const int vertexId;
    int edgeNumber{0};
    bool ended{false};

};

Graph::Graph() { }

Graph::Graph(const Graph& ob): cont(ob.cont) { }

Graph& Graph::operator=(const Graph& ob) {
    cont = ob.cont;
    return *this;
}

EdgeContainer Graph::edges(const Vertex& ob) const {
    return cont[ob.id()].second;
}

const Edge& Graph::edge(const Vertex& ob1, const Vertex& ob2) const {
    const auto& tempCont = cont[ob1.id()].second;
    auto it = std::find_if(tempCont.begin(), tempCont.end(), [ob2](const Edge& edge) {
        return edge.adjacentVertices().second == ob2;
    });
    return *it;
}

Edge& Graph::edge(const Vertex& ob1, const Vertex& ob2) {
    const auto& tempCont = cont[ob1.id()].second;
    auto it = std::find_if(tempCont.begin(), tempCont.end(), [ob2](const Edge& edge) {
        return edge.adjacentVertices().second == ob2;
    });
}

void Graph::setEdge(const Edge& edge) {
    auto vertices = edge.adjacentVertices();
    cont[vertices.first.id()].second.push_back(edge);
    if (!edge.isOriented())
        cont[vertices.second.id()].second.push_back(edge);
}

Graph::VertexIterator Graph::begin() {
    return VertexIterator{this, false};
}

Graph::VertexIterator Graph::begin() const {
    return VertexIterator{const_cast<Graph*>(this), false};
}

Graph::VertexIterator Graph::end() {
    return VertexIterator{this, true};
}

Graph::VertexIterator Graph::end() const {
    return VertexIterator{const_cast<Graph*>(this), true};
}

Graph::EdgeIterator Graph::begin(const Vertex& ob) {
    return EdgeIterator{this, ob.id(), false};
}

Graph::EdgeIterator Graph::begin(const Vertex& ob) const {
    return EdgeIterator{const_cast<Graph*>(this), ob.id(), false};
}

Graph::EdgeIterator Graph::end(const Vertex& ob) {
    return EdgeIterator{const_cast<Graph*>(this), ob.id(), true};
}

Graph::EdgeIterator Graph::end(const Vertex& ob) const {
    return EdgeIterator{const_cast<Graph*>(this), ob.id(), true};
}
