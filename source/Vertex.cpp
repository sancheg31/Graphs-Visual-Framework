#include "Vertex.h"

Vertex::Vertex(QString id, int value): id_(id), value_(value) { }

Vertex::Vertex(const Vertex& ob): id_(ob.id_), value_(ob.value_) { }

Vertex& Vertex::operator=(const Vertex& ob) {
    id_ = ob.id_;
    value_ = ob.value_;
    return *this;
}

int Vertex::value() const {
    return value_;
}

void Vertex::setValue(int val) {
    value_ = val;
}

QString Vertex::id() const {
    return id_;
}

bool operator==(const Vertex& ob1, const Vertex& ob2) {
    return (ob1.value() == ob2.value()) && (ob1.id() == ob2.id());
}

bool operator!=(const Vertex& ob1, const Vertex& ob2) {
    return !(ob1 == ob2);
}
