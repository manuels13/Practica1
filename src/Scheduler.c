#include "Scheduler.h"
#include <stdlib.h>
/**
 * @brief Devuelve el número de tareas en el planificador.
 * @param p_last Puntero al último nodo de la cola (puede ser NULL).
 * @return Cantidad de tareas encoladas.
 */
size_t Scheduler_size(const struct Node* p_last){
  if(p_last==NULL){
    return 0;
  }
  struct Node *temp = p_last;
  size_t contador=1;
  while(temp->p_next != p_last){
    contador++;
    temp = temp->p_next;
  }
  return contador;
}

/**
 * @brief Encola al final una copia de la tarea dada.
 * @param p_p_last Dirección de memoria donde está almacenado el puntero al último nodo de la cola;
 *        puede actualizarse si la cola estaba vacía.
 * @param p_task Puntero a la tarea origen a copiar (no se modifica).
 * @return true en caso de poder encolar, falso en caso contrario (scheduler no inicializado, no se puede pedir memoria, etc)
 */
bool Scheduler_enqueue(struct Node **p_p_last, const struct Task *p_task){
  struct Node *nuevo = malloc(sizeof(struct Node));
  if(nuevo==NULL){
    return false;
  }
  nuevo->task=Task_copyOf(p_task);;
  nuevo->p_next=(*p_p_last)->p_next;
  (*p_p_last)->p_next=nuevo;
  *p_p_last=nuevo;



}