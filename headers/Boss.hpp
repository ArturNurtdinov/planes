#ifndef BOSS_HPP
#define BOSS_HPP

#include "headers/Entity.hpp"

class Boss : public Entity
{
  Q_OBJECT
public:
  Boss(QGraphicsItem* parent = nullptr);
  void decreaseHealth();
  int getHealth() const;
public slots:
  void move();
  virtual void spawn() override;

private:
  QTimer* qtimer;
  int health;
};

#endif // BOSS_HPP
