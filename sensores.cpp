#include "sensores.h"
#include <cstdlib>
#include <ctime>

bool hayVehiculoDelante() {
    return true;
}

bool hayPersonaFrente() {
    return true;
}

bool obstaculoLateralIzq() {
    return true;
}

bool obstaculoLateralDer() {
    return true;
}

bool terrenoResbaloso() {
    return true;
}

bool zonaProhibida() {
    return true;
}

int generarRiesgoAleatorio() {
    return rand() % 6;
}