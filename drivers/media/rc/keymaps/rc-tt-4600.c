/* rc-tt_4600.h - Keytable for Geniatech based TT4600 Remote Controller
 * derived from drivers/media/rc/keymaps/rc-su3000.c
 * Copyright (c) 2013 by Evgeny Plehov <Evgeny Plehov@ukr.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <media/rc-map.h>
#include <linux/module.h>

static struct rc_map_table tt_4600[] = {
       { 0x41, KEY_POWER },
       { 0x42, KEY_SHUFFLE },
       { 0x43, KEY_1 },
       { 0x44, KEY_2 },
       { 0x45, KEY_3 },
       { 0x46, KEY_4 },
       { 0x47, KEY_5 },
       { 0x48, KEY_6 },
       { 0x49, KEY_7 },
       { 0x4a, KEY_8 },
       { 0x4b, KEY_9 },
       { 0x4c, KEY_0 },
       { 0x4d, KEY_UP },
       { 0x4e, KEY_LEFT },
       { 0x4f, KEY_OK },
       { 0x50, KEY_RIGHT },
       { 0x51, KEY_DOWN },
       { 0x52, KEY_INFO },
       { 0x53, KEY_EXIT },
       { 0x54, KEY_RED },
       { 0x55, KEY_GREEN },
       { 0x56, KEY_YELLOW },
       { 0x57, KEY_BLUE },
       { 0x58, KEY_MUTE },
       { 0x59, KEY_TEXT },
       { 0x5a, KEY_MODE },
       { 0x61, KEY_OPTION },
       { 0x62, KEY_EPG },
       { 0x63, KEY_CHANNELUP },
       { 0x64, KEY_CHANNELDOWN },
       { 0x65, KEY_VOLUMEUP },
       { 0x66, KEY_VOLUMEDOWN },
       { 0x67, KEY_SETUP },
       { 0x7a, KEY_RECORD },
       { 0x7b, KEY_PLAY },
       { 0x7c, KEY_STOP },
       { 0x7d, KEY_REWIND },
       { 0x7e, KEY_PAUSE },
       { 0x7f, KEY_FORWARD },
};

static struct rc_map_list tt_4600_map = {
	.map = {
		.scan    = tt_4600,
		.size    = ARRAY_SIZE(tt_4600),
		.rc_type = RC_TYPE_UNKNOWN,     /* Legacy IR type */
		.name    = RC_MAP_TT_4600,
	}
};

static int __init init_rc_map_tt_4600(void)
{
	return rc_map_register(&tt_4600_map);
}

static void __exit exit_rc_map_tt_4600(void)
{
	rc_map_unregister(&tt_4600_map);
}

module_init(init_rc_map_tt_4600)
module_exit(exit_rc_map_tt_4600)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Evgeny Plehov <Evgeny Plehov@ukr.net>");
