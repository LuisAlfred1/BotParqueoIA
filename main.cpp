#include<iostream>
#include <cstdlib>
#include <ctime>
#include "ia.h"

using namespace std;

int main() {
    srand(time(nullptr));
    
    cout << "=================================" << endl;
    cout << "Bot de Parqueo iniciado..." << endl;
    cout << "=================================" << endl;
    
    const int iteraciones = 5;
    
    for (int i = 1; i <= iteraciones; i++) {
        cout << "\n--- Iteracion " << i << " ---" << endl;
        procesarDecision();
        cout << endl;
    }
    
    cout << "=================================" << endl;
    cout << "Proceso completado." << endl;
    cout << "=================================" << endl;
    
    return 0;
}
