/*
 * Realtek RTL8367 ethernet switch driver
 *
 * Copyright (C) 2011 Gabor Juhos <juhosg@openwrt.org>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 */

#ifndef _RTL8367_H
#define _RTL8367_H

#define RTL8367_DRIVER_NAME	"rtl8367"
#define RTL8367B_DRIVER_NAME	"rtl8367b"

enum rtl8367_port_speed {
	RTL8367_PORT_SPEED_10 = 0,
	RTL8367_PORT_SPEED_100,
	RTL8367_PORT_SPEED_1000,
};

struct rtl8367_port_ability {
	int force_mode;
	int nway;
	int txpause;
	int rxpause;
	int link;
	int duplex;
	enum rtl8367_port_speed speed;
};

enum rtl8367_extif_mode {
	RTL8367_EXTIF_MODE_DISABLED = 0,
	RTL8367_EXTIF_MODE_RGMII,
	RTL8367_EXTIF_MODE_MII_MAC,
	RTL8367_EXTIF_MODE_MII_PHY,
	RTL8367_EXTIF_MODE_TMII_MAC,
	RTL8367_EXTIF_MODE_TMII_PHY,
	RTL8367_EXTIF_MODE_GMII,
	RTL8367_EXTIF_MODE_RGMII_33V,
	RTL8367B_EXTIF_MODE_RMII_MAC = 7,
	RTL8367B_EXTIF_MODE_RMII_PHY,
	RTL8367B_EXTIF_MODE_RGMII_33V,
	RTL8367_EXTIF_MODE_SGMII = 9,
	RTL8367_EXTIF_MODE_HSGMII,
};

struct rtl8367_extif_config {
	unsigned int txdelay;
	unsigned int rxdelay;
	enum rtl8367_extif_mode mode;
	struct rtl8367_port_ability ability;
};

#define RTL8367_REG_SDS_INDACS_DATA		0x6602
#define RTL8367_REG_SDS_INDACS_ADR		0x6601
#define RTL8367_REG_SDS_INDACS_CMD		0x6600
#define RTL8367_REG_SDS_MISC			0x1d11
#define RTL8367_CFG_MAC8_SEL_SGMII_OFFSET	6
#define RTL8367_CFG_MAC8_SEL_HSGMII_OFFSET	11
#define RTL8367_CFG_SGMII_FDUP_OFFSET		10
#define RTL8367_CFG_SGMII_SPD_MASK		0x180
#define RTL8367_CFG_SGMII_SPD_SHIFT		7
#define RTL8367_CFG_SGMII_LINK_OFFSET		9
#define RTL8367_CFG_SGMII_TXFC_OFFSET		13
#define RTL8367_CFG_SGMII_RXFC_OFFSET		14

#endif /*  _RTL8367_H */
