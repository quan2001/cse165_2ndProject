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

game Game();
game.gameStart();

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
   glutSwapBuffers();
   
}


int main(int argc, char** argv) {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    // Initialize GLUT and create a window
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("OpenGL Window");

    glutDisplayFunc(render);
    // Set the keyboard callback function
    glutKeyboardFunc(keyboardCallback);
    

    // Enter the main loop
    glutMainLoop();
    return 0;
}
