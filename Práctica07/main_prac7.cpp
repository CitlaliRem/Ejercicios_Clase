//Semestre 2019 - 11
//************************************************************//
//************************************************************//
//******** Alumno: BADILLO REMIGIO DULCE CITLALI  ************//
//*************				PRÁCTICA 7				**********//
//*************			Visual Studio 2017				******//
//************************************************************//
//**** Para mover el teclado:    *****************************//
//****  Derecha: teclas 'A' 'a'      *************************//
//****  Izquierda: teclas 'D' 'd'    *************************//
//****  Arriba: teclas 'Q' 'q'       *************************//
//****  Abajo: teclas 'E' 'e'         ************************//
//****  Acercar: teclas 'W' 'w'      *************************//
//****  Alejar: teclas 'S' 's'       *************************//
//************************************************************//

#include "Main.h" 

// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int lunat = 0;
int lunat2 = 0;
int lunat3 = 0;
int marte = 0.;
int jupiter = 0;
int saturno = 0;
int urano = 0;
float camaraZ = 0.0;
float camaraX = 0.0;
float camaraY = 0.0;


GLfloat LuzAmbientalSol[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat LuzDifusaSol[] = { 1.0f, 1.0f, 1.0f, 1.0f };				// Specular Light Values
GLfloat LuzEspecularSol[] = { 0.0f, 1.0f, 1.0f, 1.0f };			// Light Position
GLfloat LuzPosicionSol[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //Porque aquí está el sol

GLfloat MercurioAmbiental[] = { 0.2125f, 0.1275f, 0.054f, 1.0f };
GLfloat MercurioDiffuse[] = { 0.714f, 0.4284f, 0.18144f, 1.0f };			// Mercurio
GLfloat MercurioSpecular[] = { 0.393548f, 0.271906f, 0.166721f, 1.0f };
GLfloat MercurioShininess[] = { 0.2 };

GLfloat VenusAmbiental[] = { 0.19125f, 0.0735f, 0.0225f, 1.0f };
GLfloat VenusDiffuse[] = { 0.7038f, 0.27048f, 0.0828f, 1.0f };			//Venus
GLfloat VenusSpecular[] = { 0.256777f, 0.137622f, 0.086014f, 1.0f };
GLfloat VenusShininess[] = { 0.1 };

GLfloat EarthAmbiental[] = { 0.1f, 0.18725f, 0.1745f, 1.0f };
GLfloat EarthDiffuse[] = { 0.396f, 0.74151, 0.69102f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.297254, 0.30829, 0.306678, 1.0 };
GLfloat EarthShininess[] = { 0.1 };

GLfloat MoonAmbiental[] = { 0.25f, 0.20725f, 0.20725f, 1.0f };
GLfloat MoonDiffuse[] = { 1.0f, 0.829f, 0.829f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 0.296648f, 0.296648f, 0.296648, 1.0f };
GLfloat MoonShininess[] = { 0.088 };

GLfloat MarsAmbiental[] = { 1.0f, 0.0f, 0.0f, 1.0f };
GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glLightfv(GL_LIGHT1, GL_AMBIENT, LuzAmbientalSol);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LuzDifusaSol);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LuzEspecularSol);

	glEnable(GL_LIGHT1);

}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX,camaraY,-5.0+camaraZ);			//camara
	
	glLightfv(GL_LIGHT1, GL_POSITION, LuzPosicionSol), //Tipo de luz, parametro de la posición
		glEnable(GL_LIGHTING);

	glPushMatrix();//sistema solar
		
	glPushMatrix();//sol
		glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
		glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H,V);
		glEnable(GL_LIGHTING);
	glPopMatrix();//sol

	glPushMatrix();//mercurio
		glRotatef(mercurio, 0, 1, 0);//traslacion
		glTranslatef(3.2, 0, 0);
		glRotatef(mercurio, 0, 1, 0);//rotacion
		glMaterialfv(GL_FRONT, GL_AMBIENT, MercurioAmbiental);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);
		glutSolidSphere(0.3, 8, 8);
	glPopMatrix();//mercurio

	glPushMatrix();//venus
		glRotatef(venus, 0, 1, 0);//traslacion
		glTranslatef(4.7, 0, 0);
		glRotatef(venus, 0, 1, 0);//rotacion
		glMaterialfv(GL_FRONT, GL_AMBIENT, VenusAmbiental);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
		glutSolidSphere(0.3, 8, 8);
	glPopMatrix();//venus

	glPushMatrix();//tierra
		glRotatef(tierra, 0, 1, 0);//traslacion
		glTranslatef(7.4, 0, 0);
		glRotatef(tierra, 0, 1, 0);//rotacion
		glMaterialfv(GL_FRONT, GL_AMBIENT, EarthAmbiental);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
		glutSolidSphere(0.7, 8, 8);
		glPushMatrix();//luna
			glRotatef(tierra, 0, 1, 0);//traslacion
			glTranslatef(1.2, 0, 0);
			glRotatef(lunat, 0, 1, 0);//rotacion
			glMaterialfv(GL_FRONT, GL_AMBIENT, MoonAmbiental);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.3, 8, 8);
		glPopMatrix();//luna
	glPopMatrix();//tierra

	glPushMatrix();//marte
		glRotatef(marte, 0, 1, 0);//traslacion
		glTranslatef(9.8, 0, 0);
		glRotatef(marte, 0, 1, 0);//rotacion
		glMaterialfv(GL_FRONT, GL_AMBIENT, MarsAmbiental);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
		glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);
		glutSolidSphere(0.4, 8, 8);
		glPushMatrix();//luna1
			glRotatef(marte, 0, 1, 0);//traslacion
			glTranslatef(-0.6, 0, 0);
			glRotatef(lunat, 0, 1, 0);//rotacion
			glMaterialfv(GL_FRONT, GL_AMBIENT, MoonAmbiental);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.1, 8, 8);
		glPopMatrix();//luna1
		glPushMatrix();//luna2
			glRotatef(lunat2, 0, 1, 0);//traslacion
			glTranslatef(0.5, 0.1, 0);
			glRotatef(lunat2, 0, 1, 0);//rotacion
			glMaterialfv(GL_FRONT, GL_AMBIENT, MoonAmbiental);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
			glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
			glutSolidSphere(0.1, 8, 8);
		glPopMatrix();//luna2
	glPopMatrix();//marte


		glPushMatrix();//jupiter
			glRotatef(jupiter, 0, 1, 0);//traslacion
			glTranslatef(13.8, 0, 0);
			glRotatef(jupiter, 0, 1, 0);//rotacion
			glColor3f(1.0, 0.5, 0.0);
			glutSolidSphere(1.0, 8, 8);
			glPushMatrix();//luna1
				glRotatef(marte, 0, 1, 0);//traslacion
				glTranslatef(1.6, 0, 0);
				glRotatef(lunat, 0, 1, 0);//rotacion
				glColor3f(1.0, 1.0, 1.0);
				glutSolidSphere(0.2, 8, 8);
			glPopMatrix();//luna1
			glPushMatrix();//luna2
				glRotatef(lunat2, 0, 1, 0);//traslacion
				glTranslatef(1.5, 0.7, 0);
				glRotatef(lunat2, 0, 1, 0);//rotacion
				glColor3f(1.0, 1.0, 1.0);
				glutSolidSphere(0.1, 8, 8);
				glPopMatrix();//luna2
			glPushMatrix();//luna3
				glRotatef(lunat3, 0, 1, 0);//traslacion
				glTranslatef(-1.5, 1.0, 0);
				glRotatef(lunat3, 0, 1, 0);//rotacion
				glColor3f(1.0, 1.0, 1.0);
				glutSolidSphere(0.3, 8, 8);
			glPopMatrix();//luna3
		glPopMatrix();//jupiter

		glPushMatrix();//saturno
			glRotatef(saturno, 0, 1, 0);//traslacion
			glTranslatef(19.0, 0, 0);
			glRotatef(saturno, 0, 1, 0);//rotacion
			glColor3f(0.5, 1.0, 0.5);
			glutSolidSphere(0.9, 8, 8);
			//Anillo1
				glRotatef(45,1,0,0);
				glColor3f(0.5, 0.5, 0.5);
				glutSolidTorus(0.1,1.1,15,15);
			//Anillo2
				glColor3f(0.0, 0.5, 0.0);
				glutSolidTorus(0.09, 1.4, 15, 15);
		glPopMatrix();//saturno

		glPushMatrix();//urano
			glRotatef(urano, 0, 1, 0);//traslacion
			glTranslatef(23.8, 0, 0);
			glRotatef(urano, 0, 1, 0);//rotacion
			glColor4f(1.0, 0.0, 1.0, 0.0);
			glutSolidSphere(0.8, 8, 8);
			glPushMatrix();//luna
				glRotatef(lunat, 0, 1, 0);//traslacion
				glTranslatef(1.2, 0, 0);
				glColor3f(1.0, 1.0, 1.0);
				glRotatef(lunat, 0, 1, 0);//rotacion
				glutSolidSphere(0.3, 8, 8);
			glPopMatrix();//luna
		glPopMatrix();//urano

	glPopMatrix();//SS

	glutSwapBuffers ( );

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 35)
	{
		sol = (sol - 5) % 360;
		mercurio = (mercurio - 5) % 360;
		venus = (venus - 4) % 360;
		tierra = (tierra - 2) % 360;
		lunat = (lunat - 1) % 360;
		lunat2 = (lunat2 - 2) % 360;
		lunat3 = (lunat3 - 3) % 360;
		marte = (marte - 3) % 360;
		jupiter = (jupiter - 2) % 360;
		saturno = (saturno - 1) % 360;
		urano = (urano - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'q':
		case 'Q':
			camaraY -= 0.5f;
			break;
		case 'e':
		case 'E':
			camaraY += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 7"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}