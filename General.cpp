#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

#define NUM_HISTORIAS 1000
#define NUM_HORAS 500

float f(int i){  //función f
 if(0 <= i && i <= NUM_HORAS){
 	return exp(-i/1);
 }
 else{
 	return 0;
 }
}


int main()
{
  int i, seed=134567, hora, bingo, muestra;
  float r, norm=0;
  float pdf[NUM_HORAS];
  
  for(i=0; i<=NUM_HORAS; ++i){
  	//std::cout<<i<<"\t"<<"\t"<<f(i)<<"\t"<<norm<<std::endl; //en caso de que no cuadren cuentas...
   	norm = norm + f(i);
   	
   	}
   
  
  for(i=0;i<=NUM_HORAS;++i){
  	pdf[i] = f(i)/norm;
  }
  float sum=0, F[NUM_HORAS+1];
  float histogram[NUM_HORAS+1];

   
  // inicializacion de histogram[]
  for (i=0;i<=NUM_HORAS; ++i)
    histogram[i]=0;

  // Funcion acumulativa F[i]
  for (i=0; i<=NUM_HORAS; ++i){
    sum += pdf[i];
    F[i] = sum;
  }
   
 
   //checkeo en la terminal de que mi función de densidad está normalizada.
  for(i=1;i<=NUM_HORAS;++i){
  
   	std::cout<<i<<"\t"<<f(i)<<"\t"<<f(i)/norm <<"\t"<<pdf[i]<<"\t"<<F[i]<<std::endl;
   }
   std::cout<<norm<<std::endl;
   
  
  
 
   
   // inicializacion de la secuencia de numeros aleatorios
  srand(seed);

  // Monte Carlo lanza NUM_HISTORIAS de veces el dado.
  // Cada vez el contador del lado resultante 'bingo' es incrementado
  // en 'histogram[bingo] += 1'
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
  // Nos enteramos del resultado del juego...
  
std::ofstream myfile;
myfile.open ("general.txt");
	for (i=1; i<=NUM_HORAS; ++i){
		myfile << i <<"\t"<< histogram[i]<<"\t"<< pdf[i]<< std::endl;
	}
    
myfile.close();
  
  

 
  return 0;
}
