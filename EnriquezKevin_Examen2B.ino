#include "matrizDrop3.h" //Metodo para llamar a la matriz
#define filas 44 //Definición de la variable filas para realizar las funciones de los ciclos
#define columnas 4 // Definición de la variable columnas para realizar las funciones de los ciclos
int n = 3 ; ////Numero de entradas en este caso son dadas por los 3 sensores
float vPesos [3] ; //Vector donde se alejan los valores de los pesos para realizar las operaciones dentro de la neurona
float funcion[filas] ;//Vector donde se alojan los valores de la multiplicacion de los valores de la matriz con los pesos
float prediccion [filas] ; //Vector donde se alojan los valores 1 y 0
float error [filas] ; //Vector donde se alojarán el valor de los errores
int contador = 0 ;//Variable que almacena el número de rrores
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600) ;


}

void loop() {
  // put your main code here, to run repeatedly:
  //Randomización de los pesos
  contador = 0 ;
  for (int n = 0 ; n < 3 ; n++) { //Función para determinar aleatoriamente los valores de los pesos
    vPesos[n] = (float)random(-1000, 1000) / 1000 ; //Condicion para obtener valores en la magnitud de decimales

  }
  //Ecuacion del sistema de la forma: F(x)= matrizDrop3[0][1]*pesos [1]+ matrizDrop3[0][2]*pesos [2] +matrizDrop3[0][3]*pesos[3]
  for (int k = 0 ; k < filas; k++) { //Ciclo que se mueve en las filas de la matriz
    for (int j = 0 ; j < 3; j++) { //Ciclo que se mueve en las filas del vector
      funcion [k] = (matriz[k][0] * vPesos[j]) + (matriz[k][1] * vPesos[j]) + (matriz[k][2] * vPesos[j]) ;
    }
  }
  for (int p = 0 ; p < filas; p++) { //Condición para asginar la prediccion de la etiqueta

    if (funcion[p] >= 0 ) { //Si el valor de la sumatoria es mayor a 0 se asigna el estado 1
      prediccion[p] = 1 ;
    } else if (funcion[p] < 0) { //Si el valor de la sumatoria es menor a 0 se asigna el estado 0
      prediccion[p] = 0;
    }
  }
  //Ciclo FOR para asignar el error
  for (int y = 0 ; y < filas; y++) {

    error [y] = matriz[y][3] - prediccion[y]; //Operación para encontrar la dierencia del valor al que se quiere llegar (etiqueta) menos la prediccion encontrada
  }

  for (int m = 0; m < filas; m++) {//Ciclo for para cuantizar el error producido

    if (error[m] == 0)
    {

    } else
      contador++;
  }
  //Condición para encontrar la menor cantidad de errores

  Serial.print ("Numero de errores: ") ;
  Serial.println (contador) ;
  Serial.print ("Valor del Peso 1:  ") ;
  Serial.println (vPesos[0]) ;
  Serial.print ("Valor del Peso 2:  ") ;
  Serial.println (vPesos[1]) ;
  Serial.print ("Valor del Peso 3:  ") ;
  Serial.println (vPesos[2]) ;
  delay (500) ;
  while (contador <= 21) { //Condición para encontrar el minimo error

    Serial.print ("Numero de errores: ") ;
    Serial.println (contador) ;
    Serial.print ("Valor del Peso 1:  ") ;
    Serial.println (vPesos[0]) ;
    Serial.print ("Valor del Peso 2:  ") ;
    Serial.println (vPesos[1]) ;
    Serial.print ("Valor del Peso 3:  ") ;
    Serial.println (vPesos[2]) ;


  }

}
