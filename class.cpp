#include "class.h"
#include <iostream>
using namespace std;

int MediaItem::SetTitle(const string& t) { title = t; return 1; }
int MediaItem::SetRating(int r) { rating = r; return 1; }
int MediaItem::SetRating(double r) { rating = static_cast<int>(r); return 1; }
int MediaItem::SetGenre(const string& g) { genre = g; return 1; }
int MediaItem::ShowInfo() {
    cout << "Назва: " << title
         << ", Жанр: " << genre
         << ", Рейтинг: " << rating;
    return 1;
}

Book::Book() {
    SetTitle("Виживуть п'ятеро");
    SetGenre("Детектив-триллер");
    SetRating(9);
}


Movie::Movie() {
    SetTitle("Телефон");
    SetGenre("Жахи");
    SetRating(8);
}

Music::Music(int d) {
    SetTitle("Self Aware");
    SetGenre("Інді-рок");
    SetRating(10);
    SetDuration(3);
}

int Music::SetDuration(int d) { duration = d; return 1; }

int Music::ShowInfo() {
    MediaItem::ShowInfo();
    cout << ", Тривалість: " << duration << " хв";
    return 1;
}


OnlineMusic::OnlineMusic(int d) : Music(d) {}

int OnlineMusic::ShowInfo() {
    Music::ShowInfo();
    cout << " (онлайн)";
    return 1;
}


OfflineMusic::OfflineMusic(int d) : Music(d) {}

int OfflineMusic::ShowInfo() {
    Music::ShowInfo();
    cout << " (офлайн)";
    return 1;
}

Platform::Platform(const string& n, Music* item) : musicItem(item) { SetName(n); }

int Platform::SetName(const string& n) { name = n; return 1; }

int Platform::Info(const string& recommendation) {
    cout << "Платформа: " << name
         << ", рекомендація: " << recommendation << endl;
    if (musicItem) musicItem->ShowInfo();
    cout << endl;
    return 1;
}