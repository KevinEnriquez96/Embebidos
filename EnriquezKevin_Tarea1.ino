/*
 * Nombre: Kevin Enriquez
 * Tutor: Paul Rosero
 * Tema: Introduccion a Machine Learning, empleando las funcionalidades de Knn
 * 
 */
#include "matriz_entrenamiento.h"
float matriz_prueba [5]={7.7,3.8,6.7,2.2,3}; // datos de prueba para el sistema
void setup() {

  Serial.begin (9600) ; //Tasa de transmision de bits
}
void loop() {

  int opcion=knn (90,5,9,3)  ;

  if (opcion==1) {
      Serial.println ("Iris Setosa") ;
      Serial.print ("Largo del Sepalo: ") ;
      Serial.println (matriz_prueba[0]) ; 
      Serial.print ("Ancho del Sepalo: ") ;
      Serial.println (matriz_prueba[1]) ;
      Serial.print ("Largo del Petalo: ") ;
      Serial.println (matriz_prueba[2]) ;
      Serial.print ("Ancho del Petalo: ") ;
      Serial.println (matriz_prueba[3]) ;
      delay (2000) ;
    } else if (opcion==2) {
      Serial.println ("Iris Versicolor") ;
      Serial.print ("Largo del Sepalo: ") ;
      Serial.println (matriz_prueba[0]) ; 
      Serial.print ("Ancho del Sepalo: ") ;
      Serial.println (matriz_prueba[1]) ;
      Serial.print ("Largo del Petalo: ") ;
      Serial.println (matriz_prueba[2]) ;
      Serial.print ("Ancho del Petalo: ") ;
      Serial.println (matriz_prueba[3]) ;
      delay (2000) ;
    }else if (opcion==3) {
      Serial.println ("Iris Virginica") ;
      Serial.print ("Largo del Sepalo: ") ;
      Serial.println (matriz_prueba[0]) ; 
      Serial.print ("Ancho del Sepalo: ") ;
      Serial.println (matriz_prueba[1]) ;
      Serial.print ("Largo del Petalo: ") ;
      Serial.println (matriz_prueba[2]) ;
      Serial.print ("Ancho del Petalo: ") ;
      Serial.println (matriz_prueba[3]) ;
      delay (2000) ;
      
      }
}

int knn (int fil, int columna, int vecinos, int etiquetas){
int col; 
int fila=0; 
float sumatoria=0; //Variable que alberga la sumatoria de diferencia de cuadradados entre dos putnos
float distancia; // Variable que alberga la distancia Euclideana
float matriz_k [2][vecinos]; //Matriz que alberga los vecinos
int i=0; 
int j;
float etiqueta; // Valor que retorna del método Knn
float mayor=0;
float aux ;
float aux1; // variables auxiliares para ordenamiento del vector
float matriz_etiquetas [2][etiquetas];//Matriz que alberga las etiquetas
  /*
   * Matriz de k-vecinos
   * [1][2][3]---------->numero de vecinos
   * [0.1][0.2][0.3]--> dsitancia
   * [2][1][1]---------->asignacion del vecino por Etiquetas
   *  
   */
for(;i<vecinos;i++){  //Matriz que alberga el numero de vecinos y se encera
     matriz_k[0][i]=3000+i; 
     matriz_k[1][i]=0; 
        /*
       * [1][2][3]
       * [0][0][0]
       * [3001][3002][3003]
       */    
  }
  i=0;
  for(;i<etiquetas;i++){ //Asignar etiquetas y se encera el contador
    matriz_etiquetas[0][i]= i+1; 
    matriz_etiquetas[1][i]= 0;  
      /*
     * [1][2][3]
     * [0][0][0]
     */ 
    }
   i=0; 
  /*
   * PASOS PARA K-NN
   * leer cada fila de la matriz de entrenamiento
   * distancia entre la fila de la matriz con la nueva instancia (vector de prueba)
   * ordenar la matriz_K (determinar los k vecinas e menor instancia
   * contar las etiquetas en la matrizK y asignar en matriz etiquetas
   * eligir al mayor número de matriz etiquetas
   * retorno la etiqueta resultante
   */
   for(;fila<fil;fila++){ // ciclo de lectura de filas
        for(col=0;col<columna-1;col++){ //-1 por que ultima columna es la etiqueta
          sumatoria=sumatoria+pow(matriz_prueba[col]-matriz[fila][col],2); //Diferencia de cuadrados entre dos puntos
          }
          distancia=sqrt(sumatoria); //Variable que alberga la distancia Euclidiana
          sumatoria=0;  // reinicio de variable para siguiente lectura 
           //comparacion de nuevo dato con solo la distancia mayor almacenada en matriz_k
          if(distancia<matriz_k[0][vecinos-1]){
             matriz_k[0][vecinos-1]=distancia;
             matriz_k[1][vecinos-1]=matriz[fila][columna-1];
            }
            // ordenamiento del vector de menor a mayor utilizando el metodo "BURBUJA"
          for(i=0;i<vecinos;i++){
               for(j=i+1;j<vecinos;j++){
                    if(matriz_k[0][i]>matriz_k[0][j]){
                       aux=matriz_k[0][i];
                       matriz_k[0][i]=matriz_k[0][j];
                       matriz_k[0][j]=aux;
                       //etiquetas
                       aux1=matriz_k[1][i];
                       matriz_k[1][i]=matriz_k[1][j];
                       matriz_k[1][j]=aux1;
                      }
                }
            }  
    }
     //Asignacion de la etiqueta
     for(i=0;i<etiquetas;i++){
          for(j=0;j<vecinos;j++){
               if(matriz_etiquetas[0][i]==matriz_k[1][j]){
                  matriz_etiquetas[1][i]=1+matriz_etiquetas[1][i];
                }
            }
      }
      
   for(i=0;i<etiquetas;i++){
       if(matriz_etiquetas[1][i]>mayor){//Condición para evaluar y asignar la etiqueta
         mayor=matriz_etiquetas[1][i];
         etiqueta=matriz_etiquetas[0][i]; //Variable que retorna la función KNN
        }
    }
    
   return etiqueta; 
  
}
