#include "ia.h"
#include "sensores.h"
#include "acciones.h"
/*Lo puedes hacer a traves de un switch case, pero para que sea mas legible, lo he hecho de esta manera*/
void procesarDecision(){
    switch(detectarRiesgo()){
        case 0:
            frenar();
            break;
        case 1:
            girarIzquierda();
            break;
        case 2:
            girarIzquierda();
            break;
        case 3:
            girarDerecha();
            break;
        case 4:
            retroceder();
            break;
        case 5:
            activarAlerta();
            break;
        case 6:
            buscarRutaAlterna();
            break;
        default:
            break;
    }
}

int detectarRiesgo(){
    return generarRiesgoAleatorio();
}
