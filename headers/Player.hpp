#ifndef MYRECT_HPP
#define MYRECT_HPP

#include "headers/Entity.hpp"
#include <QMediaPlayer>

class Player : public Entity
{
  Q_OBJECT
public:
  Player(QGraphicsItem* parent = nullptr);
  ~Player() = default;
  void keyPressEvent(QKeyEvent* event);
public slots:
  void spawn();

private:
  QMediaPlayer* bulletsound;
};

#endif // MYRECT_HPP
