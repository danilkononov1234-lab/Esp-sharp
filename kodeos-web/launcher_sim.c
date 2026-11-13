/* Minimal desktop adapter for KodeOS's original launcher screen.
 * Only LVGL/kui are used; no ESP-IDF, QP or FreeRTOS.
 * SPDX-License-Identifier: GPL-3.0-or-later */
#include <stdlib.h>
#include <string.h>
#include "kui_sim.h"
#include "kgui_screens.h"

lv_subject_t *kgui_subject_app_count = NULL;
lv_subject_t *kgui_subject_empty_text = NULL;
lv_subject_t *kgui_subject_loading_text = NULL;
lv_subject_t *kgui_subject_tp_text = NULL;
static char empty_value[256], empty_previous[256];

static lv_obj_t *launcher(void) { return kgui_screen_launcher; }
const kui_sim_screen_t kui_sim_screens[] = {{"launcher", launcher}};
const uint32_t kui_sim_screen_count = 1;

void kui_sim_setup(void)
{
    kgui_subject_app_count = lv_subject_create(LV_SUBJECT_TYPE_INT);
    lv_subject_set_int(kgui_subject_app_count, 0);
    kgui_subject_empty_text = lv_subject_create(LV_SUBJECT_TYPE_STRING);
    lv_subject_set_string_buffer_static(kgui_subject_empty_text, empty_value,
                                         empty_previous, sizeof(empty_value));
    lv_subject_set_string(kgui_subject_empty_text, "No apps yet.        ");
    kgui_screen_launcher_build();
}

bool kui_sim_set(const char *subject, const char *value)
{
    if (strcmp(subject, "app_count") == 0) {
        char *end;
        long count = strtol(value, &end, 10);
        if (*end) return false;
        lv_subject_set_int(kgui_subject_app_count, (int32_t)count);
        return true;
    }
    if (strcmp(subject, "empty_text") == 0) {
        lv_subject_set_string(kgui_subject_empty_text, value);
        return true;
    }
    return false;
}
