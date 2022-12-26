#include "google_password.h"

#include <iostream>

void GooglePassword::insert(const std::string& url,
                            const std::string& login,
                            const std::string& password) {
    if(validPassword(password) && passwords_.find(url) == passwords_.end()){
        Usuario u;
        u.login = login;
        u.password = password;
        passwords_[url] = u;
    }
}

void GooglePassword::remove(const std::string& url) {
  for (auto it = passwords_.begin(); it != passwords_.end(); it++){
    if (it->first == url){
        passwords_.erase(it);
        break;
    }
  }
}


void GooglePassword::update(const std::string& url,
                            const std::string& login,
                            const std::string& old_password,
                            const std::string& new_password) {
    if(validPassword(new_password)){
        for (auto it = passwords_.begin(); it != passwords_.end(); it++){
            if (it->first == url && (it->second).password == old_password){
                (it->second).login = login;
                (it->second).password = new_password;
                break;
            }
        }
    }
}

void GooglePassword::printPasswords() {
    std::cout << passwords_.size() << std::endl;
    for (auto it = passwords_.begin(); it != passwords_.end(); it++){
        std::cout << it->first << ": " << (it->second).login << " and " << (it->second).password << std::endl;
    }
}

bool GooglePassword::validPassword(const std::string& password) const {
    if(password.size() < 6 || password.size() > 50 || (password.find("123456")) != password.npos || (password.find(" ")) != password.npos){
        return false;
    }
    else{
        return true;
    }
}

