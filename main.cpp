#include "headers/Game.hpp"

#include <QApplication>

Game* game;

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);

  srand(700);
  game = new Game();
  game->show();

  return a.exec();
}
