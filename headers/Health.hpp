#ifndef HEALTH_HPP
#define HEALTH_HPP

#include "headers/TextIntegerItem.hpp"

class Health : public TextIntegerItem
{
public:
  Health(QGraphicsTextItem* parent = nullptr);
  virtual void changeAndShow();
};

#endif // HEALTH_HPP
