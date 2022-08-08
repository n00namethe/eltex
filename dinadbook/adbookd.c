#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

#define N 20

typedef struct 
{
	char namesurname[N];
	int  phonenum;
} book;

int main()
{
	int M=3;
	book*adr=NULL;
	adr=malloc(M*sizeof(book));
	if (NULL==adr)
		{
			printf("ошибка выделения памяти\n");
			return(1);
		}
	int i; //Счетчик
	int j; //switch
	int p, phs;
	
	int*phone=&p;
	strncpy(adr[0].namesurname, "igor prikhodko", N);
	adr[0].phonenum=74557;
		
	strncpy(adr[1].namesurname, "ilya trishin", N);
	adr[1].phonenum=23453;
		
	strncpy(adr[2].namesurname, "efim glazkov", N);
	adr[2].phonenum=73273;
	for (int i=0; i<M; ++i)
	{
		printf("%s %d\n", adr[i].namesurname, adr[i].phonenum);
	}
	while (1)
	{
		printf("1. Добавить абонента;\n");
		printf("2. Список абонентов;\n");
		printf("3. Найти абонента;\n");
		printf("4. Удалить абонента;\n");
		printf("5. Выход;\n");
		int scn;
		scn=scanf("%d%*c", &j);
			if (scn!=1)
			{
				free(adr);
				printf("You died\n");
				return 0;
			}
		printf("\n");
		switch(j)
		{
				case 1: //добавление абонента
					{
						char name[N]={};
						++M;
						adr=realloc(adr, sizeof(book)*M);
							if (adr==NULL)
							{
								free(adr);
								printf("ошибка выделения памяти");
								break;
							}
						printf("Имя Фамилия:\n");
						fgets(name, N-1, stdin);
						//while ((getchar()!='\n') && (getchar() != EOF));
						name[strlen(name) - 1] = '\0';
						strncpy(adr[M-1].namesurname, name, N);
						printf("Номер телефона:\n");
						scn=scanf("%d%*c", phone);
						if (scn!=1)
							{
								free(adr);
								printf("You died\n");
								return 0;
							}
						adr[M-1].phonenum=*phone;
						printf("Добавлен абонент:\n%s% d\n", adr[M-1].namesurname, adr[M-1].phonenum);
						break;
							
					}
					break;
					
				case 2: //список абонентов
					{
						printf("Список абонентов:\n");					
						for (i=0; i<M; ++i)
							{
								printf("%s %d\n", adr[i].namesurname, adr[i].phonenum);
							}
					}
					break;

				case 3: //поиск абонента
					{
					    printf("Номер телефона\n");
						scn=scanf("%d%*c", &phs);
						if (scn!=1)
							{
								free(adr);
								printf("You died\n");
								return 0;
							}


							for (i=0; i<M; ++i)
							{
								if (phs==adr[i].phonenum)
								{
									printf("Имя фамилия: %s\nНомер телефона: %d\n", adr[i].namesurname, adr[i].phonenum);
								}
							}		
						printf("Не найден =(\n");
						break;
					}

					break;

				case 4: //удаление абонента
					{
						printf("Выберете номер для удаления:\n");
							for (i=0; i<M; ++i)
							{
								printf("%d. %s %d\n", i+1, adr[i].namesurname, adr[i].phonenum); 
							}
						int k;
						scn=scanf("%d%*c", &k);
						if (scn!=1)
							{
								free(adr);
								printf("You died\n");
								return 0;
							}
						if ((k<=0)||(k>M))
							{
								free(adr);
								printf("try again\n");
								break;
							}
						--k;
						memmove(&adr[k], &adr[k+1], sizeof(book)*(M-k));
						--M;
						adr=realloc(adr, sizeof(book)*M);
						if (adr==NULL)
							{
								free(adr);
								printf("ошибка выделения памяти\n");
								break;
							}
						printf("Абонент удален!\n");
					}
					break;

				case 5: //Выход
					{
						return 0;
						free(adr);
					}

					break;

				default:
					{
						printf("Неизвестный пункт меню\n");
						break;
					}
		} 
	}
	free(adr);		
	return 0;
}