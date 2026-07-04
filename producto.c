#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "producto.h"
void limpiar_buffer(){
    int c;
    while ((c=getchar())!=  '\n' && c != EOF);
    
}
void quitar_nueva_linea(char *cadena){
    int i= 0;
    while (*(cadena+i) !=  '\0 ')
    {
        if (*(cadena+i)==  '\n ')
        {
            *(cadena+i)=  '\0 ';
        }
        i++;
    }
    
}
int verificar_codigo_unico(const Producto *inventario, int total, const char *codigo){
for (int i= 0; i < total; i++)
{
    if (strcmp ((inventario+i)->codigo, codigo)==0)
    {
        return 0;
    }
    
}
return 1;
}
void registrar_producto(Producto *inventario, int *total){
    if (*total>= MAX_PRODUCTOS)
    {
        printf ("\n [Error] El inventario esta lleno. \n");
        return;
    }
    Producto nuevo;
    printf("\n --- REGISTRAR PRODUCTO ---\n");
    do
    {
        printf("Codigo (1-15 carac.):");
        fgets(nuevo.codigo, sizeof(nuevo.codigo), stdin);
        quitar_nueva_linea(nuevo.codigo);
        if (*(nuevo.codigo)==  '\0 ')
        {
            printf("[ERROR] El codigo no puede estar vacio.\n");
            continue;
        }
        if (verificar_codigo_unico(inventario, *total, nuevo.codigo))
        {
            printf("[ERROR] El codigo ya esta registrado.\n");
        }
        
        break;
    } while (1);
    printf("Nombre:");
    fgets(nuevo.nombre, sizeof (nuevo.nombre), stdin);
    quitar_nueva_linea(nuevo.categoria);
    do
    {
        printf("Precio de compra(>0): ");
        if (scanf("%f", &nuevo.precio_compra)!=1 || nuevo.precio_compra <=0)
        {
            printf("[ERROR] Ingrese un precio valido.\n");
            limpiar_buffer();
        }
        else
        {
            break;
        }
        
    } while (1);
    do
    {
        printf("Cantidad: (>=0): ");
        if (scanf("%d", &nuevo.cantidad)!=1||nuevo.cantidad<0)
        {
            printf("[ERROR] Ingrese una cantidad valida");
            limpiar_buffer();
        }
        else
        {
            break;
        }
        
    } while (1);
    limpiar_buffer();
    *(inventario + *total)= nuevo;
    (*total)++;
    printf("\nProducto registrado con exito\n");
}
void listar_productos(const Producto *inventario, int total)
{
if (total == 0)
{
    printf("\n No hay productos en el inventario. \n");
    return;
}
printf("\n%-10s %-15s %-15s %-10s %-10s %-10s %-10s \n", "CODIGO", "NOMBRE", "CATEGORIA", "P. VENTA", "P. VENTA", "CANTIDAD", "UTILIDAD");
printf("------------------------------------------------------------------------------------------------------------------------------\n");
for (int i = 0; i < total; i++)
{
    const Producto *p = inventario + i;
    float utilidad = (p->precio_venta - p->precio_compra) * p->cantidad;
    printf("\n%-10s %-15s %-15s %-10.2s %-10.2s %-10s %-10.2s \n", p->codigo, p->nombre, p->categoria, p->precio_compra, p->precio_venta, p->cantidad, utilidad);

}

}