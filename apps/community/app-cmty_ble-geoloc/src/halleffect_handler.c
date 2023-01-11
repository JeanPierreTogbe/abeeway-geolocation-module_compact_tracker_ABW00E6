/*
 * halleffect_handler.c
 *
 *  Created on: Jan 3, 2023
 *      Author: jptogbe
 */
#include "aos_log.h"
#include "aos_board.h"
#include "aos_system.h"
#include "aos_i2c.h"

#include "srv_cli.h"

#include "halleffect_handler.h"



void halleffect_handler_config(aos_gpio_id_t gpio, aos_system_user_callback_t cb)
{
	aos_gpio_config_t gpio_cfg;

	gpio_cfg.mode = aos_gpio_mode_input;
	gpio_cfg.pull = aos_gpio_pull_type_none;
	gpio_cfg.output_type = aos_gpio_output_type_last; // not applicable in input mode
	gpio_cfg.irq_mode = aos_gpio_irq_mode_both_edges;
	gpio_cfg.irq_prio = aos_gpio_irq_priority_medium;
	gpio_cfg.irq_servicing = aos_gpio_irq_service_type_thread;
	gpio_cfg.irq_handler.sys_cb = cb;
	gpio_cfg.user_arg = NULL;
	aos_gpio_open_ext(gpio, &gpio_cfg);
}
