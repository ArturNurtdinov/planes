#include "headers/Health.hpp"
#include <QFont>

#include "headers/Game.hpp"

extern Game* game;

Health::Health(QGraphicsTextItem* parent) : TextIntegerItem(parent)
{
  number = 3;

  setPlainText(QString("Health: ") + QString::number(number));
  setDefaultTextColor(Qt::red);
  setFont(QFont("times", 16));
}

void Health::changeAndShow()
{
  number--;
  setPlainText(QString("Health: ") + QString::number(number));

  if (number == 0)
  {
    setPlainText(QString("Game over!"));
  }
}
