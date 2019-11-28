#include "headers/Player.hpp"
#include "headers/Enemy.hpp"

#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>
#include "headers/Bullet.hpp"

Player::Player(QGraphicsItem* parent) : Entity(parent)
{
  setPixmap(QPixmap(":/images/player.png"));
  setScale(0.5);
}

void Player::keyPressEvent(QKeyEvent* event)
{
  if (event->key() == Qt::Key_Left)
  {
    if (pos().x() > 0)
    {
      setPos(x() - 15, y());
    }
  }
  else if (event->key() == Qt::Key_Right)
  {
    if (pos().x() + 100 < 800)
    {
      setPos(x() + 15, y());
    }
  }
  else if (event->key() == Qt::Key_Space)
  {
    Bullet* bullet = new Bullet();
    bullet->spawn();
    scene()->addItem(bullet);
  }
}

void Player::spawn()
{
  setPos(300, 500);
  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}
