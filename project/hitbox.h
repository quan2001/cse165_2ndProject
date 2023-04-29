#ifndef HITBOX_H
#define HITBOX_H

class Hitbox {
private:
    float x, y, width, height;

public:
    Hitbox(){

    }

    Hitbox(float x, float y, float width, float height){
        this->x = x;
        this->y = y;
        this-> width = width;
        this->height = height;
    }
    ~Hitbox(){
        
    }
    bool intersectBox(Hitbox box) {
        // Get the coordinates of the current box's top-right corner
        float xMax = x + width;
        float yMax = y + height;
        // Get the coordinates of the argument box's top-right corner
        float boxXMax = box.x + box.width;
        float boxYMax = box.y + box.height;
        // Check for overlap along the x-axis
        bool xOverlap = (box.x <= x && x <= boxXMax) || (x <= box.x && box.x <= xMax);
        // Check for overlap along the y-axis
        bool yOverlap = (box.y <= y && y <= boxYMax) || (y <= box.y && box.y <= yMax);
        // If both xOverlap and yOverlap are true, there is intersection
        return xOverlap && yOverlap;
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    float getWidth(){
        return width;
    }
    float getHeight(){
        return height;
    }
};

#endif
