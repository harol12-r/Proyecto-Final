#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
int main(){
    Producto inventario[MAX_PRODUCTOS];
    int total_productos=0;

    if (cargar_datos(inventario, &total_productos))
    {
        printf("Datos cargados desde '%s'.\n", ARCHIVO_DEFAULT);

    }else{
        printf("No se encontro archivo anterior. Inventario vacio,\n");
    }
    int opcion;
    do
    {
        printf("\n==== BODEGA INTERACTIVA ====\n");
        printf("1. Registrar el Producto\n");
        printf("2. Listar los Productos\n");
        printf("3. Buscar el Producto\n");
        printf("4. Actualizar el Producto\n");
        printf("5. Eliminar un Producto\n");
        printf("6. Calcular Utilidad Total\n");
        printf("7. Guardar Manualmente\n");
        printf("8. Salir (Autoguardado)\n");
        printf("SELECCIONE UNA OPCION: ");

        if (scanf("&d", opcion)!=1)
        {
            limpiar_buffer();
            opcion = 0;
            continue;
        }
        switch (opcion)
        {
        case 1: registrar_producto(inventario, &total_productos); break;
        case 2: listar_productos(inventario, total_productos); break;
        case 3: buscar_producto(inventario, total_productos); break;
        case 4: actualizar_producto(inventario, total_productos); break;
        case 5: eliminar_producto(inventario, &total_productos); break;
        case 6: calcular_utilidad_total(inventario, total_productos); break;
        case 7:
        if (guardar_datos(inventario, total_productos)) printf("Guardado Exitoso. \n");
            break;
        }
        
    } while (opcion !=8);
    
    return 0;
}