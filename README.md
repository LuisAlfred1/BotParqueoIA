# Bot de Parqueo con IA Básica - Guía de Implementación

## 📋 Descripción del Proyecto

Este proyecto implementa un bot de parqueo autónomo con inteligencia artificial básica que puede detectar riesgos y obstáculos, y tomar decisiones automáticas para evitar colisiones y encontrar un espacio de parqueo seguro.

## 🏗️ Estructura del Proyecto

```
BotParqueo/
│
├── main.cpp          # Punto de entrada del programa
├── sensores.h        # Declaraciones de funciones de detección
├── sensores.cpp      # Implementación de sensores
├── acciones.h        # Declaraciones de funciones de acción
├── acciones.cpp      # Implementación de acciones del bot
├── ia.h              # Declaraciones de lógica de IA
└── ia.cpp            # Implementación de la lógica de decisión
```

## 🔧 Módulos del Sistema

### 1. Módulo de Sensores (`sensores.h` / `sensores.cpp`)

**Propósito**: Simular la detección de riesgos y obstáculos en el entorno.

**Funciones a implementar**:

```cpp
// Detección de vehículos
bool hayVehiculoDelante();        // Detecta vehículo muy cerca por delante
bool hayVehiculoAtras();          // Detecta vehículo aproximándose por atrás

// Detección de obstáculos laterales
bool obstaculoLateralIzq();       // Pared u obstáculo a la izquierda
bool obstaculoLateralDer();       // Pared u obstáculo a la derecha

// Detección de personas y objetos
bool hayPersonaFrente();          // Persona pasando frente al bot
bool hayObjetoEnSuelo();          // Objeto pequeño (cono, caja, piedra)

// Detección de terreno y zonas
bool terrenoResbaloso();          // Terreno con poca tracción
bool zonaProhibida();             // Zona de parqueo marcada como prohibida
bool espacioMuyEstrecho();        // Espacio de parqueo demasiado estrecho
```

**Cómo implementar los sensores**:

Para simular los sensores, puedes usar:
- **Valores aleatorios**: `rand() % 2` para simular detección aleatoria
- **Valores predefinidos**: Retornar `true` o `false` según el escenario que quieras probar
- **Entrada del usuario**: Leer valores desde la consola para pruebas interactivas

**Ejemplo de implementación**:
```cpp
bool hayVehiculoDelante() {
    // Simulación: 30% de probabilidad de detectar vehículo
    return (rand() % 100) < 30;
}
```

### 2. Módulo de Acciones (`acciones.h` / `acciones.cpp`)

**Propósito**: Ejecutar las acciones físicas del bot.

**Funciones a implementar**:

```cpp
void frenar();                    // Detener el movimiento inmediatamente
void girarIzquierda();            // Girar hacia la izquierda
void girarDerecha();              // Girar hacia la derecha
void retroceder();                // Moverse hacia atrás con precaución
void avanzar();                   // Continuar hacia adelante
void activarAlerta();             // Activar alerta sonora o luminosa
void buscarRutaAlterna();         // Buscar otra ruta hacia el espacio de parqueo
void reducirVelocidad();          // Reducir la velocidad actual
void acelerar();                  // Aumentar la velocidad
```

**Cómo implementar las acciones**:

Cada función debe mostrar un mensaje en consola indicando qué acción se está ejecutando.

**Ejemplo de implementación**:
```cpp
void frenar() {
    cout << "⚠️  ACCIÓN: Frenando inmediatamente..." << endl;
}

void girarIzquierda() {
    cout << "↶ ACCIÓN: Girando hacia la izquierda..." << endl;
}
```

### 3. Módulo de IA (`ia.h` / `ia.cpp`)

**Propósito**: Tomar decisiones inteligentes basadas en los datos de los sensores.

**Funciones principales**:

```cpp
int detectarRiesgo();             // Evalúa todos los sensores y retorna el riesgo más crítico
void procesarDecision();          // Decide qué acción ejecutar según el riesgo detectado
```

**Lógica de detección de riesgos**:

