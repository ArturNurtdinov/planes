#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "headers/Entity.hpp"

class Enemy : public Entity
{
  Q_OBJECT
public:
  Enemy(QGraphicsItem* parent = nullptr);
public slots:
  void move();
  virtual void spawn() override;

private:
  QTimer* qtimer;
};

#endif // ENEMY_HPP
