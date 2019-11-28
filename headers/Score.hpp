#ifndef SCORE_HPP
#define SCORE_HPP

#include "headers/TextIntegerItem.hpp"

class Score : public TextIntegerItem
{
public:
  Score(QGraphicsTextItem* parent = nullptr);
  virtual void changeAndShow() override;
};

#endif // SCORE_HPP
