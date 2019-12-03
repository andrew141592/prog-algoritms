#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif


//Структура для хранения информации о процессорах.
struct proc
{
	char name[255];
	char prod[255];
	char freq[255];
	char sock[255];
	char tmp[255];

	//статические массивы символов, длинна которых 255
	//грубо говоря, это строки
};

struct proc mass[100];
char poin_to_input[250];
const char *one = "1";
const char *two = "2";
const char *three = "3";
const char *four = "4";
const char *five = "5";
const char *six = "6";
const char *seven = "7";
const char *eight = "8";
char newpoint[255];
int i = 0;
FILE *file;
int menu = 1;
int poin;




void quickSort(proc *mass, int l, int r)
{
    int x = l + (r - l) / 2;
    int i = l;
    int j = r;
    while (i <= j)
    {

        while (strcmp(mass[i].name, mass[x].name) < 0)
            i++;
        while (strcmp(mass[j].name, mass[x].name) > 0)
            j--;
        if (i <= j)
        {
            proc tmp = mass[j];
            mass[j] = mass[i];
            mass[i] = tmp;
            i++;
            j--;
        }
    }
    if (i < r)
        quickSort(mass, i, r);

    if (l < j)
        quickSort(mass, l, j);
}


int LinearSearch (proc* mass, int i, char* newpoint)
{
    for(int j = 0; j < i; j++)
    if(mass[j].name == newpoint)
        return(j);
    return(-1);
}



