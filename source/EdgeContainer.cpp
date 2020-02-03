#include "EdgeContainer.h"



EdgeContainer::EdgeContainer(int size): cont(size) { }

EdgeContainer::EdgeContainer(const EdgeContainer& ob): cont(ob.cont) { }

EdgeContainer& EdgeContainer::operator=(const EdgeContainer& ob) {
    cont = ob.cont;
    return *this;
}

void EdgeContainer::insert( int i, const value_type& ob) {
    cont.insert(i, ob);
}

void EdgeContainer::remove(int i) {
    cont.removeAt(i);
}

int EdgeContainer::size() const {
    return cont.size();
}

bool EdgeContainer::isEmpty() const {
    return cont.isEmpty();
}

EdgeContainer::value_type& EdgeContainer::operator[](int i) {
    return cont[i];
}

const EdgeContainer::value_type& EdgeContainer::operator[](int i) const {
    return cont[i];
}

EdgeContainer::iterator EdgeContainer::begin() {
    return cont.begin();
}

EdgeContainer::const_iterator EdgeContainer::begin() const {
    return cont.begin();
}

EdgeContainer::const_iterator EdgeContainer::cbegin() const {
    return cont.cbegin();
}

EdgeContainer::iterator EdgeContainer::end() {
    return cont.end();
}

EdgeContainer::const_iterator EdgeContainer::end() const {
    return cont.end();
}

EdgeContainer::const_iterator EdgeContainer::cend() const {
    return cont.cend();
}
