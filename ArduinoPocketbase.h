#ifndef PocketBaseArduino_h
#define PocketBaseArduino_h

#include "Arduino.h"
#include "HttpClient.h"

class PocketRecord
{
public:
    PocketRecord(const String &id);
    PocketRecord &expand(const String &fields);

private:
    String recordId;
    String expandFields;
};

class PocketCollection
{
public:
    PocketCollection(const String &name);
    PocketCollection &getList(int page, int perPage, const String &filter);
    PocketCollection &getFullList(const String &sort);
    PocketCollection &getFirstListItem(const String &filter, const String &expand);
    PocketRecord getOne(const String &recordId, const String &expand);

private:
    String collectionName;
    int page;
    int perPage;
    String filter;
    String sort;
    String expand;
};

class PocketBaseArduino
{
public:
    PocketBaseArduino(const String &url);
    bool connect();
    PocketCollection collection(const String &name);

private:
    String apiUrl;
};

#endif
