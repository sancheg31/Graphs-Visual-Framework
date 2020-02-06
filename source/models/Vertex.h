#pragma once

#include <QObject>
#include <QString>

namespace graph {
namespace models {

class Vertex
{
public:
    Vertex(QString id = "", int value = 0);
    Vertex(const Vertex&);
    Vertex& operator=(const Vertex&);

    int value() const;
    QString id() const;

    void setValue(int);

    friend bool operator==(const Vertex&, const Vertex&);
    friend bool operator!=(const Vertex&, const Vertex&);

protected:
    QString id_;
    int value_;
};

} //models
} //graph



