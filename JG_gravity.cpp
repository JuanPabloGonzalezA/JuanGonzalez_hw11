#include <iostream>
using namespace std;

double G;
double M;
double xpunto(double x, double v);
double vpunto(double x, double v);
int main()
{
	//valor variables
	G=10;
	M = 1000;
	double m , x , v, dt;
	x=100;
	v=0;
	dt=100.0/2000000.0;
	/*
	//ingreso de datos: 
	cout<<"Ingrese la masa m:"<<endl;
	cin>>m;
	cout<<"Ingrese la posicion inicial x:"<<endl;
	cin>>x;
	cout<<"Ingrese la velocidad inicial v:"<<endl;
	cin>>v;
	cout<<"Ingrese dt"<<endl;
	cin>>dt;
	*/
	double t=0;//inicializo t en 0
	double xf=0.01*x;//defino el xf como el 1 porciento de xinicial
	
	//solucion de ecuacion diferencial
	double kx1, kx2, kx3, kx4, kv1, kv2, kv3, kv4;
	int Nmax=2000000;//si se pasa de las 2M de iteraciones, deja de correr
	int i;//contador de iteraciones
	i=0;//inizializo contador de iteraciones
	while(x>xf && i<Nmax)
	{
		kx1=xpunto(x,v);
		kv1=vpunto(x,v);
		kx2=xpunto(x+kx1*dt/2, v+kv1*dt/2);
		kv2=vpunto(x+kx1*dt/2, v+kv1*dt/2);
		kx3=xpunto(x+kx2*dt/2, v+kv2*dt/2);
		kv3=vpunto(x+kx2*dt/2, v+kv2*dt/2);
		kx4=xpunto(x+kx3*dt, v+kv3*dt);
		kv4=vpunto(x+kx3*dt, v+kv3*dt);
	
		t+=dt;
		x+=dt*(kx1+2*kx2+2*kx3+kx4)/6;
		v+=dt*(kv1+2*kv2+2*kv3+kv4)/6;
		cout<<x<<" "<<v<<" "<<t<<" "<<endl;	//imprimo
		i++;
	}
	return 0;
}
//funcion derivada de x
double xpunto(double x, double v)
{
	return v;
}
//funcion derivada de v
double vpunto(double x, double v)
{
	return -G*M/(x*x);
}
