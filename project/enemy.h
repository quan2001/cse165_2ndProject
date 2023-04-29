#ifndef ENEMY_H
#define ENEMY_H

#include "hitbox.h"

class Enemy {
private:
    
    
public:
    float pointX;
    float pointY;
    float width;
    float height;
    Hitbox box;
    virtual ~Enemy() {}
    virtual void draw() = 0;
    //virtual void update() = 0;
    virtual Hitbox getHitBox(){
        return box;
    }
};

class smallEnemy : public Enemy {
private:
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
public:
    smallEnemy(float x, float y,float width, float height){
            this->pointX = x;
            this->pointY = y;
            this->width = width;
            this->height = height;
            box = Hitbox(x,y,width,height);
    }
    ~smallEnemy(){
        std::cout << "small enemy destory" << std::endl;
    }
    
    void draw(){
        glColor3f(1.0f, 0.0f, 0.0f); // red

        // Draw the square
        glBegin(GL_QUADS);
            glVertex2f(pointX, pointY);           // bottom-left
            glVertex2f(pointX + width, pointY);  // bottom-right
            glVertex2f(pointX+ width, pointY + width);  // top-right
            glVertex2f(pointX, pointY + width);  // top-left
        glEnd();
    }
    
    void move(int direction){
        if(direction == 1){
            wkey();
        }
        if(direction == 2){
            wkey();
            dkey();
            
        }
        if(direction == 3){
            dkey();
            
        }
        if(direction == 4){
            dkey();
            skey();
        }
        if(direction == 5){
            skey();
            
        }
        if(direction == 6){
            skey();
            akey();
            
        }
        if(direction == 7){
            akey();
            
        }
        if(direction == 8){
            akey();
            wkey();
        }
    }
    //void update();
    //HitBox getHitBox() const;
private:
    
};

class mediumEnemy : public Enemy {
private:
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
public:
    mediumEnemy(float x, float y,float width, float height){
            this->pointX = x;
            this->pointY = y;
            this->width = width;
            this->height = height;
            box = Hitbox(x,y,width,height);
    }
    ~mediumEnemy(){
        std::cout << "destroy midEnemy" << std::endl;
    }
    void draw(){
        glColor3f(0.0f, 0.0f, 1.0f); // blue

        // Draw the square
        glBegin(GL_QUADS);
            glVertex2f(pointX, pointY);           // bottom-left
            glVertex2f(pointX + width, pointY);  // bottom-right
            glVertex2f(pointX + width, pointY + width);  // top-right
            glVertex2f(pointX, pointY + width);  // top-left
        glEnd();
    }
    void move(int direction){
        if(direction == 1){
            wkey();
        }
        if(direction == 2){
            wkey();
            dkey();
            
        }
        if(direction == 3){
            dkey();
            
        }
        if(direction == 4){
            dkey();
            skey();
        }
        if(direction == 5){
            skey();
            
        }
        if(direction == 6){
            skey();
            akey();
            
        }
        if(direction == 7){
            akey();
            
        }
        if(direction == 8){
            akey();
            wkey();
        }
    }
    //void update();
    //HitBox getHitBox() const;
private:
    
};

class boss : public Enemy {
public:
    boss(float x, float y,float width, float height){
            this->pointX = x;
            this->pointY = y;
            this->width = width;
            this->height = height;
            box = Hitbox(x,y,width,height);
    }
    ~boss(){
       
        std::cout << "destroy midEnemy" << std::endl;
    
    }
    void draw(){
        glColor3f(0.5f, 0.5f, 0.5f); // 

        // Draw the square
        glBegin(GL_QUADS);
            glVertex2f(pointX, pointY);           // bottom-left
            glVertex2f(pointX + width, pointY);  // bottom-right
            glVertex2f(pointX + width, pointY + width);  // top-right
            glVertex2f(pointX, pointY + width);  // top-left
        glEnd();
    }
    
    //void update();
    //HitBox getHitBox() const;
private:
    
};

#endif // ENEMY_H