La función `detectarRiesgo()` debe:
1. Revisar todos los sensores en orden de prioridad
2. Retornar un código numérico que representa el riesgo más crítico
3. Usar constantes o enumeraciones para los códigos de riesgo

**Códigos de riesgo sugeridos**:
```cpp
// Puedes usar constantes o enum
#define SIN_RIESGO          -1
#define VEHICULO_ADELANTE    0
#define OBSTACULO_IZQUIERDA  1
#define OBSTACULO_DERECHA    2
#define PERSONA_EN_FRENTE    3
#define TERRENO_RESBALOSO    4
#define ZONA_PROHIBIDA       5
#define OBJETO_EN_SUELO      6
#define ESPACIO_ESTRECHO     7
#define VEHICULO_ATRAS       8
```

**Ejemplo de implementación de `detectarRiesgo()`**:
```cpp
int detectarRiesgo() {
    // Prioridad 1: Riesgos críticos que requieren frenado inmediato
    if (hayVehiculoDelante()) {
        return VEHICULO_ADELANTE;
    }
    if (hayPersonaFrente()) {
        return PERSONA_EN_FRENTE;
    }
    
    // Prioridad 2: Obstáculos laterales
    if (obstaculoLateralIzq()) {
        return OBSTACULO_IZQUIERDA;
    }
    if (obstaculoLateralDer()) {
        return OBSTACULO_DERECHA;
    }
    
    // Prioridad 3: Condiciones del terreno
    if (terrenoResbaloso()) {
        return TERRENO_RESBALOSO;
    }
    
    // Prioridad 4: Zonas y espacios
    if (zonaProhibida()) {
        return ZONA_PROHIBIDA;
    }
    if (espacioMuyEstrecho()) {
        return ESPACIO_ESTRECHO;
    }
    
    // Prioridad 5: Otros riesgos
    if (hayObjetoEnSuelo()) {
        return OBJETO_EN_SUELO;
    }
    if (hayVehiculoAtras()) {
        return VEHICULO_ATRAS;
    }
    
    // No hay riesgos detectados
    return SIN_RIESGO;
}
```

**Ejemplo de implementación de `procesarDecision()`**:
```cpp
void procesarDecision() {
    int riesgo = detectarRiesgo();
    
    switch(riesgo) {
        case VEHICULO_ADELANTE:
            frenar();
            activarAlerta();
            break;
            
        case OBSTACULO_IZQUIERDA:
            girarDerecha();
            break;
            
        case OBSTACULO_DERECHA:
            girarIzquierda();
            break;
            
        case PERSONA_EN_FRENTE:
            frenar();
            activarAlerta();
            break;
            
        case TERRENO_RESBALOSO:
            reducirVelocidad();
            break;
            
        case ZONA_PROHIBIDA:
            buscarRutaAlterna();
            break;
            
        case OBJETO_EN_SUELO:
            reducirVelocidad();
            break;
            
        case ESPACIO_ESTRECHO:
            buscarRutaAlterna();
            break;
            
        case VEHICULO_ATRAS:
            activarAlerta();
            avanzar();
            break;
            
        case SIN_RIESGO:
        default:
            avanzar();
            break;
    }
}
```

### 4. Módulo Principal (`main.cpp`)

**Propósito**: Orquestar el ciclo principal del bot.

**Flujo del programa**:

1. Inicializar el sistema (semilla para números aleatorios, mensaje de inicio)
2. Ejecutar un ciclo de al menos 5 iteraciones
3. En cada iteración:
   - Mostrar el estado actual
   - Procesar la decisión de la IA
   - Esperar un momento (opcional, para mejor visualización)
4. Mostrar resumen final

**Ejemplo de implementación**:
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ia.h"

using namespace std;

