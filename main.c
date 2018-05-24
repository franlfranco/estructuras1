/*
Sean los arreglos paralelos: int matricula[20], char nombre[20][30].
1. Crear una función que los cargue, hasta que el usuario lo decida.
2. Crear una función que busque dentro del arreglo de matrículas y retorne la posición de un determinado valor.
3. Hacer una función que reciba como parámetro ambos arreglos y
encuentre el nombre correspondiente a una determinada matrícula y lo imprima por pantalla.
Se debe invocar la función 2
4. Hacer una función que reciba como parámetro ambos arreglos y ordene ambos por nombre.
Sea la estructura:
typedef struct {
int matricula; char nombre[30]; char sexo; //m ó f
} alumno;
5. Hacer una función que cargue un arreglo de struct alumno, hasta que el usuario lo decida.
6. Hacer una función que escriba por pantalla el nombre de un alumno, conociendo su matricula.
7. Hacer una función que ordene el arreglo de struct alumno por medio del método de selección. El criterio de ordenación es el número de matrícula.
8. Hacer una función que muestre por pantalla el nombre y la matrícula de los varones.
9. Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
10. Hacer una función que cuente y retorne la cantidad de varones que tiene un arreglo de struct alumno.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const int maxC = 30;
const int maxDim = maxC;

typedef struct {
int matricula; char nombre[30]; char sexo; //m ó f
} alumno;

int cargaParalela(int matricula[], char nombre[][maxC], int dim){
  char control = 's';
  int i=0;

  while(control == 's'&&i<dim){
    printf("Ingrese un nombre\n" );
    fflush(stdin);
    scanf("%s",nombre[i] );
    printf("Ingrese la matricula\n");
    fflush(stdin);
    scanf("%i",&matricula[i] );
    i++;
    printf("Desea ingresar otro alumno? s/n\n" );
    fflush(stdin);
    scanf(" %c",&control);
  }
  return i;
}

void mostrarArreglosParalelos(int matricula[], char nombre[][maxC], int validos){
  for(int i = 0;i<validos;i++){
    printf("Nombre: %s\n",nombre[i]);
    printf("Matricula: %i\n",matricula[i] );
  }
}

//Funcion del ejercicio 2
int buscarMatricula(int matricula[], int validos, int dato){
  int i=0;
  while(i<validos&&matricula[i]!=dato){
    i++;
  }
  return i;
}

//Funcion del ejercicio 3
void imprimirNombre(int matricula[],char nombre[][maxC], int validos){
  int dato=0;

  printf("Ingrese un numero de matricula para buscar:\n" );
  fflush(stdin);
  scanf("%i",&dato );
  printf("El nombre que corresponde a la matricula es: %s\n",nombre[dato]);
}

//Funcion del ejercicio 4
void insertarOrdenado(char nombre[], int matricula[], int validos, char nombreNuevo[], int matNueva){
  int i=validos;
  while(i<=0&&strcmp(nombre[i],nombreNuevo)<0){
    matricula[i+1]=matricula[i];
    strcpy(nombre[i+1],nombre[i]);
    i--;
  }
  strcpy(nombre[i+1],nombreNuevo);
  matricula[i+1] = matNueva;
}

//Funcion del ejercicio 5
int cargaStruct(alumno a[],int maxDim){
  int i = 0;
  char control = 's';
  while(i<maxDim&&control == 's'){
    printf("Ingrese el numero de matricula\n" );
    fflush(stdin);
    scanf("%i",&a[i].matricula );
    printf("Ingrese el nombre del alumno\n" );
    fflush(stdin);
    scanf("%s",a[i].nombre);
    printf("Ingrese el genero m/f\n" );
    fflush(stdin);
    scanf(" %c",&a[i].sexo );
    while(a[i].sexo!='m'&&a[i].sexo!='f'){
      printf("Genero erroneo, ingrese una m para masculino, f para femenino\n" );
      fflush(stdin);
      scanf(" %c",&a[i].sexo );
    }
    printf("Desea agregar un alumno nuevo? s/n\n");
    fflush(stdin);
    scanf(" %c",&control );
    i++;
  }
  return i;
}

void mostrarStruct(alumno a[],int validos){
  printf("\nLISTADO DE ALUMNOS\n\n");
  for(int i=0;i<validos;i++){
    printf("NOMBRE: %s\n",a[i].nombre );
    printf("MATRICULA: %i\n",a[i].matricula );
    printf("SEXO: %c\n\n",a[i].sexo );
  }
}
//Funcion del ejercicio 6
int verificar(alumno a[],int validos, int matricula){
  int flag = 0;
  int i=0;
  while(i<validos&&flag==0){
    if(a[i].matricula==matricula){
      flag = 1;
    }
    i++;
  }
  return flag;
}

int buscarPosicion(alumno a[],int validos, int matricula){
  int i =0;
  while(a[i].matricula!=matricula){
    i++;
  }
  return i;
}

void mostrarNombreXMatricula(alumno a[], int validos){
  int matricula,pos;
  printf("Ingrese la matricula a buscar\n");
  fflush(stdin);
  scanf("%i",&matricula);
  while(verificar(a,validos,matricula)==0){
    printf("La matricula ingresada no existe, ingrese una matricula valida\n" );
    fflush(stdin);
    scanf("%i",&matricula);
  }
  pos = buscarPosicion(a,validos,matricula);
  printf("La matricula %i, corresponde al alumno %s, de sexo %c\n",a[pos].matricula,a[pos].nombre,a[pos].sexo );
}

//Funcion del ejercicio 7
int buscarMenor(alumno a[],int validos, int desde){
  int pos = desde;
  for( int i = desde;i<validos;i++){
    if(a[pos].matricula>a[i].matricula){
      pos = i;
    }
  }
  return pos;
}

void ordenarXMatricula(alumno a[],int validos){
  alumno aux[1];
  int mat,pos;
  char s;
  for(int i = 0; i<validos;i++){
    pos=buscarMenor(a,validos,i);
    aux[0]=a[i];
    a[i]=a[pos];
    a[pos]=aux[0];
  }
}

int main() {
  int matricula[maxDim];
  char nombre[maxDim][maxC];
  int validos, posicion;
  alumno a[maxDim];

  //validos = cargaParalela(matricula,nombre,maxDim);
  //mostrarArreglosParalelos(matricula,nombre,validos);
  //posicion = buscarMatricula(matricula,validos,2);
  //printf("La posicion buscada es la numero %i\n",posicion );
  //imprimirNombre(matricula,nombre,validos);// NO ANDA
  //insertarOrdenado(nombre,matricula,validos,"ana",348);
  //validos++;
  //mostrarArreglosParalelos(matricula,nombre,validos);
  validos = cargaStruct(a,maxDim);
  //mostrarNombreXMatricula(a,validos);
  ordenarXMatricula(a,validos);
  mostrarStruct(a,validos);
  return 0;
}
