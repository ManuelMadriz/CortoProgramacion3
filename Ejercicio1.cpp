#include "iostream"

using namespace std;

double porcent(double, double); /*Funcion que calcula de un valor dado el porcentaje proporcionado*/
double stotal(double, double); /*Funcion que calcula el salario total segun las horas normales y extras trabajadas*/
double sreal(double); /*Funcion que calcula el salario real aplicando los descuentos*/

int main()
{
    int n;
    cout << endl << "Este programa te servira para calcular los salarios mensuales de los empleados que ingreses";
    cout << endl << "¿Cuantos empleados deseas ingresar?" << endl;
    cin >> n;

    /*Debido a que se pueden ingresar una cantidad variable de datos, veo necesario usar los siguientes arreglos.
    Ya que de no ser asi, solo se podria ingresar una cantidad fija de empleados*/
    string nombre[n];
    double sal_t[n];/*SALario Total*/
    double sal_r[n];/*SALario Real*/

    /*Las siguientes variables cambiaran su valor por cada empleado ingresado*/
    int i;/*Nuestro contador*/
    double hnl;/*Horas NormaLes*/
    double hex;/*Horas EXtras*/

    for (i = 0; i < n; i++) /*Se ingresaran hasta n empleados los datos solicitados*/
    {
        cout << endl << "Ingrese el nombre del empleado numero " << i+1 << endl;
        /*El i+1 es porque el contador empieza en 0, pero para el usuario seria mas comodo leer como primero
        empleado 1 que empleado 0. Lo mismo en las siguientes lineas*/
        cin >> nombre[i];

        cout << endl << "Ingrese las horas normales trabajadas por el empleado numero " << i+1 << endl ;
        cin >> hnl;

        cout << endl << "Ingrese las horas extras trabajadas por el empleado numero " << i+1 << endl;
        cin >> hex;

        /*A continuacion, se calculan los salarios*/
        sal_t[i] = stotal(hnl,hex);
        sal_r[i] = sreal(sal_t[i]);
    }

    cout << endl << "A continuacion, se mostraran los salarios calculados" << endl;
    
    for ( i = 0; i < n; i++)
    {
        cout  << endl  << nombre[i] << " tiene un salario total de $" << sal_t[i] << " y un salario real de $" << sal_r[i];
    }
}

/*A continuacion, la funcion que nos permite calcular rapidamente los porcentajes*/
double porcent(double ctd, double porcent)
{
    return ((ctd/100)*porcent);
}

/*A continuacion, la funcion que nos permite calcular el salario total*/
double stotal(double hnl, double hex)
{
    return (hnl*1.75 + hex*2.5);
}

/*A continuacion, la funcion que aplica los descuentos y nos permite calcular el salario real*/
double sreal(double sal)
{
    double sal_r; 
    
    sal_r = sal -(porcent(sal,4)+ porcent(sal,6.25));

    if(sal > 500)
    {
        sal_r -= porcent(sal,10);
    }

    return sal_r;
}