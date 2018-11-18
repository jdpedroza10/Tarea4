#include<iostream>
#include<math.h>

using namespace std;



int main (){
	//los datos del problema:
	float k=1.62;
	float cp=820;
	float dens=2710;
	float d_x=0.05;
	float d_t=3;
	float factor=d_t*k/(dens*cp*d_x*d_x);
	//generamos el enmallado:
	float x[36];
	float y[36];
	float T[36];
	float T_t_plus_dt[36];
	for (int i=0;i<6;i++){//avace vertical
		for(int j=0;j<6;j++){//avance horizontal
			x[j+6*i]=d_x*j;
			y[j+6*i]=d_x*i;
		}
	}
	x[35]=0.215;y[35]=0.215;
	//exportar las coordenadas de los puntos generados anteriormente
	ofstream meshgrid("meshgrid.txt");





