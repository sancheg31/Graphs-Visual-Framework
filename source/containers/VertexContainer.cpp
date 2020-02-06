#include "VertexContainer.h"


namespace graph {
namespace containers {

VertexContainer::VertexContainer() { }

VertexContainer::VertexContainer(const VertexContainer& ob): cont(ob.cont) { }

VertexContainer::VertexContainer(VertexContainer&& ob): cont(std::move(ob.cont)){ }

VertexContainer& VertexContainer::operator=(const VertexContainer& ob) {
    cont = ob.cont;
    return *this;
}

VertexContainer& VertexContainer::operator=(VertexContainer&& ob) {
    cont = std::move(ob.cont);
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

auto VertexContainer::operator[](const QString& key) -> value_type&{
    return cont[key];
}

auto VertexContainer::operator[](const QString& key) const -> value_type {
    return cont[key];
}

auto VertexContainer::begin() -> iterator {
    return cont.begin();
}

auto VertexContainer::begin() const -> const_iterator {
    return cont.begin();
}

auto VertexContainer::cbegin() const -> const_iterator{
    return cont.cbegin();
}

auto VertexContainer::end() -> iterator {
    return cont.end();
}

auto VertexContainer::end() const -> const_iterator {
    return cont.end();
}

auto VertexContainer::cend() const -> const_iterator {
    return cont.cend();
}

} //containers
} //graph
