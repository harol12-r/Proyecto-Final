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
void buscar_producto (const Producto *inventario, int total){
    if (total==0){
        printf("\n No hay productos registrados.\n");
        return;
    }
    char criterio[50];
    printf("\n Ingrese el codigo o inicio del nombre a buscar: ");
    fgets(criterio, sizeof(criterio), stdin);
    quitar_nueva_linea(criterio);
    int encontrados = 0;
   for (int i = 0; i < total; i++) {
        const Producto *p = inventario + i;
        
        int coincide = (strcmp(p->codigo, criterio) == 0);
        
    
        if (!coincide) {
            int j = 0;
            coincide = 1;
            while (*(criterio + j) != '\0') {
                if (*(p->nombre + j) != *(criterio + j)) {
                    coincide = 0;
                    break;
                }
                j++;
            }
        }

if (coincide) {
            if (encontrados == 0) {
                printf("\n%-10s %-15s %-15s %-10s %-10s %-10s\n", "CODIGO", "NOMBRE", "CATEGORIA", "P. COMPRA", "P. VENTA", "CANTIDAD");
            }
            printf("%-10s %-15s %-15s %-10.2f %-10.2f %-10d\n", p->codigo, p->nombre, p->categoria, p->precio_compra, p->precio_venta, p->cantidad);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron coincidencias.\n");
    }
}
void actualizar_producto(Producto *inventario, int total){
    char codigo[LONG_CODIGO];
    printf("\n Ingrese el codigo del producto a modificar: ");
    fgets(codigo, sizeof(codigo), stdin);
    quitar_nueva_linea(codigo);
    int indice=-1;
    for (int i = 0; i < total; i++)
    {
    if (strcmp((inventario+i)->codigo, codigo)==0)
    {
        indice=i;
        break;
    }
    
    }
    if (indice==-1)
    {
        printf("[ERROR] El producto no existe.\n");
        return;
    }
    Producto *p = inventario + indice;
    printf("Nuevo Nombre: ");
    fgets(p->nombre, sizeof(p->nombre), stdin);
    quitar_nueva_linea(p->nombre);

    printf("Nueva categoria: ");
    fgets(p->categoria, sizeof(p->categoria), stdin);
    quitar_nueva_linea(p->categoria);
    
}
void eliminar_producto(Producto *inventario, int *total){
    char codigo[LONG_CODIGO];
    printf("\nIngrese el codigo a eliminar: ");
    fgets(codigo, sizeof(codigo), stdin);
    quitar_nueva_linea(codigo);
    int indice=-1;
    for (int i = 0; i < total; i++)
    {
    if (strcmp((inventario+i)->codigo, codigo)==0)
    {
      indice=i;
      break;
    }
    
    }
    if (indice==-1)
    {
      printf("[ERROR] El codigo no existe. \n");
      return;
    }
    char conf;
    printf("¿Seguro que desea eliminar %s? (s/n): ", (inventario + indice)->nombre);
    scanf("%c", &conf);
    limpiar_buffer();
    if (conf=='s'||conf=='S')
    {
        for (int i = indice; i < *total-1; i++)
        {
            *(inventario+i)=*(inventario+i+1);
        }
    (*total)--;
    printf("Producto Eliminado.\n");
    }
    
}
void calcular_utilidad_total(const Producto *inventario, int total){
  float suma=0;
  for (int i = 0; i < total; i++)
  {
    const Producto *p=inventario +i;
    suma += (p->precio_venta - p->precio_compra)* p->cantidad;
  }
  printf("\nUTILIDAD TOTAL: $%.2f\n", suma);  
}
int cargar_datos(Producto *inventario, int *total){
    FILE *archivo=fopen(ARCHIVO_DEFAULT, "r");
    if(!archivo) return 0;

    char cabecera[256];
    fgets(cabecera, sizeof(cabecera), archivo);

    *total=0;
    while (*total<MAX_PRODUCTOS &&
    fscanf(archivo, "%15[[^,], %49[^,], %29[^,], %f, %f, %d\n",
    (inventario +*total)->codigo,
      (inventario + *total)->nombre,
    (inventario+*total)->categoria,
    &(inventario + *total)->precio_compra,
    &(inventario + *total)->precio_venta,
    &(inventario + *total)->cantidad)==6)
    {
        (*total)++;
    }
    fclose(archivo);
    return 1;
}
int guardar_datos(const Producto *inventario, int total){
    FILE *archivo = fopen(ARCHIVO_DEFAULT, "w");
    if (archivo) return 0;
    
    fprintf(archivo, "codigo, nombre, categoria, precio_compra, precio_venta, cantidad\n ");

    for (int i = 0; i < total; i++)
    {
        const Producto *p = inventario + i;
        fprintf(archivo, "%s, %s, %s, %.2f, %.2f, %d\n",
        p->codigo, p->nombre, p->categoria,
        p->precio_compra, p->precio_venta, p->cantidad);
    }
    fclose(archivo);
    return 1;
    
}