#include <stdio.h>
#include <string.h>

#define N 20
#define M 10


typedef struct 
{
	char a[N]; //name, second name
	int c; 	   //phone number
} book;

int main()
{
	book adr[M]={0};
	int j, z, x = 0; //Счетчики
	char name;
	int phone;
	
	int*t=&phone;
	char*n=&name;

	strncpy(adr[0].a, "Igor Prikhodko", N);
	adr[0].c=74557;

	strncpy(adr[1].a, "Ilya Trishin", N);
	adr[1].c=23453;

	strncpy(adr[2].a, "Efim Glazkov", N);
	adr[2].c=73273;
	for (int i=0; i<3; ++i)
	{
		printf("%s %d\n", adr[i].a, adr[i].c);
	}

	while (1)
	{

		printf("1. Добавить абонента;\n");
		printf("2. Список абонентов;\n");
		printf("3. Найти абонента;\n");
		printf("4. Удалить абонента;\n");
		printf("5. Выход;\n");

		scanf("%d%*c", &j);
		printf("\n");

		switch(j)
			{
			
				case 1: //добавление абонента
					{
						do
							{
								int v = 0;
								printf("Имя Фамилия:\n");
								fgets(n, N, stdin);
								strncpy(adr[v].a, n, N);
								printf("Номер телефона:\n");
								scanf("%d%*c", t);
								adr[v].c = *t;
								printf("Добавлен абонент:\n%s%d\n", adr[v].a, adr[v].c);
								++v;
								printf("Добавить еще?\n1. Да\n2. Нет\n");
								scanf("%d%*c", &x);
								

							} while (x==1);
								
						break;
					}
		
			
				case 2: //список абонентов
					{
					
						for (int l=0; l<M; ++l)
							{
								printf("%d. %s %d\n", z=l+1, adr[l].a, adr[l].c);
							}
					

						break;
					}

				case 3: //поиск абонента
					{
						printf("Введите имя и фамилию\n");
						fgets(n, N, stdin);

							for (int i=0; i<M; ++i)
							{
								if (strcmp (n, adr[i].a)==0)
								{
									printf("Имя фамилия: %s\n", adr[i].a);
									printf("Номер телефона: %d\n", adr[i].c);
								}


							}

						break;							
					
					}







				case 4: //удаление абонента
					{
						int k;
						printf("Выберете номер для удаления:\n");

							for (int l=0; l<M; ++l)
							{
								printf("%d. %s %d\n", z=l+1, adr[l].a, adr[l].c);
							}

						scanf("%d%*c", &k);
						--k;
						strncpy(adr[k].a, "0", N);
						adr[k].c=0;
							for (int l=0; l<M; ++l)
							{
								printf("%d. %s %d\n", z=l+1, adr[l].a, adr[l].c);
							}

						break;

					}

				case 5: //Выход
					{
						return 0;
					}
			}

	}		
	return 0;
}