#include "headers/Game.hpp"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QBrush>
#include <QObject>
#include <QImage>

#include "headers/Player.hpp"
#include "headers/Enemy.hpp"
#include "headers/Health.hpp"
#include "headers/Score.hpp"
#include "headers/EnemySpawner.hpp"

Game::Game(QWidget* parent) : QGraphicsView(parent)
{}

Game::~Game()
{
  delete scene;
  delete score;
  delete health;
  delete qtimer;
  for (size_t i = 0; i < enemies.size(); ++i)
  {
    delete enemies.at(i);
  }
  enemies.clear();
}

void Game::show()
{
  scene = new QGraphicsScene();
  player = new Player();
  player->spawn();
  scene->addItem(player);

  score = new Score();
  scene->addItem(score);

  health = new Health();
  health->setPos(health->x(), health->y() + 25);
  scene->addItem(health);

  QGraphicsView* view = new QGraphicsView(scene);
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setFixedSize(800, 600);
  view->show();

  scene->setSceneRect(0, 0, 800, 600);
  scene->setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

  EnemySpawner* spawner = new EnemySpawner();
  qtimer = new QTimer(this);
  QObject::connect(qtimer, SIGNAL(timeout()), spawner, SLOT(spawnEnemy()));
  QObject::connect(qtimer, SIGNAL(timeout()), spawner, SLOT(spawnBoss()));
  qtimer->start(2000);
}

void Game::over()
{
  qtimer->stop();
  scene->removeItem(player);
  delete player;
  for (size_t i = 0; i < enemies.size(); ++i)
  {
    if (enemies.at(i) != nullptr)
    {
      scene->removeItem(enemies.at(i));
      delete enemies.at(i);
    }
  }
}
