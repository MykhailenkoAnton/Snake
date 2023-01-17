#include <conio.h>
#include <time.h>
#include <thread>
#include <chrono>

#include "Gamesnake.h"
#include "Field.h"
#include "Snake.h"
#include "Fruits.h"
#include "Menu.h"

const int STEP_MS = 350;

GameSnake::GameSnake()
{
}

// main logic of game
void GameSnake::run()
{
    Snake * snake1 = new Snake;
    Fruits fruit;
    Menu * menu = new Menu;
    menu->showMenu();
    delete menu;

    std::thread t1(&GameSnake::userChoice, this, snake1);
    t1.detach();

    while (!_gameStatus)
    {
        if (field_.isSnakesBody(snake1))
        {
            field_.drawField(_gamePoint);
            _gameStatus = true;
        }
        else
        {
            field_.drawFruit(&fruit);
            if (field_.isEatingForSnake(snake1, &fruit))
            {
                snake1->addNewHead();
                _gamePoint += 10;
                fruit.setNewCoordForFruit();
                field_.drawFruit(&fruit);
            }
            snake1->moveSnake();
            field_.drawSnakeOnField(snake1);
            field_.drawField(_gamePoint);
            std::this_thread::sleep_for(std::chrono::milliseconds(STEP_MS));
        }
    }
    delete snake1;
}

// direction snake after user iput
void GameSnake::userChoice(Snake *snake)
{
    while (true)
    {
        const auto user_input = readingUserInput();
        switch (user_input)
        {
        case eActoins::LEFT:
            snake->setNewDirection(Direction::LEFT);
            break;
        case eActoins::RIGHT:
            snake->setNewDirection(Direction::RIGHT);
            break;
        case eActoins::DOWN:
            snake->setNewDirection(Direction::DOWN);
            break;
        case eActoins::UP:
            snake->setNewDirection(Direction::UP);
            break;
        default:
            break;
        }
    }
    
}

// User input
eActoins GameSnake::readingUserInput()
{
        const auto ch = _getch();
        switch (ch)
        {
        case 'a':
            return eActoins::LEFT;
            break;
        case 's':
            return eActoins::DOWN;
            break;
        case 'd':
            return eActoins::RIGHT;
            break;
        case 'w':
            return eActoins::UP;
            break;
        case '0':
        case 'q':
            // Use '0' for exit from thegame.
            exit(0);
        default:
            break;
        }
    // }

    return eActoins::NO_ACTIONS;
}
