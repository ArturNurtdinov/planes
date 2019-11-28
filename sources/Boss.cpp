#include "headers/Boss.hpp"

#include <QTimer>
#include <QList>

#include "headers/Game.hpp"
#include "headers/Player.hpp"

extern Game* game;
Boss::Boss(QGraphicsItem* parent) : Entity(parent)
{
  health = 5;

  int random_number = rand() % 700;
  setPos(random_number, 0);

  setPixmap(QPixmap(":/images/enemy.png"));
  setScale(0.8);
  setTransformOriginPoint(50, 50);
  setRotation(180);

  game->enemies.push_back(this);
}

void Boss::spawn()
{
  qtimer = new QTimer(this);
  connect(qtimer, SIGNAL(timeout()), this, SLOT(move()));

  qtimer->start(40);
}

void Boss::move()
{
  setPos(x(), y() + 2);

  if (pos().y() > 600)
  {
    game->health->changeAndShow(-1);
    game->enemies.erase(std::remove(game->enemies.begin(), game->enemies.end(), this), game->enemies.end());
    scene()->removeItem(this);
    delete this;
    if (game->health->get() == 0)
    {
      game->over();
    }
  }
}

void Boss::decreaseHealth()
{
  --health;
}

int Boss::getHealth() const
{
  return health;
}
