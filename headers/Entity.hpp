#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <QObject>
#include <QGraphicsPixmapItem>

class Entity : public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Entity(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent) {}
  virtual ~Entity() = default;
  virtual void spawn() = 0;
};

#endif // ENTITY_HPP
