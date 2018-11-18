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
	for (int i=0;i<36;i++){
		meshgrid<<x[i]<<","<<y[i]<<"\n";
	}
	//CASO #1: T EXTERNA CONSTANTE=10 grados
	//primero asignamos cero a todo el dominio:
	for(int i=0;i<36;i++){
		T[i]=0;
	}
	//construccion paredes con 10 grados:
	for (int i=0;i<6;i++){
		T[i]=10;T[6*i]=10;
	}
	ofstream solution_1("solution_1.txt");
	//las paredes del clindro estan a T=100°:
	T[34]=100;T[35]=100;T[29]=100;
	//Solution:
	for(int ts=0;ts<10000;ts++){//bucle para ejecutar los pasos de tiempo:
		//1) los nodos internos:
		for(int i=0;i<5;i++){//avace sobre las filas;
			for(int j=0;j<5;j++){//avance sobre las columnas:
				T_t_plus_dt[7+j+6*i]=T_i_plus_1(T,7+j+6*i,factor,0);
			}
		}
		//los nodos de las simetrias derecha y superior:
		for (int i=0;i<3;i++){
			T_t_plus_dt[11+6*i]=T_i_plus_1(T,11+6*i,factor,1);
			T_t_plus_dt[31+i]=T_i_plus_1(T,31+i,factor,2);
		}
		//actualizar los datos de T
		for(int i=0;i<35;i++){
			T[i]=T_t_plus_dt[i];
		}
		//reestablecer las condiciones de frontera:
		for (int i=0;i<6;i++){
			T[i]=10;T[6*i]=10;
		}
		//las paredes del clindro estan a T=100°:
		T[34]=100;T[35]=100;T[29]=100;
		//exportar los datos de las temperaturas:
		for(int i=0;i<36;i++){
			solution_1<<T[i]<<",";	
		}
		solution_1<<"\n";
	}
	//CASO #2: PAREDES ABIERTAS:
	ofstream solution_2("solution_2.txt");
	//primero asignamos cero a todo el dominio:
	for(int i=0;i<36;i++){
		T[i]=0;
	}
	//las paredes del clindro estan a T=100 grados:
	T[34]=100;T[35]=100;T[29]=100;
	for(int ts=0;ts<100000;ts++){//bucle para ejecutar los pasos de tiempo:
		//1) los nodos internos:
		for(int i=0;i<5;i++){//avace sobre las filas;
			for(int j=0;j<5;j++){//avance sobre las columnas:
				T_t_plus_dt[7+j+6*i]=T_i_plus_1(T,7+j+6*i,factor,0);
			}
		}
		//los nodos de las simetrias derecha y superior:
		for (int i=0;i<3;i++){
			T_t_plus_dt[11+6*i]=T_i_plus_1(T,11+6*i,factor,1);
			T_t_plus_dt[31+i]=T_i_plus_1(T,31+i,factor,2);
		}
		//igualar las temperaturas en las paredes abiertas a las de sus vecinos:
		for (int i =1;i<6;i++){
			T_t_plus_dt[i]=T_t_plus_dt[i+6];
			T_t_plus_dt[i*6]=T_t_plus_dt[i*6+1];
		}
		T_t_plus_dt[0]=T_t_plus_dt[1];
		//actualizar los datos de T
		for(int i=0;i<35;i++){
			T[i]=T_t_plus_dt[i];
		}
		//reestablecer las condiciones de frontera:
		//las paredes del clindro estan a T=100 grados:
		T[34]=100;T[35]=100;T[29]=100;
		//exportar los datos de las temperaturas:
		for(int i=0;i<36;i++){
			solution_2<<T[i]<<",";	
		}
		solution_2<<"\n";
	}
	//CASO 3: FRONTERAS PERIODICAS: COMO APLICAMOS SIMETRIAS, ESTA CONDICION ES EQUIVALENTE A OTRA SIMETRIA, POR LO QUE EL DOMINIO QUEDA RODEADO DE SIMETRIAS 
	//POR TODAS PARTES:
	ofstream solution_3("solution_3.txt");
	d_t=10;
	factor=d_t*k/(dens*cp*d_x*d_x);
	//primero asignamos cero a todo el dominio:
	for(int i=0;i<36;i++){
		T[i]=0;
	}
	//las paredes del clindro estan a T=100 grados:
	T[34]=100;T[35]=100;T[29]=100;
	for(int ts=0;ts<100000;ts++){//bucle para ejecutar los pasos de tiempo:
		//1) los nodos internos:
		for(int i=0;i<5;i++){//avace sobre las filas;
			for(int j=0;j<5;j++){//avance sobre las columnas:
				T_t_plus_dt[7+j+6*i]=T_i_plus_1(T,7+j+6*i,factor,0);
			}
		}
		//los nodos de las simetrias derecha y superior:
		for (int i=0;i<3;i++){
			T_t_plus_dt[11+6*i]=T_i_plus_1(T,11+6*i,factor,1);
			T_t_plus_dt[31+i]=T_i_plus_1(T,31+i,factor,2);
		}
		//los nodos de las simetrias inferior y superior:
		for(int i=1;i<5;i++){
			T_t_plus_dt[i]=T_i_plus_1(T,i,factor,4);//simetria inferior
			T_t_plus_dt[i*6]=T_i_plus_1(T,i*6,factor,3);
		}
		//vertices 
		T_t_plus_dt[0]=T_i_plus_1(T,0,factor,6);
		T_t_plus_dt[5]=T_i_plus_1(T,5,factor,5);
		T_t_plus_dt[30]=T_i_plus_1(T,30,factor,7);
		//actualizar los datos de T
		for(int i=0;i<35;i++){
			T[i]=T_t_plus_dt[i];
		}
		//las paredes del clindro estan a T=100 grados:
		T[34]=100;T[35]=100;T[29]=100;
		//exportar los datos de las temperaturas:
		for(int i=0;i<36;i++){
			solution_3<<T[i]<<",";	
		}
		solution_3<<"\n";
	}

	
	return 0;
}





