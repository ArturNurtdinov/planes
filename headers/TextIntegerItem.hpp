#ifndef TEXTITEM_HPP
#define TEXTITEM_HPP

#include <QGraphicsTextItem>

class TextIntegerItem : public QGraphicsTextItem
{
public:
  TextIntegerItem(QGraphicsTextItem* parent = nullptr) : QGraphicsTextItem(parent)
  {}

  virtual void changeAndShow(int amount) = 0;
  int get()
  {
    return number;
  }

protected:
  int number;
};

#endif // TEXTITEM_HPP
