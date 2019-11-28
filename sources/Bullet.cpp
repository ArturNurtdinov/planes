#include "headers/Bullet.hpp"

#include <QTimer>
#include <QGraphicsScene>

#include "headers/Enemy.hpp"
#include "headers/Game.hpp"
#include "headers/Player.hpp"
#include "headers/Boss.hpp"

extern Game* game;

Bullet::Bullet(QGraphicsItem* parent) : Entity(parent)
{
  setPixmap(QPixmap(":/images/missile.png"));
  setScale(0.05);

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
      game->score->changeAndShow(1);

      delete colliding_items[i];
      delete this;
      return;
    }
    else if (typeid(*(colliding_items[i])) == typeid(Boss))
    {
      dynamic_cast<Boss*>(colliding_items[i])->decreaseHealth();
      if (dynamic_cast<Boss*>(colliding_items[i])->getHealth() == 0)
      {
        scene()->removeItem(colliding_items[i]);

        game->enemies.erase(std::remove(game->enemies.begin(), game->enemies.end(), colliding_items[i]), game->enemies.end());
        game->score->changeAndShow(5);

        delete colliding_items[i];
      }
      scene()->removeItem(this);
      delete this;
      return;
    }
  }

  if (game->score->get() > 100)
  {
    game->player->setUpgrade(true);
  }

  setPos(x(), y() - 10);
  if (pos().y() < 10)
  {
    scene()->removeItem(this);
    delete this;
  }
}

void Bullet::spawn()
{
  setPos(game->player->x() + 50, game->player->y());
  bulletsound->play();

  qtimer = new QTimer();
  connect(qtimer, SIGNAL(timeout()), this, SLOT(move()));
  qtimer->start(50);
}
