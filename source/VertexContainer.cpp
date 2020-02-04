#include "VertexContainer.h"



VertexContainer::VertexContainer() { }

VertexContainer::VertexContainer(const VertexContainer& ob): cont(ob.cont) { }

VertexContainer& VertexContainer::operator=(const VertexContainer& ob) {
    cont = ob.cont;
    return *this;
}

void VertexContainer::insert(const value_type& ob) {
    if (!cont.contains(ob.id()))
        cont.insert(ob.id(), ob);
}

void VertexContainer::remove(const QString& key) {
    cont.remove(key);
}

void VertexContainer::clear() {
    cont.clear();
}

int VertexContainer::size() const {
    return cont.size();
}

bool VertexContainer::contains(const QString& key) const {
    return cont.contains(key);
}

bool VertexContainer::isEmpty() const {
    return cont.isEmpty();
}

VertexContainer::value_type& VertexContainer::operator[](const QString& key) {
    return cont[key];
}

VertexContainer::value_type VertexContainer::operator[](const QString& key) const {
    return cont[key];
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
