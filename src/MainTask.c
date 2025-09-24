//
// Prueba de la estructura Task
// Joaquín Ballesteros, Data Structures, UMA
//

#include <stdio.h>
#include "Task.h" //Incluimos la librería, adapta si está anidada en otra carpeta.

int main(void) {
    // Crear una tarea
    struct Task *t1 = Task_new(1, "Editor", 5);
    printf("Tarea creada:\n");
    Task_print(t1);

    // Hacer una copia
    struct Task *t2 = Task_copyOf(t1);
    printf("\nCopia de la tarea:\n");
    Task_print(t2);

    // Modificar el original para comprobar independencia de la copia
    t1->quantum = 10;
    printf("\nTras modificar el quantum de la tarea original:\n");
    printf("Original: ");
    Task_print(t1);
    printf("\nCopia:    ");
    Task_print(t2);

    // Liberar memoria
    Task_free(&t1);
    Task_free(&t2);

    if (t1 == NULL && t2 == NULL) {
        printf("\nMemoria liberada correctamente.\n");
    }

    return 0;
}
