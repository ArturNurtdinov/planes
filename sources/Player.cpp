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

  isUpgraded = false;
}

void Player::keyPressEvent(QKeyEvent* event)
{
  if (event->key() == Qt::Key_Left)
  {
    if (pos().x() + 50 > 0)
    {
      setPos(x() - 20, y());
    }
  }
  else if (event->key() == Qt::Key_Right)
  {
    if (pos().x() < 700)
    {
      setPos(x() + 20, y());
    }
  }
  else if (event->key() == Qt::Key_Space)
  {
    if (!isUpgraded)
    {
      Bullet* bullet = new Bullet();
      bullet->spawn();
      scene()->addItem(bullet);
    }
    else
    {
      Bullet* first = new Bullet();
      first->spawn();
      first->setPos(x() + 25, y());
      scene()->addItem(first);

      Bullet* second = new Bullet();
      second->spawn();
      second->setPos(x() + 75, y());
      scene()->addItem(second);
    }
  }
}

void Player::spawn()
{
  setPos(300, 500);
  setFlag(QGraphicsItem::ItemIsFocusable);
  setFocus();
}

void Player::setUpgrade(bool upgrade)
{
  isUpgraded = upgrade;
}
