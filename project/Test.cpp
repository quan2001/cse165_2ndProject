#include <GL/freeglut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "hitbox.h"
#include "enemy.h"
#include "player.h"
#include <vector>
#include "game.h"
using namespace std;

// Define the keyboard callback function

game space;


player shooter(0.01f,0.01f,0.04f);
void keyboardCallback(unsigned char key, int x, int y) {
    // Handle the keyboard input

        if (key == 27) {
         
            exit(0); // Exit the program
            
        }
        if (key == 'f') {
            
            glutFullScreen();
            glutPostRedisplay(); // maybe cause problems
        }
        if (key == 'w') {
            shooter.wkey();
            shooter.print();
            glutPostRedisplay();
        }
        if (key == 'a'){
            shooter.akey();
            shooter.print();
            glutPostRedisplay();
        }
        if (key == 's'){
            shooter.skey();
            shooter.print();
            glutPostRedisplay();
        }
        if ( key == 'd'){
            shooter.dkey();
            shooter.print();
            glutPostRedisplay();
        }
        if ( key == 'd' && key == 'w'){
            shooter.wdkey();
            shooter.print();
            glutPostRedisplay();
        }
            

    
}
void render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   shooter.drawTriangle();

   int i;
   //cout << space.enemyList.size() << endl;
   for(i=0;i<space.enemyList.size();i++){
    space.enemyList[i]->draw();
    //cout << i << endl
    
   }
   
   glutSwapBuffers();
   
}
void idle() {
    space.update();
    glutPostRedisplay(); // Mark the window for redisplay
}


int main(int argc, char** argv) {
    space.gameStart();
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    // Initialize GLUT and create a window
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL Window");

    glutDisplayFunc(render);
    glutIdleFunc(idle);
    // Set the keyboard callback function
    glutKeyboardFunc(keyboardCallback);
    
    

    // Enter the main loop
    glutMainLoop();
    return 0;
}
