#include <stdio.h>
#include <errno.h>

#include <gtk/gtk.h>

#include "constants.h"
#include "windows.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    gtk_init(&argc, &argv);

    create_windows();

    return OK;
}
