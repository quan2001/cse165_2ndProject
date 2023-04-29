#ifndef GAME_H
#define GAME_H
#include "enemy.h"
#include <vector>
#include "hitbox.h"

class game{
    
    public:
        std::vector<Enemy> enemyList;

        
        void addSmallEnemy(){
            enemyList.push_back(new smallEnemy(0.01f,0.01f,0.04f,0.04f));
        }
        void addMidEnemy(){

        }
        void addBoss(){

        }
        void gameStart(){
            int i;
            for(i=0;i<enemyList.size();i++){
                addSmallEnemy();
            }
        }
        game(){

        }
        
        
};

#endif 
