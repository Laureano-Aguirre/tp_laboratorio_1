int controller_loadFromText(char* path , LinkedList* pArrayListEmployee); //ok
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, int* idEmpleado); //ok
int controller_editEmployee(LinkedList* pArrayListEmployee); //ok
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int buscarIndice(LinkedList* pArrayListEmployee, int id); //ok
void mostrarEmpleado(LinkedList* pArrayListEmployee, int index); //ok
int OrdenamientoPorNombre(void* empleadoA, void* empleadoB); //ok
int OrdenamientoPorHsTrabajadas(void* empleadoA, void* empleadoB); //ok
int OrdenamientoPorSueldo(void* empleadoA, void* empleadoB);	//ok

