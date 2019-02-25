//Semestre 2019 - II

/**********  BADILLO REMIGIO DULCE CITLALI *****************/
/**********        PRÁCTICA #2             *****************/
/**********      VISUAL STUDIO 2017        *****************/


#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	//glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// Negro de fondo
	//glClearDepth(1.0f);									// Configuramos Depth Buffer
	//glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//glBegin(GL_POINTS); //Un vértice, un punto
	//glBegin(GL_LINES); //Líneas necesitan dos vértices
	//glBegin(GL_LINE_LOOP); //Líneas, Sin fondo, varios vértices
	//glBegin(GL_TRIANGLES); //Sólidos, tres vértices
	//glBegin(GL_QUADS); //Sólido, cuatro vértices
	
//******   LETRA C     *************/
	
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); //amarillo
	glVertex3f(-14.0f, 3.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f); //verde
	glVertex3f(-14.0f, -3.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);//azul
	glVertex3f(-13.0f, -3.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f); //rojo
	glVertex3f(-13.0f, 3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-13.0f, 4.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-13.0f, 3.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-9.0f, 3.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.0f, 4.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-13.0f,-3.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-13.0f,-4.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-9.0f,-4.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-9.0f,-3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-9.0f, 3.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-9.0f, 2.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-8.0f, 2.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-8.0f, 3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-9.0f,-2.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-9.0f,-3.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-8.0f,-3.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-8.0f,-2.0f, 0.0f);
	glEnd();


	//******   LETRA G     *************/

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-7.0f, 3.0f, 0.0f);//1
	glVertex3f(-7.0f, -3.0f, 0.0f);//2
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-6.0f, -3.0f, 0.0f);//3
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-6.0f, 3.0f, 0.0f);//4
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-6.0f, 4.0f, 0.0f);
	glVertex3f(-6.0f, 3.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, 3.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 4.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-6.0f, -3.0f, 0.0f);
	glVertex3f(-6.0f, -4.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -4.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, -3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 3.0f, 0.0f);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, 3.0f, 0.0f);
	glVertex3f(-2.0f, 2.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f,-3.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f,-3.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-3.0f, 0.0f, 0.0f);
	glVertex3f(-3.0f, -1.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-2.0f, -1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(-2.0f, 0.0f, 0.0f);
	glEnd();

	//******   LETRA D     *************/

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 4.0f, 0.0f);
	glVertex3f(0.0f, 3.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(5.0f, 3.0f, 0.0f);
	glVertex3f(5.0f, 4.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f,-3.0f, 0.0f);
	glVertex3f(0.0f,-4.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(5.0f,-4.0f, 0.0f);
	glVertex3f(5.0f,-3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(1.0f, 3.0f, 0.0f);
	glVertex3f(1.0f, -3.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, -3.0f, 0.0f);
	glVertex3f(2.0f, 3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(5.0f, 3.0f, 0.0f);
	glVertex3f(5.0f, 2.0f, 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(6.0f, 2.0f, 0.0f);
	glVertex3f(6.0f, 3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(5.0f, -2.0f, 0.0f);
	glVertex3f(5.0f, -3.0f, 0.0f);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex3f(6.0f, -3.0f, 0.0f);
	glVertex3f(6.0f, -2.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(6.0f, 2.0f, 0.0f);
	glVertex3f(6.0f, -2.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(7.0f, -2.0f, 0.0f);
	glVertex3f(7.0f, 2.0f, 0.0f);
	glEnd();


	//******   LETRA B    *************/

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(8.0f, 4.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(8.0f, 3.0f, 0.0f);
	glVertex3f(13.0f, 3.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(13.0f, 4.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(8.0f, -3.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(8.0f, -4.0f, 0.0f);
	glVertex3f(13.0f, -4.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(13.0f, -3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(9.0f, 3.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(9.0f, -3.0f, 0.0f);
	glVertex3f(10.0f, -3.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(10.0f, 3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(13.0f, 3.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(13.0f, 1.0f, 0.0f);
	glVertex3f(14.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(14.0f, 3.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(13.0f, 0.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(13.0f, -3.0f, 0.0f);
	glVertex3f(14.0f, -3.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(14.0f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(10.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(10.0f, 0.0f, 0.0f);
	glVertex3f(13.0f, 0.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(13.0f, 1.0f, 0.0f);
	glEnd();

	glFlush();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
	if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Ortogonal
	glOrtho(-15,15,-15,15,-1,2);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Práctica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  (keyboard);	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}

