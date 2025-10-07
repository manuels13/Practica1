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
 * @brief Elimina todas las tareas del planificador y lo deja vacío.
 * @param p_p_last Dirección de memoria donde está almacenado el puntero al último nodo de la cola;
 *        se pone a NULL al finalizar.
 */
void Scheduler_clear(struct Node** p_p_last){
  if((*p_p_last)==NULL){
    perror("Lista ya vacia");
    exit(1);
  }
  struct Node *last = *p_p_last;
  struct Node *current = (*p_p_last)->p_next;
  struct Node *temp;
  while(current!=last){
    temp=current;
    Task_free(&(temp->task));
    current=current->p_next;
    free(temp);
  }
  Task_free(&(last->task));
  free(last);
  *p_p_last= NULL;

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
  if(*p_p_last==NULL){
    *p_p_last=nuevo;
    (*p_p_last) -> p_next=*p_p_last;
  }
  nuevo->task=Task_copyOf(p_task);;
  nuevo->p_next=(*p_p_last)->p_next;
  (*p_p_last)->p_next=nuevo;
  *p_p_last=nuevo;
  return true;
}
/**
 * @brief Obtiene una copia en memoria dinámica de la primera tarea del planificador.
 * @param p_last Puntero al último nodo de la cola (puede ser NULL).
 * @return Puntero a una copia de la primera Task, o NULL si la cola está vacía.
 * @note El llamador es responsable de liberar la Task devuelta.
 */
struct Task* Scheduler_first(const struct Node* p_last){
  if(p_last==NULL){
    return NULL;
  }
  return Task_copyOf(p_last->p_next->task);
}
/**
 * @brief Desencola la primera tarea del planificador.
 * @param p_p_last Dirección de memoria donde está el puntero al último nodo de la cola;
 *        puede actualizarse y quedar en NULL si se vacía.
 * @note Si la cola está vacía, no hace nada.
 * @return True en caso de poder encolar, falso en caso contrario (scheduler no inicializado, no se puede pedir memoria, etc)
 */
bool Scheduler_dequeue(struct Node * *p_p_last){
  if((*p_p_last)==NULL){
    return false;
  }
  struct Node *primero = (*p_p_last)->p_next;
  (*p_p_last)->p_next=primero->p_next;
  Task_free(&(primero->task));
  free(primero);
  return true;
}
  /**
 * @brief Imprime todas las tareas del planificador.
 * @param p_last Puntero al último nodo de la cola.
 */
void Scheduler_print(const struct Node* p_last){
  if(p_last==NULL){
    perror("Lista vacia");
    return;
  }
  struct Node *last = p_last;
  struct Node *current = p_last->p_next;
  while(current!=last){
    Task_print(current->task);
    current=current->p_next;
  }
  Task_print(last->task);
  

}

/**
 * @brief Avanza el planificador una posición (rota la cola).
 * @param p_p_last Dirección de memoria donde está el puntero al último
nodo de la cola;
 * pasa a apuntar al nuevo último.
 * @note Si la cola está vacía o tiene un único elemento, el estado
efectivo no cambia.
 */
void Scheduler_step(struct Node** p_p_last){
  if((*p_p_last)==NULL||(*p_p_last)->p_next==(*p_p_last)){
    return;
  }
  *p_p_last=(*p_p_last)->p_next;

}
