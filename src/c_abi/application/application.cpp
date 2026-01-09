#include "../include/application.h"
#include "../../core/include/application.hpp"

struct Gkit_Application {
    gkit::Application* instance;
};

Gkit_Application* gkit_application_new() {
    auto app = new Gkit_Application();
    app->instance = new gkit::Application();
    return app;
}

void gkit_application_delete(Gkit_Application* app_ptr) {
    delete app_ptr->instance;
    delete app_ptr;
}