#include "Edge.h"


Edge::Edge(const Vertex& l, const Vertex& r, int val, Edge::Orientation o)
    : left_(l), right_(r), value_(val), orientation_(o) { }

Edge::Edge(const Edge& ob): left_(ob.left_), right_(ob.right_), value_(ob.value_), orientation_(ob.orientation_) { }

Edge& Edge::operator=(const Edge& ob) {
    left_ = ob.left_;
    right_ = ob.right_;
    value_ = ob.value_;
    orientation_ = ob.orientation_;
    return *this;
}

QPair<Vertex, Vertex> Edge::adjacentVertices() const {
    return QPair{left_, right_};
}

int Edge::value() const {
    return value_;
}

bool Edge::isOriented() const {
    return orientation_ != Orientation::None;
}

Edge::Orientation Edge::orientation() const {
    return orientation_;
}

bool operator==(const Edge& ob1, const Edge& ob2) {
    return (ob1.left_ == ob2.left_) && (ob1.right_ == ob2.right_) &&
            (ob1.value() == ob2.value()) && (ob1.orientation_ == ob2.orientation_);
}

bool operator!=(const Edge& ob1, const Edge& ob2) {
    return !(ob1 == ob2);
}
