//
// Pepe Gallardo, Data Structures, UMA. 
//

#ifndef TASK_H // Conditional inclusion
#define TASK_H // Avoids multiple inclusion

#include <stddef.h>

/**
 * @brief Longitud máxima del nombre de una tarea (en caracteres).
 */
#define MAX_NAME_LEN 20

/**
 * @brief Representa una tarea en el sistema.
 */
struct Task {
  unsigned int id;                 ///< @brief Identificador único de la tarea.
  char name[1 + MAX_NAME_LEN];     ///< @brief Nombre de la tarea (cadena terminada en '\0').
  unsigned int quantum;            ///< @brief Quantum de tiempo asignado a la tarea.
};

/**
 * @brief Crea una nueva tarea en memoria dinámica.
 * @param id Identificador único de la tarea.
 * @param name Nombre de la tarea (se copia al campo interno).
 * @param quantum Quantum de tiempo asignado.
 * @return Puntero a la nueva tarea creada en el heap.
 * @note El llamador debe liberar la memoria con Task_free().
 */
struct Task* Task_new(unsigned int id, const char name[], unsigned int quantum);

/**
 * @brief Libera la memoria de una tarea y pone el puntero a NULL.
 * @param p_p_task Dirección de memoria donde está el puntero a la tarea a liberar.
 * @note Si *p_p_task es NULL, no hace nada.
 */
void Task_free(struct Task** p_p_task);

/**
 * @brief Crea una copia en memoria dinámica de la tarea dada.
 * @param p_task Puntero a la tarea a copiar.
 * @return Puntero a una nueva Task con los mismos datos.
 * @note El llamador debe liberar la memoria con Task_free().
 */
struct Task* Task_copyOf(const struct Task* p_task);

/**
 * @brief Imprime por pantalla los datos de una tarea.
 * @param p_task Puntero a la tarea a imprimir.
 */
void Task_print(const struct Task* p_task);

#endif
