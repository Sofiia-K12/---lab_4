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
    int SetRating(int r);
    int SetRating(double r);
    int SetGenre(const string& g);

    virtual int ShowInfo();
};

class Book : public MediaItem {
public:
    Book();
};

class Movie : public MediaItem {
public:
    Movie();
};

class Music : public MediaItem
{
protected:
    int duration;

public:
    Music(int d);
    int SetDuration(int d);
    int ShowInfo() override;
};

class OnlineMusic : public Music
{
public:
    OnlineMusic(int d);
    int ShowInfo() override;
};

class OfflineMusic : public Music
{
public:
    OfflineMusic(int d);
    int ShowInfo() override;
};

class Platform
{
    string name;
    Music* musicItem;  

public:
    Platform(const string& n, Music* item);
    int SetName(const string& n);
    int Info(const string& recommendation);
};