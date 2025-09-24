//
// Pepe Gallardo, Data Structures, UMA.
//

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.h"

#include <stddef.h>
#include <stdbool.h>

struct Node {
  struct Task * task;    // Task to be executed
  struct Node* p_next; // Pointer to next node in circular list
};


struct Node* Scheduler_new(void); // Initialize an empty scheduler
/**
 * @brief Devuelve el número de tareas en el planificador.
 * @param p_last Puntero al último nodo de la cola (puede ser NULL).
 * @return Cantidad de tareas encoladas.
 */
size_t Scheduler_size(const struct Node* p_last); 


/**
 * @brief Elimina todas las tareas del planificador y lo deja vacío.
 * @param p_p_last Dirección de memoria donde está almacenado el puntero al último nodo de la cola;
 *        se pone a NULL al finalizar.
 */
void Scheduler_clear(struct Node** p_p_last); 

/**
 * @brief Obtiene una copia en memoria dinámica de la primera tarea del planificador.
 * @param p_last Puntero al último nodo de la cola (puede ser NULL).
 * @return Puntero a una copia de la primera Task, o NULL si la cola está vacía.
 * @note El llamador es responsable de liberar la Task devuelta.
 */
struct Task* Scheduler_first(const struct Node* p_last); 


/**
 * @brief Encola al final una copia de la tarea dada.
 * @param p_p_last Dirección de memoria donde está almacenado el puntero al último nodo de la cola;
 *        puede actualizarse si la cola estaba vacía.
 * @param p_task Puntero a la tarea origen a copiar (no se modifica).
 * @return true en caso de poder encolar, falso en caso contrario (scheduler no inicializado, no se puede pedir memoria, etc)
 */
bool Scheduler_enqueue(struct Node **p_p_last, const struct Task *p_task); 

/**
 * @brief Desencola la primera tarea del planificador.
 * @param p_p_last Dirección de memoria donde está el puntero al último nodo de la cola;
 *        puede actualizarse y quedar en NULL si se vacía.
 * @note Si la cola está vacía, no hace nada.
 * @return True en caso de poder encolar, falso en caso contrario (scheduler no inicializado, no se puede pedir memoria, etc)
 */
bool Scheduler_dequeue(struct Node * *p_p_last); 

/**
 * @brief Imprime todas las tareas del planificador.
 * @param p_last Puntero al último nodo de la cola.
 */
void Scheduler_print(const struct Node* p_last); // Print all tasks in the scheduler
#endif
