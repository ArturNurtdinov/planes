#include "headers/Player.hpp"
#include "headers/Enemy.hpp"

#include <QKeyEvent>
#include <QGraphicsScene>
#include "headers/Bullet.hpp"

Player::Player(QGraphicsItem* parent) : Entity(parent)
{
  setPixmap(QPixmap(":/images/player.png"));
  setScale(0.5);

  bulletsound = new QMediaPlayer();
  bulletsound->setMedia(QUrl("qrc:/sounds/bullet_sound.wav"));
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
    bullet->setPos(x() + 50, y());
    scene()->addItem(bullet);

    bulletsound->play();
  }
}

void Player::spawn()
{
  Enemy* enemy = new Enemy();
  scene()->addItem(enemy);
}
