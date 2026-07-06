#define MAX_PRODUCTOS 100
#define LONG_CODIGO 16
#define LONG_NOMBRE 50
#define LONG_CATEGORIA 30
#define ARCHIVO_DEFAULT "inventario.csv"
typedef struct 
{
    char codigo [LONG_CODIGO];
    char nombre [LONG_NOMBRE];
    char categoria [LONG_CATEGORIA];
    float precio_compra;
    float precio_venta;
    int cantidad;
}Producto;
void limpiar_buffer();
void quitar_nueva_linea(char *cadena);
int verificar_codigo_unico(const Producto *inventario, int total, const char *codigo);
void registrar_producto(Producto *inventario, int *total);
void listar_productos(const Producto *inventario, int total);
void buscar_producto (const Producto *inventario, int total);
void actualizar_producto(Producto *inventario, int total);
void eliminar_producto(Producto *inventario, int *total);
void calcular_utilidad_total(const Producto *inventario, int total);
int cargar_datos(Producto *inventario, int *total);
int guardar_datos(const Producto *inventario, int total);