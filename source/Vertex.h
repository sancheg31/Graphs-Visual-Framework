#pragma once

#include <QObject>

class Vertex: public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(int id READ id CONSTANT)
public:
    Vertex(int id, int value);

    int value() const;
    int id() const;

    friend bool operator==(const Vertex&, const Vertex&);
    friend bool operator!=(const Vertex&, const Vertex&);

protected:
    int id_;
    int value_;
};

