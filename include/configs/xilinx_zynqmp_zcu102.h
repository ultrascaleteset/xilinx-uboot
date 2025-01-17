/*
 * Configuration for Xilinx ZynqMP zcu102
 *
 * (C) Copyright 2015 Xilinx, Inc.
 * Michal Simek <michal.simek@xilinx.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_ZYNQMP_ZCU102_H
#define __CONFIG_ZYNQMP_ZCU102_H

#define CONFIG_ZYNQ_SDHCI1
#define CONFIG_ZYNQ_I2C0
#define CONFIG_ZYNQ_I2C1
#define CONFIG_SYS_I2C_MAX_HOPS		1
#define CONFIG_SYS_NUM_I2C_BUSES	18
#define CONFIG_SYS_I2C_BUSES	{ \
				{0, {I2C_NULL_HOP} }, \
				{0, {{I2C_MUX_PCA9544, 0x75, 0} } }, \
				{0, {{I2C_MUX_PCA9544, 0x75, 1} } }, \
				{0, {{I2C_MUX_PCA9544, 0x75, 2} } }, \
				{1, {I2C_NULL_HOP} }, \
				{1, {{I2C_MUX_PCA9548, 0x74, 0} } }, \
				{1, {{I2C_MUX_PCA9548, 0x74, 1} } }, \
				{1, {{I2C_MUX_PCA9548, 0x74, 2} } }, \
				{1, {{I2C_MUX_PCA9548, 0x74, 3} } }, \
				{1, {{I2C_MUX_PCA9548, 0x74, 4} } }, \
				{1, {{I2C_MUX_PCA9548, 0x75, 0} } }, \
				{1, {{I2C_MUX_PCA9548, 0x75, 1} } }, \
				{1, {{I2C_MUX_PCA9548, 0x75, 2} } }, \
				{1, {{I2C_MUX_PCA9548, 0x75, 3} } }, \
				{1, {{I2C_MUX_PCA9548, 0x75, 4} } }, \
				{1, {{I2C_MUX_PCA9548, 0x75, 5} } }, \
				{1, {{I2C_MUX_PCA9548, 0x75, 6} } }, \
				{1, {{I2C_MUX_PCA9548, 0x75, 7} } }, \
				}

#define CONFIG_SYS_I2C_ZYNQ
#define CONFIG_PCA953X
#define CONFIG_CMD_PCA953X
#define CONFIG_CMD_PCA953X_INFO

#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN	1
#define CONFIG_CMD_EEPROM
#define CONFIG_ZYNQ_EEPROM_BUS		5
#define CONFIG_ZYNQ_GEM_EEPROM_ADDR	0x54
#define CONFIG_ZYNQ_GEM_I2C_MAC_OFFSET	0x20

#include <configs/xilinx_zynqmp.h>

/* Fix for FMC voltage being set to 0.0V by system controller */
#undef CONFIG_EXTRA_ENV_SETTINGS
#define CONFIG_EXTRA_ENV_SETTINGS \
	EXTRA_ENV_SETTINGS \
	"zcu102_set_vadj_fmc=i2c dev 3 && " \
		"i2c mt 18 02 10 b && " \
		"i2c mt 18 21 1ccf w && " \
		"i2c mt 18 02 00 b\0"

#undef  CONFIG_PREBOOT
#define CONFIG_PREBOOT		"run setup && run zcu102_set_vadj_fmc"

#endif /* __CONFIG_ZYNQMP_ZCU102_H */
