/*
 * Metodo Bayes
 * Nombre: Kevin Enriquez
 * *********************************SIN TERMINAR
 * 
 * P(1)
 * p(2)
 * P(3)
 * 
 * P(x)=sumatoria ddde los elementos dentro de la circunferencia y dividir para el total de filas
 *      Encontrar la circunferencia
 *                >Distancia entre la nueva instancia y la base de datos
 *                >Encuentro la mayor distancia y divido para el reto de las
 *                distancias encontradas
 *                >Define el radio de la circunferencia (0,1)
 *                >Seleccionar las filas que senceutnra dentro de la circunferencia
 * P(x/1)= Sumatoria de todos los elementos que se encuentran dentro de la circunferencia con etiqueta 1              
 *         Y se divide para tods las instancias de la misma etiqueta
 * P(x/2)= Sumatoria de todos los elementos que se encuentran dentro de la circunferencia con etiqueta 2            
 *         Y se divide para tods las instancias de la misma etiqueta
 * P(x/3)= Sumatoria de todos los elementos que se encuentran dentro de la circunferencia con etiqueta 3    
 *         Y se divide para tods las instancias de la misma etiqueta     
 * P(1/X)=P(1)*P(x/1)/p(x)
 * P(2/X)=P(2)*P(x/2)/p(x)
 * P(3/X)=P(3)*P(x/3)/p(x)
 * 
 * Encontrar la probabilidada mas alta  asignar etiqueta.
 */
 #include "matriz_ingresada.h"
float datos_prueba[5]={4.4,2.9,1.4,0.2,1};

void setup() {
  Serial.begin (9600) ;

}

void loop() {
  // put your main code here, to run repeatedly:
  int estado ;
    estado=bayesiano (3,5,120,5) ;

    
}
int bayesiano (int etiquetas, int columnas, int filas, float r) {
/*
 * |1                 |2               |3           
 * |sum1              |sum2            |sum3
 * |p(x/1)            |p(x/2)          |p(x/3)
 * |p(1/x)        )   |p(2/x)          |p(3/x)
 */
int count ;
int valetiq = 0;
int resul;
int countp = 0;
float distancia = 0;
float distanciam = 0.1;
int i=0 ;
int j=0 ;
int k=0 ;
float suma = 0;
  float matrizb[4][etiquetas];
  float numetiq[etiquetas ];
  float norma[120];
    for (i = 0; i < 4; i++) {//lenado de ceros de la matriz de trabajo .
    for (j = 0; j < etiquetas; j++) {
      matrizb[i][j] = 0;
    }
  }
  for (i = 0; i < 120; i++) {//calculo de distancia euclideana
    for (j= 0; j < 4 ; j++) {
      suma = suma + pow(matriz[i][j] - datos_prueba[j], 2);
    }
    distancia = sqrt(suma);//Se eslige distancia Mayor
    if (distancia > distanciam) {
      distanciam = distancia;
    }
    distancia = 0;
    suma = 0;
  }
 
}
