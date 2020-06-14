#include "iostream"
#include "cmath"
#include "ctime"

using namespace std;

int random(int);/*Funcion que usaremos para generar el numero aleatorio*/
string pista(int, int);/*Funcion con la que daremos pistas*/

int main()
{
    
int n_sec; /*En esta variable se guardara el Numero SECreto*/
    int resp; /*En esta variable guardaremos las RESPuestas que vaya dando el jugador*/
    int cont = 5; /*Esta variable sera el CONTador a los intentos del jugador*/

    n_sec = random(100);

    cout << endl << "Bienvenido a El Numero Magico. Intenta adivinar nuestro numero secreto que esta comprendido entre 1 y 100";
    cout << endl << "Si te aburres de jugar, solo ingresa 0" << endl;
    /*La tecla 0 sera lo que el jugador debe presionar cuando ya no quiera jugar*/

    do
    {
        cout << endl << "Tienes " << cont << " intentos";
        cout << endl << "Ingresa tu respuesta" << endl;
        cin >> resp;

        if (resp == 0)
        {
            cout << endl << "Te esperamos pronto!";
            cont = 0; /*Igualamos el contador a 0 para que no hayan mas iteraciones*/
        }

        else
        {
            if (resp == n_sec)
            {
                cout << endl  << "Correcto!!!";
                cout << endl << "Has ganado con " << 5 - cont << " intentos!!!";
                cont = 0; /*Igualamos el contador a 0 para que no hayan mas iteraciones*/
            }
            
            else
            {
                cout << endl  << "Has fallado";
                cont--;/*restamos uno al contador*/

                if(cont != 0)/*Se hace esta comprobacion para que el programa no de pistas,
                cuando losintentos ya hayan terminado*/
                {   
                    cout  << endl << pista(n_sec, resp) << endl;
                }
            }
        }
    } while (cont != 0 );
    
    if(resp != n_sec && resp != 0)
    /*El siguiente mensaje solo se mostrara cuando el jugador no haya ganado ni abandonado
    Es decir, cuando haya perdido*/
    {
        cout << endl << "Se te acabaron los intentos. Has perdido!!";
        cout << endl << "La respuesta era: " << n_sec << endl;
    }
    
}


int random(int n) /*Esta parte la saque de internet*/
{
    srand(time(NULL));
    /*El tiempo actual en segundos sera nuestra semilla inicial para la funcion rand*/

    return 1+rand()%100;
    /*El modulo entre el resultado de la funcion rand y n sera un nuemero entre 0 y n-1
    A ello le sumaremos 1 para que el resultado se encuentre entre 1 y n*/
}

string pista(int n_sec, int resp)
{
    string ret;
    if( n_sec <= resp)
    {
        return "Pista: Nuestro numero secreto es menor que el que has ingresado";
    }
    else
    {
        return "Pista: Nuestro numero secreto es mayor que el que has ingresado";
    }
}