#include "headers/Bullet.hpp"

#include <QTimer>
#include <QGraphicsScene>

#include "headers/Enemy.hpp"
#include "headers/Game.hpp"

extern Game* game;

Bullet::Bullet(QGraphicsItem* parent) : Entity(parent)
{
  setPixmap(QPixmap(":/images/missile.png"));
  setScale(0.05);
  QTimer* qtimer = new QTimer();
  connect(qtimer, SIGNAL(timeout()), this, SLOT(move()));
  qtimer->start(50);

  bulletsound = new QMediaPlayer();
  bulletsound->setMedia(QUrl("qrc:/sounds/bullet_sound.wav"));
}

void Bullet::move()
{
  QList<QGraphicsItem*> colliding_items = collidingItems();
  for (int i = 0; i < colliding_items.size(); ++i)
  {
    if (typeid(*(colliding_items[i])) == typeid(Enemy))
    {
      scene()->removeItem(colliding_items[i]);
      scene()->removeItem(this);

      game->enemies.erase(std::remove(game->enemies.begin(), game->enemies.end(), colliding_items[i]), game->enemies.end());
      game->score->changeAndShow();

      delete colliding_items[i];
      delete this;
    }
  }

  setPos(x(), y() - 10);
  if (pos().y() < 20)
  {
    scene()->removeItem(this);
    delete this;
  }
}

void Bullet::spawn()
{
  setPos(game->player->x() + 50, game->player->y());
  bulletsound->play();
}
