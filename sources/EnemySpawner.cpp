#include "headers/EnemySpawner.hpp"

#include "headers/Enemy.hpp"
#include "headers/Boss.hpp"
#include "headers/Game.hpp"

extern Game* game;
void EnemySpawner::spawnEnemy()
{
  Enemy* enemy = new Enemy();
  enemy->spawn();
  game->player->scene()->addItem(enemy);
}

void EnemySpawner::spawnBoss()
{
  Boss* boss = new Boss();
  boss->spawn();
  game->player->scene()->addItem(boss);
}
