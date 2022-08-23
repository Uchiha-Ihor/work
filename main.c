#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char global[5];

int broken(void){
	char *dyn;
	char local[5];
	
	dyn = malloc(5);
	strcpy(dyn, "7734");
	printf("1:%s\n", dyn);
	free(dyn);
	
	dyn = malloc(5);
	strcpy(dyn, "1234");
	printf("2: %s\n", dyn);
	
	/* Пройти перед началом выделенного с помощью malloc локального буфера */
	*(dyn-1) ='\0';
	printf ("3: %s\n", dyn);
	/* обратите внимание, что указатель не освобожден! */

	/* Теперь двинуться после переменной local */
	strcpy(local, "1234");
	printf ("4: %s\n", local);
	local[-1] = '\0';
	printf("5: %s\n", local);

	/* Наконец, атаковать пространство данных global */
	strcpy(global, "1234");
	printf ("6: %s\n", global);

	/* И записать поверх пространства перед буфером global */
	global[-1] = '\0';
	printf("7: %s\n", global);
	return 0;
}
	
int main (void) {
	return broken();
}
	
