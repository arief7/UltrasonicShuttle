#ifndef __GAME_H__
#define __GAME_H__

#include "common.h"
#include "GlobalSpriteResource.h"
#include "BulletFlight.h"
#include "EnemyFlight.h"

#include "Player.h"
#include "Enemy.h"
#include "Explosion.h"

#include "Level.h"

#include <boost/thread.hpp>

#include "BufferedAsyncSerial.h"

using namespace boost;
using namespace std;

class Game {
public:
    Game();
    ~Game();

    int init();
    void run();
    void reset();

    void backGround();
    void handleInput();
    void readInputEvent();

    void handleLevel();

    void handleBullets();

    void handleEnemies();
    int getEmptyEnemy();

    void handleExplosions();
    int getEmptyExplosion();
    void addExplosion(int image, int x, int y, int damage);

    void shootbeam(int beam);

    bool firstrun = false;

    Player* player;



    SDL_Surface* screen;

    SDL_Surface* text;

    int gs;

    int mouseX;
    int mouseY;
    int sonicDistanceX;
    int sonicDistanceY;
    int sonicMiddleX;
    int sonicMiddleY;

    bool KEYS[322];  // 322 is the number of SDLK_DOWN events

    GlobalSpriteResource* gsr;
    BulletFlight* bf;
    EnemyFlight* ef;

    Enemy enemies[MAX_ENEMIES];

    Bullet eBullets[MAX_BULLETS];

    Explosion explosions[MAX_EXPLOSIONS];

    Level* level;

  //  int gameSpeed;


};
#endif
