#include <windows.h>
#include "class.h"
#include <iostream>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    cout << " Класи \n\n";

    MediaItem* book = new Book();
    cout << "[Book] ";
    book->ShowInfo();
    cout << endl;
    delete book;

    MediaItem* movie = new Movie();
    cout << "[Movie] ";
    movie->ShowInfo();
    cout << endl;
    delete movie;

    Music* music = new Music(5);
    cout << "[Music] ";
    music->ShowInfo();
    cout << endl;
    delete music;

    cout << "\n Похідні класи \n\n";

    
    Music* online = new OnlineMusic(3);
    cout << "[OnlineMusic] ";
    online->ShowInfo();
    cout << endl;
    delete online;

    Music* offline = new OfflineMusic(4);
    cout << "[OfflineMusic] ";
    offline->ShowInfo();
    cout << endl;
    delete offline;

    
    cout << "\n Платформи \n\n";

    Music* platMusic1 = new OnlineMusic(3);
    Platform* plat1 = new Platform("Spotify, ", platMusic1);
    plat1->Info("Рекомендована пісня: Self Aware");
    delete plat1;
    delete platMusic1;

    Music* platMusic2 = new OfflineMusic(4);
    Platform* plat2 = new Platform("Apple Music,", platMusic2);
    plat2->Info("Рекомендована пісня: Self Aware");
    delete plat2;
    delete platMusic2;

    return 0;
}