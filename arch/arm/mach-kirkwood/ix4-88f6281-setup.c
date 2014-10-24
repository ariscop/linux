/*
 * Marvell RD-88F6281 Reference Board Setup
 *
 * This file is licensed under the terms of the GNU General Public
 * License version 2.  This program is licensed "as is" without any
 * warranty of any kind, whether express or implied.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/irq.h>
#include <linux/mtd/nand.h>
#include <linux/mtd/partitions.h>
#include <linux/ata_platform.h>
#include <linux/mv643xx_eth.h>
#include <linux/ethtool.h>
#include <net/dsa.h>
#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <mach/kirkwood.h>
#include <linux/platform_data/mmc-mvsdio.h>
#include "common.h"
#include "mpp.h"

static struct mtd_partition nasix4200d_nand_parts[] = {
	{
		.name = "uboot",
		.offset = 0,
		.size = 655360
	}, {
		.name = "env",
		.offset = MTDPART_OFS_APPEND,
		.size = 65536
	}, {
		.name = "kernel",
		.offset = MTDPART_OFS_APPEND,
		.size = 2293760
	}, {
		.name = "rootfs",
		.offset = MTDPART_OFS_APPEND,
		.size = 30539776
	},
};

static struct mv643xx_eth_platform_data nasix4200d_ge00_data = {
	.phy_addr	= MV643XX_ETH_PHY_ADDR(8),
};

static struct mv643xx_eth_platform_data nasix4200d_ge01_data = {
	.phy_addr	= MV643XX_ETH_PHY_ADDR(9),
};

static struct mv_sata_platform_data nasix4200d_sata_data = {
	.n_ports	= 2,
};

static struct mvsdio_platform_data nasix4200d_mvsdio_data = {
	.gpio_write_protect	= 37,
	.gpio_card_detect	= 38,
};

static unsigned int nasix4200d_mpp_config[] __initdata = {
	MPP37_GPIO,
	MPP38_GPIO,
	0
};

static void __init nasix4200d_init(void)
{
	/*
	 * Basic setup. Needs to be called early.
	 */
	kirkwood_init();
	kirkwood_mpp_conf(nasix4200d_mpp_config);

	kirkwood_nand_init(nasix4200d_nand_parts,
	                   ARRAY_SIZE(nasix4200d_nand_parts),
	                   25);

	kirkwood_ehci_init();

	kirkwood_ge00_init(&nasix4200d_ge00_data);
	kirkwood_ge01_init(&nasix4200d_ge01_data);

	kirkwood_sata_init(&nasix4200d_sata_data);
	kirkwood_sdio_init(&nasix4200d_mvsdio_data);
	kirkwood_uart0_init();
}

static int __init nasix4200d_pci_init(void)
{
	if (machine_is_nasix4200d())
		kirkwood_pcie_init(KW_PCIE0 | KW_PCIE1);

	return 0;
}
subsys_initcall(nasix4200d_pci_init);

MACHINE_START(NASIX4200D, "Iomega NAS ix4-200d")
	/* Maintainer: Andrew Cook <ariscop at gmail.com> */
	.atag_offset	= 0x100,
	.init_machine	= nasix4200d_init,
	.map_io		= kirkwood_map_io,
	.init_early	= kirkwood_init_early,
	.init_irq	= kirkwood_init_irq,
	.init_time	= kirkwood_timer_init,
	.restart	= kirkwood_restart,
MACHINE_END

