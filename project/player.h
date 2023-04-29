#ifndef PLAYER_H
#define PLAYER_H

#include "hitbox.h"

class player{
    public:
        float pointX;
        float pointY;
        float length;
        Hitbox box;
        
        player(float pointX,float pointY, float length){
            this->pointX = pointX;
            this->pointY = pointY;
            this->length= length;
            box = Hitbox(pointX,pointY,length,length);
            
            
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
            pointY = pointY + 0.01f;
        }
        void skey(){
            pointY = pointY - 0.01f;
        }
        void akey(){
            pointX = pointX - 0.01f;
        }
        void dkey(){
            pointX = pointX + 0.01f;
        }
        void wdkey(){
            dkey();
            wkey();
        }
};

#endif 
