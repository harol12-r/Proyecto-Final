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