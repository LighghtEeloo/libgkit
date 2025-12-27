#include "../../c_abi/include/application.h"
#include "../../c_abi/include/window.h"

int main() {
    Gkit_Application* app = gkit_application_new();
    Gkit_Window* window = gkit_window_new("Hello", 800, 600);

    gkit_application_delete(app);
    gkit_window_delete(window);

    return 0;
}