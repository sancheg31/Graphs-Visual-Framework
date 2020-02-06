#include "GraphFactory.h"

namespace graph {
namespace models {

GraphFactory* GraphFactory::instance() {
    static GraphFactory* instance_;
    if (instance_ == nullptr)
        instance_ = new GraphFactory();
    return instance_;
}

models::Vertex* GraphFactory::createVertex() const {
    return new Vertex();
}

models::Edge* GraphFactory::createEdge() const {
    return new Edge();
}

models::Graph* GraphFactory::createGraph() const {
    return new Graph();
}

GraphFactory::GraphFactory() { }

} // models
} //graph


