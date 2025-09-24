#include "Task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * @brief Crea una nueva tarea en memoria dinámica.
 * @param id Identificador único de la tarea.
 * @param name Nombre de la tarea (se copia al campo interno).
 * @param quantum Quantum de tiempo asignado.
 * @return Puntero a la nueva tarea creada en el heap.
 * @note El llamador debe liberar la memoria con Task_free().
 */
struct Task* Task_new(unsigned int id, const char name[], unsigned int quantum){
  if(strlen(name)> MAX_NAME_LEN){
    perror("el nombre es muy largo");
    exit(1);
  }
  struct Task *new = malloc(sizeof(struct Task));
  if(new==NULL){
    printf("Error al alocar memoria");
    exit(-1);
  }
  new->id=id;
  strcpy(new->name,name);
  new->quantum=quantum;
  return new;
}
/**
 * @brief Libera la memoria de una tarea y pone el puntero a NULL.
 * @param p_p_task Dirección de memoria donde está el puntero a la tarea a liberar.
 * @note Si *p_p_task es NULL, no hace nada.
 */
void Task_free(struct Task** p_p_task){
  if(*p_p_task==NULL && p_p_task==NULL){
    exit(1);
  }
  free(*p_p_task);
  *p_p_task=NULL;
}
/**
 * @brief Crea una copia en memoria dinámica de la tarea dada.
 * @param p_task Puntero a la tarea a copiar.
 * @return Puntero a una nueva Task con los mismos datos.
 * @note El llamador debe liberar la memoria con Task_free().
 */
struct Task* Task_copyOf(const struct Task* p_task){
  if(p_task==NULL){
    return NULL;
  }
  return Task_new(p_task->id,p_task->name,p_task->quantum);
}
/**
 * @brief Imprime por pantalla los datos de una tarea.
 * @param p_task Puntero a la tarea a imprimir.
 */
void Task_print(const struct Task* p_task){
  if(p_task!=NULL){
    printf("ID: %d , Name: %s , Quantum: %d ",p_task->id,p_task->name,p_task->quantum);
  }
}