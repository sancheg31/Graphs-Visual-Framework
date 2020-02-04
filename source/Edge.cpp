#include "Edge.h"

#include <QPair>

Edge::Edge(): left_(), right_(), value_(0), orientation_(Orientation::None) { }

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

const Vertex& Edge::left() const {
    return left_;
}

const Vertex& Edge::right() const {
    return right_;
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

void Edge::setValue(int val) {
    value_ = val;
}

bool operator==(const Edge& ob1, const Edge& ob2) {
    return (ob1.left_ == ob2.left_) && (ob1.right_ == ob2.right_) &&
            (ob1.value_ == ob2.value_) && (ob1.orientation_ == ob2.orientation_);
}

bool operator!=(const Edge& ob1, const Edge& ob2) {
    return !(ob1 == ob2);
}
