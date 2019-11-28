#ifndef GAME_HPP
#define GAME_HPP

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <deque>

#include "headers/Entity.hpp"
#include "headers/TextIntegerItem.hpp"

class Game : public QGraphicsView
{
public:
  Game(QWidget* parent = nullptr);
  ~Game();
  void show();
  void over();

  QGraphicsScene* scene;
  Entity* player;
  TextIntegerItem* score;
  TextIntegerItem* health;
  QTimer* qtimer;
  std::deque<QGraphicsItem*> enemies;
};

#endif // GAME_HPP
