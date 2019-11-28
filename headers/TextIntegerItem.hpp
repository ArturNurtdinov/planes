#ifndef TEXTITEM_HPP
#define TEXTITEM_HPP

#include <QGraphicsTextItem>

class TextIntegerItem : public QGraphicsTextItem
{
public:
  TextIntegerItem(QGraphicsTextItem* parent = nullptr) : QGraphicsTextItem(parent)
  {
  }

  virtual void changeAndShow() = 0;
  int get()
  {
    return number;
  }

protected:
  int number;
};

#endif // TEXTITEM_HPP
