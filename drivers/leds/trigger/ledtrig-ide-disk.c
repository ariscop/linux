/*
 * LED IDE-Disk Activity Trigger
 *
/* Copyright 2013 bodhi
 *
 * Copyright 2006 Openedhand Ltd.
 * Author: Richard Purdie <rpurdie@openedhand.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/leds.h>

#define BLINK_DELAY 30

DEFINE_LED_TRIGGER(ledtrig_ide1);
DEFINE_LED_TRIGGER(ledtrig_ide2);
static unsigned long ide_blink_delay = BLINK_DELAY;

void ledtrig_ide_activity(int portno)
{
	switch (portno) {
		case 0:
		        led_trigger_blink_oneshot(ledtrig_ide1, &ide_blink_delay, &ide_blink_delay, 0);
			break;
        	case 1:
			led_trigger_blink_oneshot(ledtrig_ide2, &ide_blink_delay, &ide_blink_delay, 0);
			break;
		default:
			break;
	}
}
EXPORT_SYMBOL(ledtrig_ide_activity);

static int __init ledtrig_ide_init(void)
{
	led_trigger_register_simple("ide-disk1", &ledtrig_ide1); 
	led_trigger_register_simple("ide-disk2", &ledtrig_ide2);
	return 0;
}

static void __exit ledtrig_ide_exit(void)
{
	led_trigger_unregister_simple(ledtrig_ide1);
	led_trigger_unregister_simple(ledtrig_ide2);
}

module_init(ledtrig_ide_init);
module_exit(ledtrig_ide_exit);

MODULE_AUTHOR("Richard Purdie <rpurdie@openedhand.com>");
MODULE_DESCRIPTION("LED IDE Disk Activity Trigger");
MODULE_LICENSE("GPL");
