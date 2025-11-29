#include "ia.h"
#include "sensores.h"
#include "acciones.h"
#include <iostream>
using namespace std;

void procesarDecision(){
    int tipoEvaluacion = detectarRiesgo();
    bool peligroDetectado = false;
    
    switch(tipoEvaluacion){
        case 0:
            cout <<"Evaluando sensor: Vehiculo delante" << endl;
            peligroDetectado = hayVehiculoDelante();
            break;
        case 1:
            cout <<"Evaluando sensor: Persona frente" << endl;
            peligroDetectado = hayPersonaFrente();
            break;
        case 2:
            cout <<"Evaluando sensor: Obstaculo lateral izquierdo" << endl;
            peligroDetectado = obstaculoLateralIzq();
            break;
        case 3:
            cout <<"Evaluando sensor: Obstaculo lateral derecho" << endl;
            peligroDetectado = obstaculoLateralDer();
            break;
        case 4:
            cout <<"Evaluando sensor: Terreno resbaloso" << endl;
            peligroDetectado = terrenoResbaloso();
            break;
        case 5:
            cout <<"Evaluando sensor: Zona prohibida" << endl;
            peligroDetectado = zonaProhibida();
            break;

        default:
            cout <<"No se ha detectado ningun peligro" << endl;
            break;
    }

    if(peligroDetectado){
        cout <<"Peligro detectado! Ejecutando accion..." << endl;
        switch(tipoEvaluacion){
            case 0: // Vehiculo delante
                frenar();
                activarAlerta();
                break;
            case 1: // Persona frente
                frenar();
                activarAlerta();
                break;
            case 2: // Obstaculo lateral izquierdo
                girarDerecha();
                break;
            case 3: // Obstaculo lateral derecho
                girarIzquierda();
                break;
            case 4: // Terreno resbaloso
                reducirVelocidad();
                break;
            case 5: // Zona prohibida
                buscarRutaAlterna();
                break;
            default:
                break;
        }
    } else {
        cout <<"Sin peligros detectados. Continuando..." << endl;
    }
}

int detectarRiesgo(){
    return generarRiesgoAleatorio();
}
