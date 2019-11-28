#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <QObject>

class EnemySpawner : public QObject
{
  Q_OBJECT
  public slots:
      void spawn();
};

#endif // ENEMYSPAWNER_H
