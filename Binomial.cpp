#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::ios;
using std::ofstream;




int main()
{
   
  int i,seed=134567, hora, bingo, muestra, NUM_HORAS=2;
  float r, t,delta_t=0.1,p=0.1,NUM_HISTORIAS = 10;
  float pdf[] = {0,1-p,p};
  float sum=0, F[NUM_HORAS+1];
  float histogram[NUM_HORAS+1];
  
  // inicializacion de histogram[]
  

  // Funcion acumulativa F[i]
  for (i=0; i<=NUM_HORAS; ++i){
    sum += pdf[i];
    F[i] = sum;
  }

  // inicializacion de la secuencia de numeros aleatorios
  srand(seed);

  // Monte Carlo lanza NUM_HISTORIAS de veces el dado.
  // Cada vez el contador del lado resultante 'bingo' es incrementado
  // en 'histogram[bingo] += 1'
  
 
  	ofstream myfile;
myfile.open ("parcial_10.txt"); 
  for(t=0;t<=1.4;t=t+delta_t){ //para cada t, cambiamos el n?mero de n?cleos totales y repetimos el experimento. Ponemos una condición que
  //siempre se cumple 1==1 para no definir a priori un t máximo y que se cierre el conteo con un break cuando el número de decaímientos
  // llegue a 0
  
      for (i=0;i<=NUM_HORAS; ++i){
      	histogram[i]=0;
	  }
    
  	 for (i=1; i<=NUM_HISTORIAS;++i){
         r=(float)rand()/((float)RAND_MAX+1);
         
          for(hora=1; hora<=NUM_HORAS; ++hora){

              if (r >= F[hora-1] && r < F[hora]){
	               bingo = hora;
	               histogram[bingo] += 1;
	               muestra+= 1;
	               break;
          }
     }
  }
  myfile << t << "\t"<< NUM_HISTORIAS <<"\t"<<histogram[1] << endl; //nos interesa en este caso la gráfica de 1:3 
  
 
  NUM_HISTORIAS = histogram[1];  //renovación del número de núcleos
  
 
  }
  
	
		
	
    
myfile.close();
  




  



 
  return 0;
}

