#include<stdio.h>
#include<locale>
#include<math.h>
#include"Header.h"

void vvod(int &cisl1, int &znam1, int &cisl2, int &znam2) {
	printf("\nВведите числитель первой дроби : "); scanf_s("%d", &cisl1);
	printf("\nВведите знаменатель первой дроби : "); scanf_s("%d", &znam1);
	do {
		if (znam1 == 0) { printf("\nТребуется повторный ввод знаменателя : "); scanf_s("%d", &znam1); }
	} while (znam1 == 0);
	printf("\nВведите числитель второй дроби : "); scanf_s("%d", &cisl2);
	printf("\nВведите знаменатель второй дроби : "); scanf_s("%d", &znam2);
	do {
		if (znam2 == 0) { printf("\nТребуется повторный ввод знаменателя : "); scanf_s("%d", &znam2); }
	} while (znam2 == 0);
}

void vivod(int chislob, int znamob) {
	if ((znamob < 0 && chislob < 0) || (znamob < 0 && chislob >0)) {
		chislob *= -1; znamob *= -1;
		printf("\nПроизведение дробей : %d/%d", chislob, znamob);
	}
	else if (chislob == 0)printf("\nОтвет : 0");
	else if (chislob == 1 && znamob == 1)printf("\nОтвет : 1");
	else printf("\nОтвет : %d/%d", chislob, znamob);

}

int sokr(int a, int b) {
	a = abs(a), b = abs(b);
	if (b == 0)return a;
	else return sokr(b, a % b);
}

int main(){
	setlocale(0, "");

	printf("1 - Сложение дробей\n2 - Вычитание дорбей\n3 - Умножение дробей\n4 - Деление дробей\n5 - Сравнение дробей\n6 - Сокращение дробей\n7 - Представление в виде десятичной дроби\n\n");
	printf("Ваш выбор : "); scanf_s("%d", &count);

	switch (count)
	{
	case 1:

		vvod(chisl1, znam1, chisl2, znam2);

		a = sokr(znam1, znam2);

		chisl1 = chisl1*znam2 / a+ chisl2 *znam1/a;
		
		znam1 *= (znam2 / a);

		vivod(chisl1, znam1);
		
		break;
	case 2: 
		vvod(chisl1, znam1, chisl2, znam2);

		a = sokr(znam1, znam2);

		chisl1 = chisl1 * znam2 / a - chisl2 * znam1 / a;

		znam1 *= (znam2 / a);

		vivod(chisl1, znam1);
		
		break;
	case 3:

		vvod(chisl1, znam1, chisl2, znam2);

		chislob = chisl1 * chisl2;
		znamob = znam1 * znam2;

		x = sokr(chislob, znamob);

		chislob /= x;
		znamob /= x;

		vivod(chislob, znamob);

		break;

	case 4:
		vvod(chisl1, znam1, chisl2, znam2);

		chislob = chisl1 * znam2;
		znamob = znam1 * chisl2;

		x = sokr(chislob, znamob);

		chislob /= x;
		znamob /= x;

		vivod(chislob, znamob);
		break;
	case 5:
		vvod(chisl1, znam1, chisl2, znam2);

		a = sokr(znam1, znam2);
		if (chisl1 * znam2 / a < chisl2 * znam1 / a)printf("\nДробь %d/%d  меньше %d/%d", chisl1, znam1, chisl2, znam2);
		else if (chisl1 * znam2 / a > chisl2 * znam1 / a)printf("\nДробь %d/%d  больше %d/%d", chisl2, znam2, chisl1, znam1);
		else printf("\nДробь %d/%d равна дроби %d/%d", chisl1, znam1, chisl2, znam2);
		
		break;
	case 6:
		printf("\nВведите числитель  дроби : "); scanf_s("%d", &chisl1);
		printf("\nВведите знаменатель  дроби : "); scanf_s("%d", &znam1);

		a = sokr(chisl1, znam1);
		printf("\nСокращённая дробь : %d/%d", chisl1 / a, znam1 / a);
		break; 
	case 7:
		printf("\nВведите числитель  дроби : "); scanf_s("%d", &chisl1);
		printf("\nВведите знаменатель  дроби : "); scanf_s("%d", &znam1);
		printf("\nДесятичная дробь : %.3lf", double(chisl1)/znam1);
	default:
		break;
	}
}
