#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "headers/Entity.hpp"

class Enemy : public Entity
{
  Q_OBJECT
public:
  Enemy(QGraphicsItem* parent = nullptr);
  ~Enemy() = default;
public slots:
  void move();

private:
  QTimer* qtimer;
};

#endif // ENEMY_HPP
