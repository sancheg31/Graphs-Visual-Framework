#include "Graph.h"


Graph::Graph() { }

Graph::Graph(const Graph& ob): impl(ob.impl) { }

Graph& Graph::operator=(const Graph& ob) {
    impl = ob.impl;
}

EdgeContainer Graph::edges(const Vertex& ob) const {

}

const Edge& Graph::edge(const Vertex& ob1, const Vertex& ob2) const {

}

Edge& Graph::edge(const Vertex& ob1, const Vertex& ob2) {

}

Graph::VertexIterator Graph::begin() {

}

const Graph::VertexIterator Graph::begin() const {

}

Graph::VertexIterator Graph::end() {

}

const Graph::VertexIterator Graph::end() const {

}

Graph::EdgeIterator Graph::begin(const Vertex&) {

}

const Graph::EdgeIterator Graph::begin(const Vertex&) const {

}

Graph::EdgeIterator Graph::end(const Vertex&) {

}

const Graph::EdgeIterator Graph::end(const Vertex&) const {

}
