#pragma once

#include <string>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

class MongoDB {
private:
    mongocxx::client client;
    mongocxx::database db;
    mongocxx::collection collection;

public:
    MongoDB(const std::string& uri, const std::string& dbName, const std::string& collectionName);

    bool create_table();
    bool insert_name(const std::string& name);
    bool update_name(int id, const std::string& newName);
    bool delete_name(int id);
    void list_all();
};
