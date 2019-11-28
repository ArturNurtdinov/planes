#include "headers/Enemy.hpp"

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QFont>
#include <QList>
#include <stdlib.h>
#include <algorithm>

#include "headers/Player.hpp"
#include "headers/Game.hpp"

extern Game* game;

Enemy::Enemy(QGraphicsItem* parent) : Entity(parent)
{
  int random_number = rand() % 700;
  setPos(random_number, 0);

  setPixmap(QPixmap(":/images/enemy.png"));
  setScale(0.5);
  setTransformOriginPoint(50, 50);
  setRotation(180);

  game->enemies.push_back(this);

  qtimer = new QTimer(this);
  connect(qtimer, SIGNAL(timeout()), this, SLOT(move()));

  qtimer->start(50);
}

void Enemy::move()
{
  setPos(x(), y() + 5);
  QList<QGraphicsItem*> colliding_items = collidingItems();
  for (int i = 0; i < colliding_items.size(); ++i)
  {
    if (typeid(*(colliding_items[i])) == typeid(Player))
    {
      game->health->changeAndShow();
      game->enemies.erase(std::remove(game->enemies.begin(), game->enemies.end(), this), game->enemies.end());
      scene()->removeItem(this);
      delete this;
      if (game->health->get() == 0)
      {
        game->over();
        delete colliding_items[i];
      }
    }
  }
  if (pos().y() > 600)
  {
    scene()->removeItem(this);
    delete this;
  }
}

void Enemy::spawn()
{

}