int main() {
    // Inicializar semilla para números aleatorios
    srand(time(nullptr));
    
    cout << "🤖 Bot de Parqueo iniciado..." << endl;
    cout << "=================================" << endl << endl;
    
    const int ITERACIONES = 5;
    
    for (int i = 1; i <= ITERACIONES; i++) {
        cout << "\n--- Iteración " << i << " ---" << endl;
        procesarDecision();
        cout << endl;
    }
    
    cout << "=================================" << endl;
    cout << "✅ Proceso completado." << endl;
    
    return 0;
}
```

## 📝 Pasos de Implementación

### Paso 1: Configurar el proyecto en CLion

1. Abre CLion
2. Crea un nuevo proyecto C++ (Ejecutable)
3. Asegúrate de que todos los archivos estén en la misma carpeta

### Paso 2: Implementar el módulo de Sensores

1. Completa `sensores.h` con todas las declaraciones de funciones
2. En `sensores.cpp`, implementa cada función retornando valores simulados
3. Usa `rand()` para simular detecciones aleatorias o valores fijos para pruebas

### Paso 3: Implementar el módulo de Acciones

1. Completa `acciones.h` con todas las declaraciones
2. En `acciones.cpp`, implementa cada función mostrando mensajes descriptivos
3. Cada acción debe ser clara y específica

### Paso 4: Implementar el módulo de IA

1. Define las constantes o enum para los códigos de riesgo
2. Implementa `detectarRiesgo()` revisando todos los sensores en orden de prioridad
3. Implementa `procesarDecision()` con un switch que mapee riesgos a acciones

### Paso 5: Implementar el main.cpp

1. Incluye los headers necesarios
2. Inicializa la semilla aleatoria
3. Crea el ciclo principal con al menos 5 iteraciones
4. Llama a `procesarDecision()` en cada iteración

### Paso 6: Compilar y probar

1. Compila el proyecto (Build → Build Project)
2. Ejecuta el programa (Run → Run)
3. Observa las decisiones que toma el bot
4. Ajusta los valores de los sensores si es necesario

## 🎯 Mapeo de Riesgos a Acciones

| Riesgo Detectado | Acción Recomendada |
|------------------|-------------------|
| Vehículo delante | Frenar + Activar Alerta |
| Obstáculo izquierda | Girar derecha |
| Obstáculo derecha | Girar izquierda |
| Persona en frente | Frenar + Activar Alerta |
| Terreno resbaloso | Reducir velocidad |
| Zona prohibida | Buscar ruta alterna |
| Objeto en suelo | Reducir velocidad |
| Espacio estrecho | Buscar ruta alterna |
| Vehículo atrás | Activar alerta + Avanzar |
| Sin riesgo | Avanzar normalmente |

## 💡 Consejos de Implementación

1. **Prioridad de riesgos**: Los riesgos más críticos (colisión inminente) deben revisarse primero
2. **Mensajes claros**: Usa mensajes descriptivos en las acciones para entender qué está haciendo el bot
3. **Modularidad**: Mantén cada módulo independiente y bien organizado
4. **Pruebas**: Prueba con diferentes combinaciones de sensores activos
5. **Documentación**: Comenta el código para explicar la lógica de decisión

## 🔍 Ejemplo de Salida Esperada

```
🤖 Bot de Parqueo iniciado...
=================================

--- Iteración 1 ---
⚠️  ACCIÓN: Frenando inmediatamente...
🔔 ACCIÓN: Activando alerta sonora...

--- Iteración 2 ---
↶ ACCIÓN: Girando hacia la izquierda...

--- Iteración 3 ---
➡️  ACCIÓN: Avanzando normalmente...

--- Iteración 4 ---
⚠️  ACCIÓN: Reduciendo velocidad...

--- Iteración 5 ---
🔍 ACCIÓN: Buscando ruta alterna...

=================================
✅ Proceso completado.
```

## 📚 Conceptos Clave

- **Modularidad**: Separar el código en módulos lógicos facilita el mantenimiento
- **Simulación**: Los sensores simulan el mundo real mediante valores aleatorios o predefinidos
- **Lógica condicional**: La IA usa if/switch para tomar decisiones basadas en condiciones
- **Priorización**: Los riesgos más críticos se evalúan primero

## 🚀 Extensiones Opcionales

Una vez completado el proyecto básico, puedes agregar:
- Sistema de puntuación de riesgos (riesgo bajo/medio/alto)
- Historial de decisiones
- Múltiples riesgos simultáneos
- Interfaz gráfica simple
- Guardado de logs en archivo

---

**¡Buena suerte con tu implementación!** 🎉

