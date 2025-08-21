#include "MongoDB.hxx"
#include <iostream>

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;

MongoDB::MongoDB(const std::string& uri, const std::string& db_name, const std::string& collection_name)
    : client(mongocxx::uri{ uri }), db(client[db_name]), collection(db[collection_name]) {}


bool MongoDB::create_table() {
    return true;
}

bool MongoDB::insert_name(const std::string& name) {
    static int current_id = 1;

    auto doc = document{}
        << "id" << current_id++
        << "name" << name
        << finalize;

    auto result = collection.insert_one(doc.view());
    return result ? true : false;
}

bool MongoDB::update_name(int id, const std::string& new_name) {
    auto filter = document{} << "id" << id << finalize;
    auto update = document{} << "$set" << document{} << "name" << new_name << finalize;

    auto result = collection.update_one(filter.view(), update.view());
    return result && result->modified_count() > 0;
}

bool MongoDB::delete_name(int id) {
    auto filter = document{} << "id" << id << finalize;
    auto result = collection.delete_one(filter.view());
    return result && result->deleted_count() > 0;
}

void MongoDB::list_all() {
    auto cursor = collection.find({});
    for (auto&& doc : cursor) {
        if (doc["id"] && doc["id"].type() == bsoncxx::type::k_int32) {
            int id = doc["id"].get_int32().value;

            auto name_element = doc["name"];
            if (name_element && name_element.type() == bsoncxx::type::k_utf8) {
                std::string name{ name_element.get_string().value.data(), name_element.get_string().value.size() };

                std::cout << "ID: " << id << " | Name: " << name << "\n";
            }
            else {
                std::cout << "ID: " << id << " | Name: <invalid or missing>\n";
            }
        }
        else {
            std::cout << "Document missing valid 'id' field\n";
        }
    }
}




