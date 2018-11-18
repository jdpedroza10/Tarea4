#include<iostream>
#include<math.h>

using namespace std;

//funcion para calcular las temperaturas:
float T_i_plus_1(float T[], int index, float factor,int opcion){
	float T_calc;
	if( opcion==0){
		//nodo interno:
		T_calc=T[index]+factor*(-4*T[index]+T[index+1]+T[index-1]+T[index+6]+T[index-6]);
		return T_calc;
	}
	else if(opcion==1){
		//nodo borde derecho:
		T_calc=T[index]+factor*(-4*T[index]+2*T[index-1]+T[index+6]+T[index-6]);
		return T_calc;
	}
	else if(opcion==2){//nodo borde superior:
		T_calc=T[index]+factor*(-4*T[index]+2*T[index-6]+T[index+1]+T[index-1]);
		return T_calc;
	}
	else if(opcion==3){//nodo borde izquierdo:
		T_calc=T[index]+factor*(-4*T[index]+2*T[index+1]+T[index+6]+T[index-6]);
		return T_calc;	
	}
	else if(opcion==4){//nodo borde inferior.
		T_calc=T[index]+factor*(-4*T[index]+2*T[index+6]+T[index+1]+T[index-1]);
		return T_calc;		
	}
	else if (opcion==5){//nodo esquina inferior derecha:
		T_calc=T[index]+factor*(-4*T[index]+2*T[index+6]+2*T[index-1]);
		return T_calc;
	}
	else if(opcion==6){//esquina inferior izquierda:
		T_calc=T[index]+factor*(-4*T[index]+2*T[index+6]+2*T[index+1]);
		return T_calc;
	}
	else if (opcion==7){//esquina superior izquierda
		T_calc=T[index]+factor*(-4*T[index]+2*T[index+1]+2*T[index-6]);
		return T_calc;
	}
	
}

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





