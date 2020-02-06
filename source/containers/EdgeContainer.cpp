#include "EdgeContainer.h"

namespace graph {
namespace containers {

EdgeContainer::EdgeContainer(int size): cont(size) { }

EdgeContainer::EdgeContainer(const EdgeContainer& ob): cont(ob.cont) { }

EdgeContainer& EdgeContainer::operator=(const EdgeContainer& ob) {
    cont = ob.cont;
    return *this;
}

void EdgeContainer::push_back(const value_type& ob) {
    cont.push_back(ob);
}

void EdgeContainer::insert(int i, const value_type& ob) {
    cont.insert(i, ob);
}

void EdgeContainer::remove(int i) {
    cont.remove(i);
}

void EdgeContainer::remove(iterator it) {
    cont.removeAll(*it);
}

void EdgeContainer::remove_if(std::function<bool(const value_type&)> f) {
    for (int i = 0; i < size(); ++i)
        if (f(cont[i])) {
            remove(i);
        }
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

} //containers
} //graph

