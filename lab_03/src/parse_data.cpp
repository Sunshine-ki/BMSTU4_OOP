#include "parse_data.h"

int parseData(double args[3], GtkWidget *entries[3])
{
	char userAnswer[64];

	for (size_t i = 0; i < 3; i++)
	{
		strcpy(userAnswer, gtk_entry_get_text(GTK_ENTRY(entries[i])));
		if (!strcmp(userAnswer, ""))
			return Errors::EMPTY_INPUT;
		if (strpbrk(userAnswer, STRING_ERROR_INPUT) != NULL)
			return Errors::INPUT_SYMBOL;
		args[i] = atof(userAnswer);
	}

	return OK;
}