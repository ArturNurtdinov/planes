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
  delete enemyTimer;
  delete bossTimer;
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
  enemyTimer = new QTimer(this);
  QObject::connect(enemyTimer, SIGNAL(timeout()), spawner, SLOT(spawnEnemy()));
  enemyTimer->start(1000);

  bossTimer = new QTimer(this);
  QObject::connect(bossTimer, SIGNAL(timeout()), spawner, SLOT(spawnBoss()));
  bossTimer->start(3000);
}

void Game::over()
{
  enemyTimer->stop();
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
