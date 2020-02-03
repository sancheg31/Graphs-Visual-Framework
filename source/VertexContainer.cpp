#include "VertexContainer.h"



VertexContainer::VertexContainer(int size): cont(size) { }

VertexContainer::VertexContainer(const VertexContainer& ob): cont(ob.cont) { }

VertexContainer& VertexContainer::operator=(const VertexContainer& ob) {
    cont = ob.cont;
    return *this;
}

void VertexContainer::insert(int i, const value_type& ob) {
    cont.insert(i, ob);
}

void VertexContainer::remove(int i) {
    cont.removeAt(i);
}

int VertexContainer::size() const {
    return cont.size();
}

bool VertexContainer::isEmpty() const {
    return cont.isEmpty();
}

VertexContainer::value_type& VertexContainer::operator[](int i) {
    return cont[i];
}

const VertexContainer::value_type& VertexContainer::operator[](int i) const {
    return cont[i];
}

VertexContainer::iterator VertexContainer::begin() {
    return cont.begin();
}

VertexContainer::const_iterator VertexContainer::begin() const {
    return cont.begin();
}

VertexContainer::const_iterator VertexContainer::cbegin() const {
    return cont.cbegin();
}

VertexContainer::iterator VertexContainer::end() {
    return cont.end();
}

VertexContainer::const_iterator VertexContainer::end() const {
    return cont.end();
}

VertexContainer::const_iterator VertexContainer::cend() const {
    return cont.cend();
}
