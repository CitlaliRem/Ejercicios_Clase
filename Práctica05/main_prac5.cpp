//Semestre 2019 - II
//************************************************************//
//************************************************************//
//******** Alumno: BADILLO REMIGIO DULCE CITLALI  ************//
//******    				PRÁCTICA 5					******//
//********	 		Visual Studio 2017				******//

//**** Para mover el teclado:        *************************//
//****  Derecha: teclas 'A' 'a'      *************************//
//****  Izquierda: teclas 'D' 'd'    *************************//
//****  Arriba: teclas 'Q' 'q'       *************************//
//****  Abajo: teclas 'E' 'e'         ************************//
//****  Acercar: teclas 'W' 'w'      *************************//
//****  Alejar: teclas 'S' 's'       *************************//
//****  Brazo positivo: tecla 'h'     ************************//
//****  Brazo negativo: tecla 'H'     ************************//
//****  Codo positivo: tecla 'c'      ************************//
//****  Codo negativo: tecla 'C'      ************************//
//****  Palma positivo: tecla 'P'     ************************//
//****  Palma negativo: tecla 'p'     ************************//
//****  Palma positivo: tecla 'm'     ************************//
//****  Palma negativo: tecla 'M'     ************************//
//************************************************************//


#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float transY = 0.0f;

float angleX = 0.0f;
float angleY = 0.0f;

int screenW = 0.0;
int screenH = 0.0;

float angHombro = 0.0f;
float angCodo = 0.0f;
float angMuñeca = 0.0f;
float angMano = 0.0f;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);

	//Poner Código Aquí. (0,0,0)
	
	glPushMatrix(); //dibuja brazo 1
		
		glTranslatef(-2.5, 1.25, 0.0); // (-2.5,1.25,0.0)
		glRotatef(angHombro, 0, 0, 1); //rotate para el hombro
		
		glPushMatrix(); //dibuja  hombro 2
			glTranslatef(2.5, -1.25, 0.0); //(0,0,0)
			glScalef(5.0, 2.5, 5.0);
			prisma();
		glPopMatrix(); //2
		
		glPushMatrix();//dibuja antebrazo 3
			glRotatef(angCodo, 0, 0, 1); //rotate para el codo
			
			glPushMatrix(); //4
				glTranslatef(8.0,-1.25,0.0);
				glScalef(6.0, 2.5, 3.0);
				prisma();
			glPopMatrix();//4

			glPushMatrix(); //5
				glRotatef(angMuñeca, 0, 1, 0); // rotate para la muñeca
				
				glPushMatrix();//6 dibuja palma
					glTranslatef(12.0, -1.25, 0.0);
					glScalef(2.0, 2.5, 2.0);
					prisma();
				glPopMatrix(); //6
					

				glPushMatrix(); //21
				glRotatef(angMano, 0, 1, 0);

				glPushMatrix();//dedo pulgar 1 7
					glTranslatef(12.25, 0.25, 0.0);
					glScalef(0.5, 0.5, 1.0);
					prisma();
				glPopMatrix(); //7

				glPushMatrix();//dedo pulgar 2 8
					glTranslatef(12.25, 0.75, 0.0);
					glScalef(0.5, 0.5, 1.0);
					prisma();
				glPopMatrix(); //8


				glPushMatrix();//dedo índice 1 9
					glTranslatef(13.25, -0.25, 0.0);
					glScalef(0.5, 0.5, 1.0);
					prisma();
				glPopMatrix(); //9

				glPushMatrix();//dedo índice 2 10
					glTranslatef(13.75, -0.25, 0.0);
					glScalef(0.5, 0.5, 1.0);
					prisma();
				glPopMatrix(); //10

				glPushMatrix();//dedo índice 3 11
					glTranslatef(14.25, -0.25, 0.0);
					glScalef(0.5, 0.5, 1.0);
					prisma();
				glPopMatrix(); //11


				glPushMatrix();//dedo medio 1 12
					glTranslatef(13.375, -0.825, 0.0);
					glScalef(0.75, 0.5, 1.0);
					prisma();
				glPopMatrix(); //12

				glPushMatrix();//dedo medio 2 13
					glTranslatef(14.125, -0.825, 0.0);
					glScalef(0.75, 0.5, 1.0);
					prisma();
				glPopMatrix(); //13

				glPushMatrix();//dedo medio 3 14
					glTranslatef(14.875, -0.825, 0.0);
					glScalef(0.75, 0.5, 1.0);
					prisma();
				glPopMatrix(); //14

				
				glPushMatrix();//dedo anular 1 15
					glTranslatef(13.25, -1.5, 0.0);
					glScalef(0.5, 0.5, 1.0);
					prisma();
				glPopMatrix(); //15

				glPushMatrix();//dedo anular 2 16
					glTranslatef(13.75, -1.5, 0.0);
					glScalef(0.5, 0.5, 1.0);
					prisma();
				glPopMatrix(); //16

				glPushMatrix();//dedo anular 3 17
					glTranslatef(14.25, -1.5, 0.0);
					glScalef(0.5, 0.5, 1.0);
					prisma();
				glPopMatrix(); //17
				
				
				glPushMatrix();//dedo meñique 1 18
					glTranslatef(13.2, -2.25, 0.0);
					glScalef(0.4, 0.5, 1.0);
					prisma();
				glPopMatrix(); //18

				glPushMatrix();//dedo meñique 2 19
					glTranslatef(13.6, -2.25, 0.0);
					glScalef(0.4, 0.5, 1.0);
					prisma();
				glPopMatrix(); //19

				glPushMatrix();//dedo meñique 3 20
					glTranslatef(14.0, -2.25, 0.0);
					glScalef(0.4, 0.5, 1.0);
					prisma();
				glPopMatrix(); //20

			
				glPopMatrix();
			glPopMatrix();//5

		glPopMatrix(); //3
	glPopMatrix();//1

	glutSwapBuffers ( );
  // Swap The Buffers
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

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.3, 0.3,-0.3, 0.3, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 'e':
		case 'E':
			transY += 0.2f;
			break;
		case 'q':
		case 'Q':
			transY -= 0.2f;
			break;

		case 'h':
			if (angHombro < 90) {
				angHombro += 0.5f;
				printf("%f ", angHombro);
			}
			break;
		case 'H':
			if (angHombro > -90) {
				angHombro -= 0.5f;
				printf("%f ", angHombro);
			}
			break;

		case 'c':
			if (angCodo < 10) {
				angCodo += 0.5f;
				printf("%f ", angCodo);
			}
			break;
		case 'C':
			if (angCodo > -15) {
				angCodo -= 0.5f;
				printf("%f ", angCodo);
			}
			break;


		case 'p':
			if (angMuñeca < 10) {
				angMuñeca += 0.5f;
				printf("%f ", angCodo);
			}
			break;
		case 'P':
			if (angMuñeca > -15) {
				angMuñeca -= 0.5f;
				printf("%f ", angCodo);
			}
			break;



		case 'm':
			if (angMano < 7) {
				angMano += 0.5f;
				printf("%f ", angMano);
			}
			break;
		case 'M':
			if (angMano > -5) {
				angMano -= 0.5f;
				printf("%f ", angMano);
			}
			break;


		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



