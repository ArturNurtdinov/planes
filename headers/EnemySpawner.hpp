#ifndef ENEMYSPAWNER_HPP
#define ENEMYSPAWNER_HPP

#include <QObject>

class EnemySpawner : public QObject
{
  Q_OBJECT
public slots:
  void spawnEnemy();
  void spawnBoss();
};

#endif // ENEMYSPAWNER_HPP
