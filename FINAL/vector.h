/*Proteccion contra inclusion multiple*/

#ifndef VECTOR__H

#define VECTOR__H

/*Se define la interfaz del TDA vector que se usará como memoria*/

#define MAX_SIZE_WORD 65535
#define MIN_SIZE_WORD 0

#define SHIFT_1 9
#define MASK_1 0xfe00
#define MASK_2 0x7f

typedef struct vector{
	size_t size;
	size_t used;
	void **datos;
} vector_t;

/*Funciones del TDA vector*/

bool vector_cargar(vector_t *v, void *dato, int *used);

vector_t * vector_crear(size_t s);

void vector_proc(vector_t **v);

void vector_destruir(vector_t **v);

void vector_limpiar_datos(vector_t *v);

/*Prototipos de funciones usadas con el op_code que interactuan con datos del vector TDA*/

bool vector_op_leer(vector_t *v, int operand);

void vector_op_guardar(vector_t *v, int operand, unsigned short int acc);

void vector_op_guardarp(vector_t *v, int operand, unsigned short int acc);

/*Funciones a procesar datos de entrada*/

bool vector_proc_txt(char *filename, vector_t *v, int *used, bool (*vector_cargar)(vector_t *v, void *dato, int *used));

bool vector_proc_bin(char *filename, vector_t *v, int *used, bool (*vector_cargar)(vector_t *v, void *dato, int *used));

bool vector_proc_stdin(vector_t *v, int *used);

#endif