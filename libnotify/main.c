#include <stdio.h>
#include <libnotify/notify.h>
#include <stdlib.h>

int main() {
    const char *appName = "libnotify-demo";
    gboolean result = notify_init(appName);
    if (!result) {
        fprintf(stderr, "Error during initialized libnotify.\n");
        return EXIT_FAILURE;
    }

    NotifyNotification *notifyHello = notify_notification_new ("Title of notification", "This is an example notification.", "dialog-information");
    notify_notification_set_app_name(notifyHello, appName);
    notify_notification_set_category(notifyHello, "category1");
    notify_notification_show (notifyHello, NULL);
    g_object_unref(G_OBJECT(notifyHello));

    notify_uninit();
    return 0;
}