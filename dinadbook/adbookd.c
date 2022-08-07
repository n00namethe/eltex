#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>

/*int n;
	printf("Enter size of array\n");
	scanf("%d%*c", &n);
	char*ptr1 = (char*)malloc(n);

		if (NULL==ptr1)
		{
			printf("sold out\n");
			return(1);
		}

			for (int i=0; i<n; ++i)
			{
				ptr1[i]=i;
			}

	printf ("you have a space\n");*/

#define N 20

typedef struct 
{
	char namesurname[N]; //name, second name
	int  phonenum; 	   //phone number
} book;

int main()
{
	int M=3;
	book*adr=NULL;
	adr=malloc(M*sizeof(book));
	if (NULL==adr)
		{
			printf("что-то не получилось\n");
			return(1);
		}

	int i; //Счетчик
	int j; //switch
	char name[N];
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
		scn = scanf("%d%*c", &j);
			if (scn == 0)
			{
				printf("You died\n");
				return 0;
			}
		printf("\n");

		switch(j)
			{
				case 1: //добавление абонента
					{
						++M;
						adr=realloc(adr, sizeof(book)*M);
							if (adr==NULL)
							{
								free(adr);
								printf("что-то случилось");
								break;
							}
						printf("Имя Фамилия:\n");
						fgets(name, N-1, stdin);
						//while ((name = getchar()) != '\n' && name != EOF);
						name[strlen(name) - 1] = '\0';
						strncpy(adr[M-1].namesurname, name, N);
						printf("Номер телефона:\n");
						scanf("%d%*c", phone);
						adr[M-1].phonenum = *phone;
						printf("Добавлен абонент:\n%s% d\n", adr[M-1].namesurname, adr[M-1].phonenum);
						break;
							
					}
					break;
					
				case 2: //список абонентов
					{
					
						for (i=0; i<M; ++i)
							{
								printf("%s %d\n", adr[i].namesurname, adr[i].phonenum);
							}
					}
					break;

				case 3: //поиск абонента
					{
					    printf("Номер телефона\n");
						scanf("%d%*c", &phs);

							for (i=0; i<M; ++i)
							{
								if (phs==adr[i].phonenum)
								{
									printf("Имя фамилия: %s\nНомер телефона: %d\n", adr[i].namesurname, adr[i].phonenum);
								}
							}
						break;
					}

					break;

				case 4: //удаление абонента
					{
						int k;
						printf("Выберете номер для удаления:\n");

							for (i=0; i<M; ++i)
							{
								printf("%d. %s %d\n", i+1, adr[i].namesurname, adr[i].phonenum); 
							}

						scanf("%d%*c", &k);
						
						if ((k <= 0)||(k>M))

							{
							printf("try again\n");
							break;
							}
						--k;
						strncpy(adr[k].namesurname, "0", N);
						adr[k].phonenum=0;
					}

					break;

				case 5: //Выход
					{
						return 0;
					}

					break;

				default:
					{
						printf("Ошибка\n");
						break;
					}
			} 
	}
	free(adr);		
	return 0;
}