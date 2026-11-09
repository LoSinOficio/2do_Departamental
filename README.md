# Segundo Departamental - Abstracción y Uso de Datos

## Carátula

| Dato | Información |
| --- | --- |
| Institución | Unidad Profesional Interdisciplinaria de Ingeniería y Ciencias Sociales y Administrativas |
| Asignatura | Abstracción y Uso de Datos |
| Trabajo | Segundo departamental |
| Periodo | Segundo parcial |
| Equipo | Los Sin Oficio |
| Integrantes | Cruz Montalvo Erick Itzmin |
|  | Murillo Sánchez Fátima Mariana |
|  | Pérez Rivera Leia Michelle |
| Docente | Yventz Entzana Garduño |
| Repositorio | https://github.com/LoSinOficio/2do_Departamental.git |

## Índice

1. [Desarrollo](#1-desarrollo)
2. [Solución de las prácticas y código esencial](#2-solución-de-las-prácticas-y-código-esencial)
3. [Compilación y ejecución](#3-compilación-y-ejecución)
4. [Conclusiones](#4-conclusiones)
5. [Referencias](#5-referencias)

## 1. Desarrollo

### Descripción del trabajo

Este repositorio contiene las prácticas desarrolladas para el segundo departamental de la asignatura Abstracción y Uso de Datos. El trabajo está orientado a la aplicación de algoritmos de ordenamiento y a la implementación de estructuras de datos, tanto estáticas como dinámicas.

Cada ejercicio se encuentra en un archivo independiente de C++, con su propia función `main`, lo que permite compilar y ejecutar cada práctica por separado según sea necesario.

### Objetivo

El objetivo principal del proyecto es reforzar la lógica de programación y la manipulación de datos mediante la resolución de problemas que involucren:

- Ordenamiento de caracteres, enteros y tipos definidos por el usuario.
- Algoritmos de ordenamiento: burbuja, merge sort y quick sort.
- Ordenamiento indirecto mediante punteros e índices.
- Manejo de punteros y referencias.
- Implementación de pilas, colas y listas.
- Uso de estructuras de datos dinámicas y contenedores de la STL.

### Fundamentación

Durante el segundo departamental se estudiaron dos temas centrales: la organización de la información y la eficiencia en el acceso a los datos. El ordenamiento permite agrupar elementos para facilitar su análisis y búsqueda, mientras que las estructuras de datos permiten almacenar, insertary consultar datos de forma ordenada.

Estas herramientas son esenciales para resolver problemas más complejos, optimizar procesos y desarrollar soluciones más robustas en C++.

### Procedimiento

1. Se identificó el tipo de ejercicio y la técnica requerida.
2. Se seleccionaron las variables, arreglos, punteros y estructuras necesarias.
3. Se escribió el programa en un archivo independiente con su `main`.
4. Se compiló y ejecutó cada ejercicio para comprobar su funcionamiento.
5. Se documentó la lógica principal para facilitar la revisión y comprensión del trabajo.

### Temas trabajados

- Ordenamiento por burbuja.
- Ordenamiento por merge sort.
- Ordenamiento por quick sort.
- Ordenamiento indirecto.
- Punteros y referencias.
- Pilas, colas y listas.
- Estructuras estáticas y dinámicas.
- Librerías estándar de C++.

## 2. Solución de las prácticas y código esencial

A continuación se presenta la organización de las prácticas del segundo departamental.

### 2.1 Ordenamiento

| No. | Concepto | Archivo |
| --- | --- | --- |
| 16 | Ordenamiento por burbuja | [Practica 16.cpp](Practica%2016.cpp) |
| 17 | Merge sort | [Practica 17.cpp](Practica%2017.cpp) |
| 18 | Quick sort | [Practica 18.cpp](Practica%2018.cpp) |
| 19 | Ordenamiento indirecto con burbuja | [Practica 19.cpp](Practica%2019.cpp) |
| 20 | Ordenamiento indirecto con merge sort | [Practica 20.cpp](Practica%2020.cpp) |
| 21 | Ordenamiento indirecto con quick sort | [Practica 21.cpp](Practica%2021.cpp) |

### 2.2 Estructuras de datos

| No. | Concepto | Archivo |
| --- | --- | --- |
| 1 | Punteros y referencias | [Practica 22_01.cpp](Practica%2022_01.cpp) |
| 2 | ADT | [Practica 22_02.cpp](Practica%2022_02.cpp) |
| 3 | Pila estática | [Practica 22_03.cpp](Practica%2022_03.cpp) |
| 4 | Cola estática | [Practica 22_04.cpp](Practica%2022_04.cpp) |
| 5 | Lista estática | [Practica 22_05.cpp](Practica%2022_05.cpp) |
| 6 | Pila dinámica | [Practica 22_06.cpp](Practica%2022_06.cpp) |
| 7 | Cola dinámica | [Practica 22_07.cpp](Practica%2022_07.cpp) |
| 7 bis | Lista dinámica | [Practica 22_07bits.cpp](Practica%2022_07bits.cpp) |
| 8 | Pila con STL | [Practica 22_08.cpp](Practica%2022_08.cpp) |
| 9 | Cola con STL | [Practica 22_09.cpp](Practica%2022_09.cpp) |
| 10 | Lista con STL | [Practica 22_10.cpp](Practica%2022_10.cpp) |

### Ejemplo de código esencial

El siguiente fragmento muestra la lógica del ordenamiento por burbuja:

```cpp
for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (arreglo[j] > arreglo[j + 1]) {
            int aux = arreglo[j];
            arreglo[j] = arreglo[j + 1];
            arreglo[j + 1] = aux;
        }
    }
}
```

Este algoritmo compara elementos adyacentes y realiza intercambios hasta que el arreglo quede ordenado.

También se trabajó con estructuras de datos dinámicas, por ejemplo en [Practica 22_10.cpp](Practica%2022_10.cpp), donde se usa `std::list<int>` para manejar una lista enlazada con inserciones al inicio y al final.

```cpp
list<int> elementos;
elementos.push_back(10);
elementos.push_front(5);
```

## 3. Compilación y ejecución

Se requieren compiladores compatibles con C++11 o posterior, como `g++`.

### Compilar una práctica concreta

```bash
g++ -std=c++11 "Practica 16.cpp" -o practica16
```

### Ejecutar en Windows

```powershell
.\practica16.exe
```

### Ejecutar en Linux o macOS

```bash
./practica16
```

Cada ejercicio contiene su propia función `main`, por lo que debe compilarse de forma independiente.

## 4. Conclusiones

El segundo departamental permitió reforzar conceptos fundamentales de la programación en C++. A través de los ejercicios de ordenamiento y estructuras de datos, se comprendió la importancia de organizar la información, optimizar procesos y manejar memoria de forma eficiente.

La combinación de algoritmos de clasificación con pilas, colas y listas demuestra que la elección de la estructura adecuada depende del problema que se desea resolver. Esto fortalece la capacidad de abstracción y la lógica de programación necesaria para el desarrollo de soluciones más complejas.

## 5. Referencias

- Archivos fuente del proyecto: [Practica 16.cpp](Practica%2016.cpp) a [Practica 22_10.cpp](Practica%2022_10.cpp).
- Bibliotecas estándar de C++ utilizadas: `<iostream>`, `<list>`, `<algorithm>`, `<string>`.
- Material académico de la asignatura Abstracción y Uso de Datos.

---

Repositorio académico desarrollado para la asignatura de Abstracción y Uso de Datos.