int _tmain(int argc, _TCHAR* argv[])
{








	//часть, где происходит открытие файла, а если такого файла нет, то его создание
	//проверяет, существует ли такой файл для записи в него информации
	if ((file = fopen("info.txt","rb+")) == NULL)
	{
		//проверяет, возможно ли создать такой файл, для записи
		if ((file = fopen("info.txt","w")) == NULL)
		{
			printf("Файл невозможно открыть или создать\n");
			Sleep(2);
			system("cls");
		}
	}
	else
		while ( fscanf(file, "%s%s%s%s", mass[i].name, mass[i].prod, mass[i].freq, mass[i].sock ) != EOF)
			i++;
		//заполнение массима структур инфомацией из файла с помощью функции fscanf



	//закрытие файла
	fclose(file);

    MENU:
	//меню
	while(menu == 1)
	{

		system("cls");   // очистка консоли
		puts("-----------Menu-------------");
		puts("");  // вывод неформатированного текста
		puts("1. Add new processcor.");
		puts("2. Change one of processors.");
		puts("3. Delete one of processors.");
		puts("4. Show all the list.");
		puts("5. BubleSort.");
		puts("6. HoarSorting.");
		puts("7. LenearSearch.");
		puts("8. Exit.");
		puts("");
		gets(poin_to_input);  // получение значения введенного с клавиатуры


		//проверка на корректность ввода
		if(strcmp (poin_to_input, one)== 0 || strcmp (poin_to_input, two)== 0 ||
		strcmp (poin_to_input, three)== 0 || strcmp (poin_to_input, four)== 0 ||
		strcmp (poin_to_input, five)== 0 || strcmp (poin_to_input, six)== 0 || strcmp (poin_to_input, seven)== 0 || strcmp (poin_to_input, eight)== 0 )
		{
			//преобразование текстовой введенной переменной в числовую
			poin = atoi(poin_to_input);
		}
		else
		{
			system("cls");

			puts("Input Error");

			//задержка окна консоли перед выполнением следующей команды
			Sleep(2);

			//команда для пропуска одной итерации цикла
			continue;
		}


		//оператор разветвления switch
		switch(poin)
		{
			// создание нового элемента
			case 1:
			{
				system("cls");

                puts("Input the processor`s name: ");
				gets(newpoint);
				//функция, чтобы присвоить переменной mass[i].name значение newpoint
				strcpy(mass[i].name, newpoint);

				puts("Input the processor`s manufacturer: ");
				gets(newpoint);
				strcpy(mass[i].prod, newpoint);

				puts("Input the processor`s frequency: ");
				gets(newpoint);
				strcpy(mass[i].freq, newpoint);

				puts("Input the processor`s socket: ");
				gets(newpoint);
				strcpy(mass[i].sock, newpoint);

				i++;

				system("cls");
				puts("Added correctly!");
                Sleep(3);

				break;
				//команда, которая осведетельствует окончание выполнения фрагмента кода
			}
			//редактирование уже существующего элемента
			case 2:
			{
				system("cls");

				puts("Input the processor`s name: ");
				gets(newpoint);

				//циклы для поиска процессора по имени
				for(int j = 0; j < i; j++)
				{
					// функция для проверки сходимости символов и их мест
					// в символьном массиве
					if(strcmp (mass[j].name, newpoint)== 0)
					{
						system("cls");

						puts("Input the processor`s new name:");
						gets(newpoint);
						strcpy(mass[j].name, newpoint);

						puts("");

						puts("Input the processor`s new manufacturer: ");
						gets(newpoint);
						strcpy(mass[j].prod, newpoint);

						puts("");

						puts("Input the processor`s new frequency: ");
						gets(newpoint);
						strcpy(mass[j].freq, newpoint);

						puts("");

						puts("Input the processor`s new socket: ");
						gets(newpoint);
						strcpy(mass[j].sock, newpoint);

						break;
					}
					//проверка для исключения ошибки выхода за пределы массива
					if(j + 1 == i)
					{
						system("cls");
						puts("There is no processors with that name.");
						Sleep(3);
					}
				}

				break;

			}
			//процедурра удаления элемента
			case 3:
			{

				system("cls");

				puts("Input the processor`s name: ");
				gets(newpoint);

				for(int j = 0; j < i; j++)
				{
					if(strcmp (mass[j].name, newpoint)== 0)
					{
						//цикл для замены удаленного элемента еще существующими
						for(int l = j; l < i; l++)
						{
							strcpy(mass[l].name, mass[l+1].name);
							strcpy(mass[l].prod, mass[l+1].prod);
							strcpy(mass[l].freq, mass[l+1].prod);
							strcpy(mass[l].sock, mass[l+1].prod);
						}

						i--;
						system("cls");
						puts("Operation success.");
						Sleep(3);

						break;
					}
					if(j + 1 == i)
					{
						system("cls");
						puts("There is no processors with that name.");
						Sleep(3);
					}
				}





				break;
			}
			//полный вывод информации о всех процессорах
			case 4:
			{
				system("cls");



				//вывод тех самых элементов
				for(int j = 0; j < i; j++)
				{
					printf("%s \t %s \t %s \t %s\n", mass[j].name, mass[j].prod, mass[j].freq, mass[j].sock);
				}
				printf(" \n total number of processors: %d \n", i);

				//функция для остановки выполнения программы до нажатия кнопки
				system("pause");

				break;
			}
			//Выход из программы
			case 8:
			{
				menu = 0;
				break;
			}

			case 5:
                {


                        while(menu == 1)
                            {
                                system("cls");
                                puts("1.Up.");
                                puts("2.Down.");
                                gets(poin_to_input);

                                if((strcmp(poin_to_input,one))==0 || (strcmp(poin_to_input,two))==0)
                                {
                                    poin = atoi(poin_to_input);
                                }
                                else
		{
			system("cls");

			puts("Input Error");

			//задержка окна консоли перед выполнением следующей команды
			Sleep(2);

			//команда для пропуска одной итерации цикла
			continue;
		}
		switch(poin)
		{
        case 1:
            {
                system("cls");

                for (int z = 0; z <= i; z++) {
                    for (int j = i - 1; j > z; j--) {
                        if (strcmp(mass[j].name,mass[j - 1].name) > 0)
                            {
                                proc tmp  = mass[j];
                                mass[j] = mass[j-1];
                                mass[j-1] = tmp;
                            }
                        }
                    }
                    for(int j = 0; j < i; j++)
				{
					printf("%s \t %s \t %s \t %s\n", mass[j].name, mass[j].prod, mass[j].freq, mass[j].sock);
				}
				printf("\n");
				system("pause");
                goto MENU;
            }
        case 2:
            {
                system("cls");

                for (int z = 0; z <= i; z++) {
                    for (int j = i - 1; j > z; j--) {
                        if (strcmp(mass[j].name,mass[j - 1].name) < 0)
                            {
                                proc tmp  = mass[j];
                                mass[j] = mass[j-1];
                                mass[j-1] = tmp;
                            }
                        }
                    }
                    for(int j = 0; j < i; j++)
				{
					printf("%s \t %s \t %s \t %s\n", mass[j].name, mass[j].prod, mass[j].freq, mass[j].sock);
				}
				printf("\n");
				system("pause");
                goto MENU;
            }
		}
                            }












                }

        case 6:
            {
                system("cls");
                quickSort(mass, 0, i - 1 );
                for(int j = 0; j < i; j++)
				{
					printf("%s \t %s \t %s \t %s\n", mass[j].name, mass[j].prod, mass[j].freq, mass[j].sock);
				}
				system("pause");
                break;
            }

        case 7:
            {
                system("cls");
                int j = 0;
                puts("Search:");
                gets(newpoint);
                LinearSearch(mass, j,0);
                printf("%s \t %s \t %s \t %s\n", mass[j].name, mass[j].prod, mass[j].freq, mass[j].sock);
                system("pause");
                break;

            }
		}
    }

	//пересоздание файла для записи в него нового списка информации
   file = fopen("info.txt", "w");

   //цикл, в котором запись в файл с помощью функции fprintf и происходит
   for(int fl = 0;  fl < i; fl++)
   {
		fprintf(file, "%s %s %s %s\n", mass[fl].name, mass[fl].prod, mass[fl].freq, mass[fl].sock);
   }
   fclose(file);

	return 0;
}
