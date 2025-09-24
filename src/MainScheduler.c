//
// Usa el depurador para ver el contenido de la memoria.
//

#include "Scheduler.h"
#include <stdio.h>

int main(void) {
  struct Node* ptr_cola_circular = NULL;

  // Enqueue a heap allocated task
  struct Task* ptr_tarea1 = Task_new(1, "Task1", 2);
  bool exito = Scheduler_enqueue(&ptr_cola_circular, ptr_tarea1);
  Task_free(&ptr_tarea1);
  
  // Enqueue another heap allocated task
  struct Task* ptr_tarea2 = Task_new(2, "Task2", 1);
  exito = Scheduler_enqueue(&ptr_cola_circular, ptr_tarea2);
  Task_free(&ptr_tarea2);
  
  // Enqueue a stack allocated task
  struct Task ptr_tarea3 = {.id=3, .name="Task3", .quantum=3};
  exito = Scheduler_enqueue(&ptr_cola_circular, &ptr_tarea3);

  printf("Initial Scheduler:\n");
  Scheduler_print(ptr_cola_circular);

  printf("\n\nFirst Task:\n");
  struct Task* ptr_tarea = Scheduler_first(ptr_cola_circular);
  Task_print(ptr_tarea);
  Task_free(&ptr_tarea);

  printf("\n\nAfter Dequeue:\n");
  exito = Scheduler_dequeue(&ptr_cola_circular);
  Scheduler_print(ptr_cola_circular);

  struct Task tarea4 = {.id=4, .name="Task4", .quantum=4};
  exito = Scheduler_enqueue(&ptr_cola_circular, &tarea4);
  printf("\n\nAfter Enqueue:\n");
  Scheduler_print(ptr_cola_circular);

  Scheduler_clear(&ptr_cola_circular);
  printf("\n\nAfter Clearing Scheduler:\n");
  Scheduler_print(ptr_cola_circular);
  printf("\n");

  exito = Scheduler_dequeue(&ptr_cola_circular);

  return 0;
}
