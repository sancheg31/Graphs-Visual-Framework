
include(qmake-target-platform.pri)
include(qmake-destination-path.pri)

DESTDIR = $${PWD}/binaries/$${DESTINATION_PATH}
OBJECTS_DIR = $${PWD}/build/$${DESTINATION_PATH}/.obj
MOC_DIR = $${PWD}/build/$${DESTINATION_PATH}/.moc
UI_DIR = $${PWD}/build/$${DESTINATION_PATH}/.ui
RCC_DIR = $${PWD}/build/$${DESTINATION_PATH}/.rcc

message(project dir: $${PWD})
message(dest dir: $${DESTINATION_PATH})

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    source/Edge.cpp \
    source/EdgeContainer.cpp \
    source/Graph.cpp \
    source/GraphFactory.cpp \
    source/GraphImplementation.cpp \
    source/Vertex.cpp \
    source/VertexContainer.cpp \
    source/VertexIterator.cpp \
    source/main.cpp \

HEADERS += \
    source/Edge.h \
    source/EdgeContainer.h \
    source/Graph.h \
    source/GraphFactory.h \
    source/GraphImplementation.h \
    source/Vertex.h \
    source/VertexContainer.h \
    source/VertexIterator.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
