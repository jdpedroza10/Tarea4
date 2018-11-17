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
	while
