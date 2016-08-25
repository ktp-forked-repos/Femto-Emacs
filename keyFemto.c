/*
 * key.c, Femto Emacs, Hugh Barney, Public Domain, 2016
 * Derived from: Anthony's Editor January 93, (Public Domain 1991, 1993 by Anthony Howe)
 */

#include "header.h"

/* desc, keys, func */
keymap_t keymap[] = {
	{"up previous-line         ", "\x1B\x5B\x41", up },
	{"down next-line           ", "\x1B\x5B\x42", down },
	{"left backward-character  ", "\x1B\x5B\x44", left },
	{"right forward-character  ", "\x1B\x5B\x43", right },

	{"C-a beginning-of-line    ", "\x01", lnbegin },
	{"C-e end-of-line          ", "\x05", lnend },
	{"home beginning-of-line   ", "\x1B\x4F\x48", lnbegin }, /* home key */
	{"end end-of-line          ", "\x1B\x4F\x46", lnend }, /* end key */

	{"C-b                      ", "\x02", left },
	{"C-f                      ", "\x06", right },
	{"C-n                      ", "\x0E", down },
	{"C-p                      ", "\x10", up },
 
	{"C-d forward-delete-char  ", "\x04", delete },
	{"INS toggle-overwrite-mode", "\x1B\x5B\x32\x7E", toggle_overwrite_mode }, /* Ins key */
	{"DEL forward-delete-char  ", "\x1B\x5B\x33\x7E", delete }, /* Del key */
	{"backspace delete-left    ", "\x7f", backsp },
	{"C-h backspace            ", "\x08", backsp },
	{"C-l                      ", "\x0C", redraw },

	{"C-u                      ", "\x15", undo },
	{"esc v                    ", "\x1B\x76", pgup },
	{"esc V                    ", "\x1B\x56", pgup },
	{"C-v                      ", "\x16", pgdown },
	{"PgUp                     ", "\x1B\x5B\x35\x7E",pgup }, /* PgUp key */
	{"PgDn                     ", "\x1B\x5B\x36\x7E", pgdown }, /* PgDn key */

	{"esc < beg-of-buf         ", "\x1B\x3C", top },
	{"esc > end-of-buf         ", "\x1B\x3E", bottom },
	{"esc home, beg-of-buf     ", "\x1B\x1B\x4F\x48", top },
	{"esc end, end-of-buf      ", "\x1B\x1B\x4F\x46", bottom },
	{"esc up, beg-of-buf       ", "\x1B\x1B\x5B\x41", top },
	{"esc down, end-of-buf     ", "\x1B\x1B\x5B\x42", bottom },
 
	{"esc b back-word          ", "\x1B\x62", wleft },
	{"esc f forward-word       ", "\x1B\x66", wright },
	{"esc g gotoline           ", "\x1B\x67", gotoline },
	{"esc r query-replace      ", "\x1B\x72", query_replace },

	{"esc B back-word          ", "\x1B\x42", wleft },
	{"esc F forward-word       ", "\x1B\x46", wright },
	{"esc G gotoline           ", "\x1B\x47", gotoline },
	{"esc R query-replace      ", "\x1B\x52", query_replace },

	/* these are not standard emacs bindings but I like them on the ALT key */
	{"esc c copy               ", "\x1B\x63", copy },
	{"esc d killtoeol          ", "\x1B\x64", killtoeol },
	{"esc i paste              ", "\x1B\x69", paste },
	{"esc k killtoeol          ", "\x1B\x6B", killtoeol },
	{"esc m set-mark           ", "\x1B\x6D", iblock },
	{"esc n next-buffer        ", "\x1B\x6E", next_buffer },
	{"esc o delete-other-windows", "\x1B\x6F", delete_other_windows },
                
	{"C-space set-mark         ", "\x00", iblock },  /* ctrl-space */
	{"esc @ set-mark           ", "\x1B\x40", iblock },  /* esc-@ */

	{"C-w kill-region          ", "\x17", cut},
	{"C-y yank                 ", "\x19", paste},
	{"esc w copy-region        ", "\x1B\x77", copy},
	{"esc W copy-region        ", "\x1B\x57", copy},
	{"C-k kill-to-eol          ", "\x0B", killtoeol },
	{"C-s search               ", "\x13", search },
	{"C-r search               ", "\x12", search },
	{"C-o eval region          ", "\x0F", repl },
       
	{"C-x 1 delete-other-window", "\x18\x31", delete_other_windows },
	{"C-x 2 split-window       ", "\x18\x32", split_window },
	{"C-x o other-window       ", "\x18\x6F", next_window },

	{"C-x @ shell-command      ", "\x18\x40", i_shell_command },

	{"C-x = cursor-position    ", "\x18\x3D", showpos },
	{"C-x i insert-file        ", "\x18\x69", insertfile },
	{"C-x k kill-buffer        ", "\x18\x6B", killbuffer },
	{"C-x C-n next-buffer      ", "\x18\x0E", next_buffer },
	{"C-x n next-buffer        ", "\x18\x6E", next_buffer },

	{"C-x C-b list-buffers     ", "\x18\x02", list_buffers },
	{"C-x C-f find-file        ", "\x18\x06", readfile },
	{"C-x C-s save-buffer      ", "\x18\x13", savebuffer },  
	{"C-x C-w write-file       ", "\x18\x17", writefile },  /* write and prompt for name */
	{"C-x C-c exit             ", "\x18\x03", quit_ask },
	{"esc ] eval_block         ", "\x1B\x5D", eval_block },

	{"esc esc show-version     ", "\x1B\x1B", version },

        {"C-c a", "\x03\x61", keyboardDefinition},
        {"C-c b", "\x03\x62", keyboardDefinition},
        {"C-c c", "\x03\x63", keyboardDefinition},
        {"C-c d", "\x03\x64", keyboardDefinition},
        {"C-c e", "\x03\x65", keyboardDefinition},
        {"C-c f", "\x03\x66", keyboardDefinition},
        {"C-c g", "\x03\x67", keyboardDefinition},
        {"C-c h", "\x03\x68", keyboardDefinition},
        {"C-c i", "\x03\x69", keyboardDefinition},
        {"C-c j", "\x03\x6A", keyboardDefinition},
        {"C-c k", "\x03\x6B", keyboardDefinition},
        {"C-c l", "\x03\x6C", keyboardDefinition},
        {"C-c m", "\x03\x6D", keyboardDefinition},
        {"C-c n", "\x03\x6E", keyboardDefinition},
        {"C-c o", "\x03\x6F", keyboardDefinition},
        {"C-c p", "\x03\x70", keyboardDefinition},
        {"C-c q", "\x03\x71", keyboardDefinition},
        {"C-c r", "\x03\x72", keyboardDefinition},
        {"C-c s", "\x03\x73", keyboardDefinition},
        {"C-c t", "\x03\x74", keyboardDefinition},
        {"C-c u", "\x03\x75", keyboardDefinition},
        {"C-c v", "\x03\x76", keyboardDefinition},
        {"C-c w", "\x03\x77", keyboardDefinition},
        {"C-c x", "\x03\x78", keyboardDefinition},
        {"C-c y", "\x03\x79", keyboardDefinition},
        {"C-c z", "\x03\x7A", keyboardDefinition},
	
	{"K_ERROR                  ", NULL, NULL }
};

