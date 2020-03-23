#include <mimas/mimas.h>
#include <mimas/mimas_vk.h>
#include <iostream>

#include "file_dialog.hpp"

int main() {
    mimas_init_with_vk();
    
    Mimas_Window_Create_Info window_info;
    window_info.decorated = true;
    window_info.height = 600;
    window_info.width = 800;
    window_info.title = "WinAPI bug - Mimas";
    Mimas_Window* win = mimas_create_window(window_info);
    mimas_show_window(win);

    while (!mimas_close_requested(win)) {

        Mimas_Key_Action state = mimas_get_key(MIMAS_MOUSE_LEFT_BUTTON);
        if (state == MIMAS_KEY_PRESS || state == MIMAS_KEY_REPEAT) {
            std::cout << "true\n";
        } else {
            std::cout << "false\n";
        }

        state = mimas_get_key(MIMAS_MOUSE_RIGHT_BUTTON);
        if (state == MIMAS_KEY_PRESS) {
            FileDialog dialog;
            dialog.show(FileDialog::PickFiles, fs::current_path());
        }

        mimas_poll_events();
    }

    mimas_destroy_window(win);
    mimas_terminate();
}