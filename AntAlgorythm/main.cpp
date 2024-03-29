#include <iostream>

#include "antgraphvisualgenerator.h"

/**
 * @brief isCityMap
 * Если true, то генерирует карту для транспортной задачи
 * Если false, то случайный граф с nPlaces вершин
 * и nPathes ребёр
 */
const bool isCityMap = false;
/**
 * @brief isCycle
 * Если true, то является поиском циклического решения, а
 * именно приближенным решением задачи коммивояжёра
 * Если false, то поиск из превой в последнюю вершины графа
 */
const bool isCycle = false;

/**
 * @brief winWidth
 * Ширина окна
 */
const int winWidth = 900;
/**
 * @brief winHeight
 * Высота окна
 */
const int winHeight = 600;

/**
 * @brief nPlaces
 * Количество вершин случайного графа
 */
const int nPlaces = 10;
/**
 * @brief nPathes
 * Количество ребёр случайного графа
 */
const int nPathes = 20;
/**
 * @brief nAnts
 * Количество муравьёв для запуска
 */
const int nAnts = 1000;
/**
 * @brief pheromonPerAnt
 * Параметр Q - количество феромона для одного муравья
 */
const int pheromonPerAnt = 1;
/**
 * @brief pheromonExpire
 * Параметр ro - испарение феромона за ход
 */
const double pheromonExpire = 0.01;
/**
 * @brief distWeight
 * Жадность алгоритма
 */
const double distWeight = 1;
/**
 * @brief pheromonWeight
 * Сталность алгоритма
 */
const double pheromonWeight = 1;

int main(int argc, char **argv){
    QGuiApplication app(argc, argv);
    do{
        std::cout << "\n\n\n";
        AntGraphVisualGenerator gen(
            isCityMap,
            {winWidth, winHeight},
            nPlaces,
            nPathes,
            pheromonPerAnt,
            pheromonExpire,
            distWeight,
            pheromonWeight);

        auto graph = gen.graph();
        if (isCycle)
            graph.autoSpawnAnt(0, nAnts);
        else
            graph.autoSpawnAntFinder(0, winHeight * winWidth / (900) - 1, nAnts);
        graph.printScore();
        graph.finish();
    }while(1);
    return app.exec();
}
