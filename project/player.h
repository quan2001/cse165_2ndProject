#ifndef PLAYER_H
#define PLAYER_H

#include "hitbox.h"
#include "game.h"
#include "enemy.h"

class player{
    public:
        bool w_pressed;
        bool d_pressed;
        bool s_pressed;
        bool a_pressed;
        
        bool enter_pressed;
        float pointX;
        float pointY;
        float length;
        const float speed = 0.0055f;
        
        Hitbox box;
        
        player(float pointX,float pointY, float length){
            this->pointX = pointX;
            this->pointY = pointY;
            this->length= length;
            box = Hitbox(pointX,pointY,length,length);
            w_pressed = false;
            d_pressed = false;
            s_pressed = false;
            a_pressed = false;
            enter_pressed = false;

            
            
        }
        
        void shoot(std::vector<Enemy*> list){
            float width = pointX+(length/2.0f);
            float horizontal = 20.0f;
            int i;
            for(i=0;i<list.size();i++){
                if((list[i]->getHitBox()).intersectBox(pointX)){
                    list[i]->reduceHp();
                }
            }

        }

        ~player(){
            std::cout << "player destory" << std::endl;
        }
        float getX(){
            return pointX;
        }
        float getY(){
            return pointY;
        }
        float getlength(){
            return length;
        }
        void drawTriangle(){
            float width = pointX+(length/2.0f);
            //cout << width << " " << pointX;
            glColor3f( 0.5f, 0.0f, 0.5f );
            glBegin( GL_TRIANGLES );
                glVertex2f( pointX, pointY );
                glVertex2f( pointX+length, pointY );
                glVertex2f( width, pointY+ length);
            glEnd();
    

        }
        void print(){
            std::cout << "X: " << pointX << "Y: " << pointY << std::endl;
        }
        void wkey(){
            pointY = pointY + speed;
        }
        void skey(){
            pointY = pointY - speed;
        }
        void akey(){
            pointX = pointX - speed;
        }
        void dkey(){
            pointX = pointX + speed;
        }
        void wdkey(){
            dkey();
            wkey();
        }
};

#endif 
