/*
 * Estudiante: Enriquez Kevin
 * Tutor: Paul Rosero
 * Tema: CNN
 */



#import "matriz_ingresada.h"
int condicion=3000; //Condicion para asignar etiquetas
int fin =0 ; //Variable para no crear un bucle
int inicio=0; //Variable para no crear un bucle 
float etiquetaNueva [120][1] ; //Vector Donde se designa la posición de la etiqueta que varia con la matriz original
boolean con=true ; //Condición logica para no crear un bucle en el loop
int numero ;


void setup() {
  // put your setup code here, to run once:
    Serial.begin (9600) ; //Transmisión de bits
}

void loop() {
  // put your main code here, to run repeatedly:
  while (con==true){ //Condición para no crear bucles
    cnn (3,5,120) ;
    con=false ;
  }
  

}
void cnn (int etiquetas, int columnas, int filas) {
  float centroide [columnas][filas] ; //Vector donde se desginan los centroides de la mariz
  float promedio ; //Variable que alberga el valor del promedio del valor de los centroides
  int i ; //Variable para designar el conteo del ciclo for
  int j ; //Variable para designar el conteo del ciclo for
  int p ; //Variable para designar el conteo del ciclo for
  int s ;
  int f ;
  int c ;
  float sumatoria =0 ; //Variable que alberga la sumatoria de las distancias
  float dist ; //Variable que alberga la distancia euclidiana entre los valores de la matriz de test con los valores de los centroides
    for (j=0;j<columnas;j++) { //Condición para encerar la matriz centroide
       for (i=0;i<filas;i++) {
            centroide [j][i]= 0 ;
       }
    }
                for (p=0 ;p<etiquetas;p++) { //Ciclo repetitivo y variable de las filas del vector centroide
                     for (j=0;j<columnas-1;j++) {//Ciclo repetitivo para desplazar columnas
                         for (i=(40*p);i<(40)*(p+1);i++) { // Ciclo repetitivo para desplazar filas
                                 promedio=promedio+matriz[i][j] ; //Operacion matematica para sumar las posiciones de la matriz de test
      }
                           promedio=promedio/40 ; //Operacion matematica para sacar el promedio de dicha sumatoria
                           centroide [p][j]=promedio ; //Almacenamiento de los valores de promedio en la matriz centroide
                           centroide [p][4]=p+1 ; //Asignación de la etiqueta
                           //Serial.println (centroide [p][4]) ;
                           promedio=0 ;
    }
                }
      for (i=0;i<filas;i++) { //Desplazamiento de filas
         for (j=0;j<columnas-2;j++) { //Desplazamiento de columnas
             for (p=0;p<4;p++) { //Desplazamiento de etiquetas
                sumatoria=sumatoria+pow(matriz[i][p]-centroide[j][p],2) ; //Sumatoria Euclideana
         }           
                dist=sqrt (sumatoria) ; //Distancia Euclideana entre los puntos de la matriz con los puntos de la matriz centroides
               // Serial.println (dist) ;
                 sumatoria=0 ;
                
                if (condicion>dist) { //Condicion para asignar las etiquetas que serán empleadas para descechar elementos
                  condicion=dist ;
                  etiquetaNueva[i][1]=centroide[j][4]; //Asignación del valor de la etiqueta 
                  
                } 
              }
              condicion=3000 ;
            }
             Serial.println ("POSICIONES DEL VECTOR QUE NO COINCIDEN CON EL NUMERO DE ETIQUETA") ;
            int connt ;
              for (i=0;i<120;i++) {
                if (etiquetaNueva[i][1]!=matriz[i][4]) { //Condición para mirar errores en la etiqueta
                    Serial.println (i) ;
                        centroide[i][4]=matriz[i][4] ; //Asignacion del valor orignal de la etiqueta 
                          numero=1 ;
                            int num[numero] ;//vector que guardar las posiciones donde se genera
                                numero++;//aumento el numero de los errores
                                    num[numero-1]=i;//Se llena el vector con las posiciones de donde encuentra el error
                                        float matrizNueva[numero + etiquetas ][columnas];//se declara la nueva matriz
                                              for (int w = 0; w <=s; w++) {//se recorre en base al numero de s encontrados
                                                    for (int f = 0; f < s + etiquetas; f++) { 
                                                        for (int c = 0; c < columnas; c++) {
                                                                 matrizNueva[f][c] = centroide[f][c];//se llena con los centroides 
                                                                      matrizNueva[etiquetas][c] = matriz[num[numero-1]][c];//se llena con la fila donde existe el error  
     
      }
      Serial.println(' ');
    }
          for (int f = 0; f < s+etiquetas; f++) {
        for (int c = 0; c < columnas; c++) {
          Serial.print(matrizNueva[f][c]);
          Serial.print(' ');
        }
        Serial.println(' ');
      }
  }
 }    
}
}
