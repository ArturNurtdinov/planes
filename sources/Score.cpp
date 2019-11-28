#include "headers/Score.hpp"
#include <QFont>

Score::Score(QGraphicsTextItem* parent) : TextIntegerItem(parent)
{
  number = 0;

  setPlainText(QString("Score: ") + QString::number(number));
  setDefaultTextColor(Qt::blue);
  setFont(QFont("times", 16));
}

void Score::changeAndShow()
{
  number++;
  setPlainText(QString("Score: ") + QString::number(number));
}
