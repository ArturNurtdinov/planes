#include "headers/EnemySpawner.hpp"

#include "headers/Enemy.hpp"
#include "headers/Game.hpp"

extern Game* game;
void EnemySpawner::spawn()
{
  Enemy* enemy = new Enemy();
  game->player->scene()->addItem(enemy);
}
