# Diagrama de Flujo - Sistema de Decisión del Bot de Parqueo

```mermaid
flowchart TD
    START([INICIO]) --> DETECT[Detectar Riesgo<br/>Aleatorio 0-5]
    
    DETECT --> EVAL{Evaluar<br/>Sensor}
    
    EVAL --> CHECK{¿Peligro<br/>Detectado?}
    
    CHECK -->|SÍ| ACTION[Ejecutar Acción<br/>Según Tipo de Riesgo]
    CHECK -->|NO| CONTINUE[Continuar]
    
    ACTION --> CONTINUE
    
    CONTINUE --> LOOP{¿Más<br/>Iteraciones?}
    
    LOOP -->|SÍ| DETECT
    LOOP -->|NO| END([FIN])
    
    style START fill:#4CAF50,color:#fff,stroke-width:4px,font-size:24px
    style END fill:#f44336,color:#fff,stroke-width:4px,font-size:24px
    style DETECT fill:#2196F3,color:#fff,stroke-width:3px,font-size:22px
    style EVAL fill:#FF9800,color:#fff,stroke-width:3px,font-size:22px
    style CHECK fill:#9C27B0,color:#fff,stroke-width:3px,font-size:22px
    style ACTION fill:#E91E63,color:#fff,stroke-width:3px,font-size:22px
    style CONTINUE fill:#00BCD4,color:#fff,stroke-width:3px,font-size:22px
    style LOOP fill:#FFC107,color:#000,stroke-width:3px,font-size:22px
```

## Tabla de Acciones por Tipo de Riesgo

| Tipo | Sensor | Acción |
|------|--------|--------|
| **0** | Vehículo delante | Frenar + Activar Alerta |
| **1** | Persona frente | Frenar + Activar Alerta |
| **2** | Obstáculo lateral izquierdo | Girar Derecha |
| **3** | Obstáculo lateral derecho | Girar Izquierda |
| **4** | Terreno resbaloso | Reducir Velocidad |
| **5** | Zona prohibida | Buscar Ruta Alterna |

## Descripción del Flujo

1. **INICIO**: El bot de parqueo se inicia
2. **Detectar Riesgo**: Se genera un número aleatorio (0-5) que representa el tipo de riesgo
3. **Evaluar Sensor**: Se evalúa el sensor correspondiente al tipo de riesgo detectado
4. **¿Peligro Detectado?**: Se verifica si realmente hay peligro
   - **SÍ** → Se ejecuta la acción correspondiente según la tabla
   - **NO** → Se continúa sin acción
5. **Continuar**: Después de la acción (o si no hay peligro), se continúa
6. **¿Más Iteraciones?**: Se verifica si hay más iteraciones
   - **SÍ** → Vuelve a detectar riesgo
   - **NO** → FIN

