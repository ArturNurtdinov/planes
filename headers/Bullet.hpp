#ifndef BULLET_H
#define BULLET_H

#include "headers/Entity.hpp"

class Bullet : public Entity
{
  Q_OBJECT
public:
  Bullet(QGraphicsItem* parent = nullptr);
  ~Bullet() = default;
public slots:
  void move();
  virtual void spawn() override;

private:
  QTimer* qtimer;
};

#endif // BULLET_H
