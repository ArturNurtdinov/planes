#ifndef MYRECT_HPP
#define MYRECT_HPP

#include <deque>

#include "headers/Entity.hpp"
#include "headers/Bullet.hpp"

class Player : public Entity
{
  Q_OBJECT
public:
  Player(QGraphicsItem* parent = nullptr);
  void keyPressEvent(QKeyEvent* event) override;
  virtual void spawn() override;
  void setUpgrade(bool upgrade);

private:
  bool isUpgraded;
};

#endif // MYRECT_HPP