int getkey(keymap_t *keys, keymap_t **key_return)
{
	keymap_t *k;
	int submatch;
	static char buffer[K_BUFFER_LENGTH];
	static char *record = buffer;

	*key_return = NULL;

	/* if recorded bytes remain, return next recorded byte. */
	if (*record != '\0')
		*key_return = NULL;
	/* reset record buffer. */
	record = buffer;

	do {
		assert(K_BUFFER_LENGTH > record - buffer);
		/* read and record one byte. */
		*record++ = (unsigned)getch();
		*record = '\0';

		/* if recorded bytes match any multi-byte sequence... */
		for (k = keys, submatch = 0; k->lhs != NULL; ++k) {
			char *p, *q;

			for (p = buffer, q = k->lhs; *p == *q; ++p, ++q) {
			        /* an exact match */
				if (*q == '\0' && *p == '\0') {
	    				record = buffer;
					*record = '\0';
					*key_return = k;
					return -1;
				}
			}
			/* record bytes match part of a command sequence */
			if (*p == '\0' && *q != '\0') {
				submatch = 1;
			}
		}
	} while (submatch);
	/* nothing matched, return recorded bytes. */
	record = buffer;
	return (*(unsigned char *)record++);
}

int getinput(char *prompt, char *buf, int nbuf)
{
	int cpos = 0;
	int c;
	int start_col = strlen(prompt); 

	mvaddstr(MSGLINE, 0, prompt);
	clrtoeol();

	/* if we have a default value print it and go to end of it */
	if (buf[0] != '\0') {
		addstr(buf);
		cpos = strlen(buf);
	}

	for (;;) {
		refresh();
		c = getch();
		/* ignore control keys other than backspace, cr, lf */
		if (c < 32 && c != 0x07 && c != 0x08 && c != 0x0a && c != 0x0d)
			continue;

		switch(c) {
		case 0x0a: /* cr, lf */
		case 0x0d:
			buf[cpos] = '\0';
			return (cpos > 0 ? TRUE : FALSE);

		case 0x07: /* ctrl-g */
			return FALSE;

		case 0x7f: /* del, erase */
		case 0x08: /* backspace */
			if (cpos == 0)
				continue;
			
			move(MSGLINE, start_col + cpos - 1);
			addch(' ');
			move(MSGLINE, start_col + cpos - 1);
			buf[--cpos] = '\0';
			break;

		default:	
			if (cpos < nbuf -1) {
				addch(c);
				buf[cpos++] = c;
				buf[cpos] ='\0';
			}
			break;
		}
	}
}
