#ifndef GAME_HPP
#define GAME_HPP

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <deque>

#include "headers/Player.hpp"
#include "headers/Score.hpp"
#include "headers/Health.hpp"

class Game : public QGraphicsView
{
public:
  Game(QWidget* parent = nullptr);
  ~Game();
  void show();
  void over();

  QGraphicsScene* scene;
  Player* player;
  Score* score;
  Health* health;
  QTimer* qtimer;
  std::deque<QGraphicsItem*> enemies;
};

#endif // GAME_HPP
