#include <algorithm>
#include <iostream>
#include <memory>
#include <cstdlib>
#include <cstring>
#include "triangle.h"
#include "TList.h"

void menu()
{
 	std::cout << " \n Выберите действие:" << std::endl;
	std::cout << "1) Добавить треугольник в список" << std::endl;
	std::cout << "2) Удалить треугольник из списка" << std::endl;
	std::cout << "3) Печать списка фигур с помощью std::for_each()" << std::endl;
	std::cout << "0) Выход" << std::endl;
}

uint fc;
void output(std::shared_ptr<TListItem<Triangle>> i) { // функция для цикла for_each
	std::cout << "\n Фигура № " << fc << std::endl;
	i.get()->GetFigure()->Print();
	fc++;
}

int main(void)
{
    int32_t act = 0;
    TList<Triangle> list;
    std::shared_ptr<Triangle> ptr;
    do {
        menu();
        std::cin >> act;
        switch(act) {
             case 1:
                ptr = std::make_shared<Triangle>(std::cin);
                list.Insert(ptr);
                break;
            case 2:
                ptr = list.Erase();
                break;
			case 3:
				if (!list.IsEmpty()) {
					fc = 0;
					std::for_each(list.begin(), list.end(), output); //вывод с помощью  for_each
				}
				else {
					std::cout << "В списке нет фигур." << std::endl;
				}
				break;
            case 0:
                list.Del();
                break;
            default:
                std::cout << "Неопознанная команда." << std::endl;;
                break;
        }
    } while (act);
    return 0;
}
