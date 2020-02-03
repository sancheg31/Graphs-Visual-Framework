#include "GraphFactory.h"


GraphFactory* GraphFactory::instance() {
    static GraphFactory* instance_;
    if (instance_ == nullptr)
        instance_ = new GraphFactory();
    return instance_;
}

Vertex* GraphFactory::createVertex() const {
    return new Vertex();
}

Edge* GraphFactory::createEdge() const {
    return new Edge();
}

Graph* GraphFactory::createGraph() const {
    return new Graph();
}

GraphFactory::GraphFactory() { }
