#ifndef MYPIXMAPITEM_H
#define MYPIXMAPITEM_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>

class MyPixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    // test
public:
    explicit MyPixmapItem(QGraphicsPixmapItem *parent = 0);

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    const double RATE;

public :
    void reset();

signals:

public slots:
};

#endif // MYPIXMAPITEM_H
