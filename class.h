#pragma once
#include <iostream>
#include <string>

using namespace std;

class MediaItem
{
protected:
    string title;
    int rating;
    string genre;

public:
    virtual ~MediaItem() = default;

    int SetTitle(const string& t);
    int SetRating(int r);           // базовий варіант
    int SetRating(double r);        // перевантаження

    int SetGenre(const string& g);

    virtual int ShowInfo();
};

// --- Book ---
class Book : public MediaItem
{
public:
    Book();
};

// --- Movie ---
class Movie : public MediaItem
{
public:
    Movie();
};

// --- Music ---
class Music : public MediaItem
{
protected:
    int duration;

public:
    Music(int d);
    int SetDuration(int d);
    int ShowInfo() override;
};

// --- OnlineMusic ---
class OnlineMusic : public Music
{
public:
    OnlineMusic(int d);
    int ShowInfo() override;
};

// --- OfflineMusic ---
class OfflineMusic : public Music
{
public:
    OfflineMusic(int d);
    int ShowInfo() override;
};

// --- Platform ---
class Platform
{
    string name;
    Music* musicItem;   // композиція через вказівник на базовий клас

public:
    Platform(const string& n, Music* item);

    int SetName(const string& n);
    int Info(const string& recommendation);
};