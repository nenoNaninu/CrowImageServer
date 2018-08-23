#include <iostream>
#include "crow.h"

int main() {

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "I want eat nooooodle!!!";
    });

    app.port(8080).multithreaded().run();
}
