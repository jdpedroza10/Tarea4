#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
//Solucionar la ecuacion de movimiento de un proyectil para el caso en que hay una friccion proporcional a v2 

float a_x(float v_x, float v_y){
	float a_x=-v_x*pow((v_x*v_x+v_y*v_y),0.5);
	return a_x;
}
float a_y(float v_x, float v_y){
	float a_y=-10-v_y*pow((v_x*v_x+v_y*v_y),0.5);
	return a_y;
}
int main(){
	//declarar algunas variables:
	float tht=3.1415/4;//angulo respecto a la horizontal
	float x=0; float y=0; float v_x=300*cos(tht); float v_y=300*sin(tht); float v_x_next, v_y_next, ax, ay; float dt=0.001; float i, t;float x_max, tht_max;
	//inicializar el problema:
	ax=a_x(v_x,v_y);ay=a_y(v_x,v_y);
	//calculamos las velocidades en t=0-dt/2
	v_x_next=v_x-ax*dt/2; v_y_next=v_y-ay*dt/2;
	//un archivo para guadar los datos:
	ofstream a_45("@45°.txt");
	i=0;t=0;
	while (y>=0){
		ax=a_x(v_x,v_y);ay=a_y(v_x,v_y);//se calculan las aceleraciones:
		v_x_next=v_x_next+ax*dt; v_y_next=v_y_next+ay*dt;//se actualizan las velocidades en t+dt/2;
		x=x+v_x_next*dt;y=y+v_y_next*dt;//se actualizan las posiciones;
		v_x=v_x_next+ax*dt/2;v_y=v_y_next+ay*dt/2;//se calculan las velocidades en t;
		i+=1;
		t=dt*i;
		a_45<<t<<","<<x<<","<<y<<","<<v_x<<","<<v_y<<"\n";
		
	}
	cout<<"la distancia alcanzada es "<<x<<"\n";
	x_max=x;
	tht_max=45;
	//segunda parte:
	//creamos un vector de char para guardar los nombres de los archivos:
	char* nombres[7];
	nombres[0]="@10°.txt";nombres[1]="@20°.txt";nombres[2]="@30°.txt";nombres[3]="@40°.txt";nombres[4]="@50°.txt";nombres[5]="@60°.txt";nombres[6]="@70°.txt";
	//hacemos un bucle para calcular las dinamicas:
	for (int j=0;j<7;j=j+1){
		float tht_1=(10+10*j)*3.1415/180;
		ofstream segunda_parte(nombres[j]);
		float x=0; float y=0; float v_x=300*cos(tht_1); float v_y=300*sin(tht_1); float v_x_next, v_y_next, ax, ay; float dt=0.001; float i, t;
		//inicializar el problema:
		ax=a_x(v_x,v_y);ay=a_y(v_x,v_y);
		//calculamos las velocidades en t=0-dt/2
		v_x_next=v_x-ax*dt/2; v_y_next=v_y-ay*dt/2;
		//un archivo para guadar los datos:
		ofstream a_45("@45°.txt");
		i=0;t=0;
		while (y>=0){
			ax=a_x(v_x,v_y);ay=a_y(v_x,v_y);//se calculan las aceleraciones:
			v_x_next=v_x_next+ax*dt; v_y_next=v_y_next+ay*dt;//se actualizan las velcoidades en t+dt/2;
			x=x+v_x_next*dt;y=y+v_y_next*dt;//se actualizan las posiciones;
			v_x=v_x_next+ax*dt/2;v_y=v_y_next+ay*dt/2;//se calculan las velocidades en t;
			i+=1;
			t=dt*i;
			segunda_parte<<t<<","<<x<<","<<y<<","<<v_x<<","<<v_y<<"\n";
			
		}
		//buscar el maximo:
		if (x>x_max){
			x_max=x;
			tht_max=10+10*j;
		}
		//cout<<tht_max<<"\n";
	}
	//imprimir el mensaje:
	cout<<"el angulo con mayor alcance es "<<tht_max<<"\n";
	return 0;
}
	







