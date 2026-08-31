# ADA_P1_Gonzalez_Martinez_Pina_Quimbayo

Práctica 1 — Fuerza Bruta y Backtracking. Análisis y Diseño de Algoritmos.

## Integrantes
- Brayan Gonzalez Mateus
- Alejandro Martinez Vivanco
- José Eduardo Piña Montero
- Angel David Quimbayo Carvajal

## Semilla del equipo
Apellidos concatenados (orden alfabético, sin tildes, ñ normalizada a n): `gonzalezmartinezpinaquimbayo`
Semilla calculada: **3043** (suma de códigos ASCII mod 100000)

Parámetros de la política del Módulo BT (Sección 9.2):
- minLower = 3, minUpper = 2, minDigit = 2, minSymbol = 1, n = 8

Puedes reproducir este cálculo corriendo `tests/verificar_semilla.cpp`. Nota: la utilidad oficial `resources/verificar_semilla.cpp` mencionada en la Sección 9 no fue publicada por el docente al momento de esta entrega; se consultó por el canal oficial del curso y se implementó una versión propia con el mismo procedimiento documentado.

## Estructura del proyecto

src/ Código fuente de ambos módulos (FB y BT) y main.cpp (con menú)

tests/ Pruebas de correctitud y verificación de semilla

resources/ Archivos de datos de entrada (diccionario.txt, etc.)

results/ Salidas de la experimentación (CSV, gráficas)

report/ Informe técnico (Informe.pdf)


## Compilación

Desde la raíz del repositorio:

g++ -std=c++17 -O2 -o ada_p1 src/*.cpp


## Ejecución

El programa arranca con un menú para elegir el módulo:

./ada_p1


o, si vas a usar el Módulo BT, puedes pasar directamente los parámetros de la instancia como argumentos:

./ada_p1 <n> <minLower> <minUpper> <minDigit> <minSymbol>


### Módulo FB (Fuerza Bruta)

Al ejecutar `./ada_p1` (sin argumentos) y elegir la opción `1` en el menú, el programa pide interactivamente:
1. El hash SHA-256 objetivo.
2. `1` para fuerza bruta pura, o `0` para ataque por diccionario.
3. Si eliges fuerza bruta (`1`): el alfabeto, la longitud mínima y la longitud máxima a explorar.
4. Si eliges diccionario (`0`): busca directamente en `resources/diccionario.txt`.

### Módulo BT (Backtracking)

Ejecuta con los 5 parámetros de la instancia:

./ada_p1 <n> <minLower> <minUpper> <minDigit> <minSymbol>


Ejemplos:

./ada_p1 8 3 2 2 1 # Instancia del equipo (política completa)
./ada_p1 6 2 1 1 1 # Instancia de referencia común (Sección 9.2)


El programa te preguntará qué módulo quieres correr — elige `2` para Backtracking. Se ejecutan ambas versiones (con poda y sin poda) y se reportan nodos generados, visitados, podados, número de soluciones, y tiempo de ejecución.

## Pruebas de correctitud

g++ -std=c++17 -O2 -o test_bt tests/verificar_correctitud.cpp src/backtracking.cpp src/BTSinPoda.cpp
./test_bt


Verifica que las versiones con poda y sin poda coincidan en el número de soluciones, sobre 4 instancias de prueba más la instancia de referencia común (n=6, minLower=2, minUpper=1, minDigit=1, minSymbol=1): **293,922,208 soluciones**, validadas con la versión CON poda.

## Generación de resultados experimentales (Módulo BT)

g++ -std=c++17 -O2 -o generar_resultados results/generar_resultados.cpp src/backtracking.cpp src/BTSinPoda.cpp
./generar_resultados "<etiqueta>" <n> <minLower> <minUpper> <minDigit> <minSymbol>


Los resultados se acumulan en `results/resultados_bt.csv`.

## Instancias intratables (documentadas por extrapolación, no ejecutadas completas)

| Instancia | Motivo |
|---|---|
| Variante (i): n=8, política completa | Extrapolación desde n=4: estimado >12,000 años con poda |
| Variante (iii): n=10, política completa | Extrapolación desde (i): árbol ~4,489x mayor |
| Variante (iv): n=8, política relajada (minLower=1) | Extrapolación desde variante (v): árbol ~4,356x mayor, estimado ~157 días |
| Serie de gráfica, n=7, política (1,1,1,1) | Extrapolación desde n=6: estimado >30 horas |
