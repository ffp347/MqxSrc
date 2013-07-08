#!/bin/sh

# expect forward slash paths
MQXROOTDIR="${1}"
OUTPUTDIR="${2}"
TOOL="${3}"

# remove processor expert files if exists
rm -rf "${OUTPUTDIR}/Generated_Code"
rm -rf "${OUTPUTDIR}/Sources"

# copy common files
mkdir -p "${OUTPUTDIR}"
mkdir -p "${OUTPUTDIR}/.."
mkdir -p "${OUTPUTDIR}/Generated_Code"
mkdir -p "${OUTPUTDIR}/tss"
cp -f "${MQXROOTDIR}/config/common/maximum_config.h" "${OUTPUTDIR}/../maximum_config.h"
cp -f "${MQXROOTDIR}/config/common/small_ram_config.h" "${OUTPUTDIR}/../small_ram_config.h"
cp -f "${MQXROOTDIR}/config/common/smallest_config.h" "${OUTPUTDIR}/../smallest_config.h"
cp -f "${MQXROOTDIR}/config/common/verif_enabled_config.h" "${OUTPUTDIR}/../verif_enabled_config.h"
cp -f "${MQXROOTDIR}/config/twrk60n512/user_config.h" "${OUTPUTDIR}/../user_config.h"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/bsp.h" "${OUTPUTDIR}/bsp.h"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/bsp_cm.h" "${OUTPUTDIR}/bsp_cm.h"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/bsp_rev.h" "${OUTPUTDIR}/bsp_rev.h"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/init_lpm.h" "${OUTPUTDIR}/init_lpm.h"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/PE_LDD.h" "${OUTPUTDIR}/Generated_Code/PE_LDD.h"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/TSS_SystemSetup.h" "${OUTPUTDIR}/TSS_SystemSetup.h"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/twrk60n512.h" "${OUTPUTDIR}/twrk60n512.h"
cp -f "${MQXROOTDIR}/mqx/source/include/mqx.h" "${OUTPUTDIR}/mqx.h"
cp -f "${MQXROOTDIR}/mqx/source/io/adc/adc.h" "${OUTPUTDIR}/adc.h"
cp -f "${MQXROOTDIR}/mqx/source/io/adc/adc_conf.h" "${OUTPUTDIR}/adc_conf.h"
cp -f "${MQXROOTDIR}/mqx/source/io/adc/kadc/adc_kadc.h" "${OUTPUTDIR}/adc_kadc.h"
cp -f "${MQXROOTDIR}/mqx/source/io/adc/kadc/adc_mk60.h" "${OUTPUTDIR}/adc_mk60.h"
cp -f "${MQXROOTDIR}/mqx/source/io/can/flexcan/kflexcan.h" "${OUTPUTDIR}/kflexcan.h"
cp -f "${MQXROOTDIR}/mqx/source/io/cm/cm.h" "${OUTPUTDIR}/cm.h"
cp -f "${MQXROOTDIR}/mqx/source/io/cm/cm_kinetis.h" "${OUTPUTDIR}/cm_kinetis.h"
cp -f "${MQXROOTDIR}/mqx/source/io/debug/iodebug.h" "${OUTPUTDIR}/iodebug.h"
cp -f "${MQXROOTDIR}/mqx/source/io/enet/enet.h" "${OUTPUTDIR}/enet.h"
cp -f "${MQXROOTDIR}/mqx/source/io/enet/enet_rev.h" "${OUTPUTDIR}/enet_rev.h"
cp -f "${MQXROOTDIR}/mqx/source/io/enet/enet_wifi.h" "${OUTPUTDIR}/enet_wifi.h"
cp -f "${MQXROOTDIR}/mqx/source/io/enet/ethernet.h" "${OUTPUTDIR}/ethernet.h"
cp -f "${MQXROOTDIR}/mqx/source/io/enet/macnet/macnet_1588.h" "${OUTPUTDIR}/macnet_1588.h"
cp -f "${MQXROOTDIR}/mqx/source/io/enet/macnet/macnet_mk60.h" "${OUTPUTDIR}/macnet_mk60.h"
cp -f "${MQXROOTDIR}/mqx/source/io/enet/macnet/macnet_rev.h" "${OUTPUTDIR}/macnet_rev.h"
cp -f "${MQXROOTDIR}/mqx/source/io/enet/phy/phy_ksz8041.h" "${OUTPUTDIR}/phy_ksz8041.h"
cp -f "${MQXROOTDIR}/mqx/source/io/esdhc/esdhc.h" "${OUTPUTDIR}/esdhc.h"
cp -f "${MQXROOTDIR}/mqx/source/io/flashx/flashx.h" "${OUTPUTDIR}/flashx.h"
cp -f "${MQXROOTDIR}/mqx/source/io/flashx/freescale/flash_ftfl.h" "${OUTPUTDIR}/flash_ftfl.h"
cp -f "${MQXROOTDIR}/mqx/source/io/flashx/freescale/flash_mk60.h" "${OUTPUTDIR}/flash_mk60.h"
cp -f "${MQXROOTDIR}/mqx/source/io/gpio/io_gpio.h" "${OUTPUTDIR}/io_gpio.h"
cp -f "${MQXROOTDIR}/mqx/source/io/gpio/kgpio/io_gpio_kgpio.h" "${OUTPUTDIR}/io_gpio_kgpio.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/btnled.h" "${OUTPUTDIR}/btnled.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/derivative.h" "${OUTPUTDIR}/derivative.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/hmi_client.h" "${OUTPUTDIR}/hmi_client.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/hmi_lwgpio_provider.h" "${OUTPUTDIR}/hmi_lwgpio_provider.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/hmi_provider.h" "${OUTPUTDIR}/hmi_provider.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/hmi_tss_provider.h" "${OUTPUTDIR}/hmi_tss_provider.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/hmi_uids.h" "${OUTPUTDIR}/hmi_uids.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_API.h" "${OUTPUTDIR}/tss/TSS_API.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_DataTypes.h" "${OUTPUTDIR}/tss/TSS_DataTypes.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_GPIO.h" "${OUTPUTDIR}/tss/TSS_GPIO.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_Sensor.h" "${OUTPUTDIR}/tss/TSS_Sensor.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_SensorGPIO.h" "${OUTPUTDIR}/tss/TSS_SensorGPIO.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_SensorTSI.h" "${OUTPUTDIR}/tss/TSS_SensorTSI.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_SensorTSIL.h" "${OUTPUTDIR}/tss/TSS_SensorTSIL.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_StatusCodes.h" "${OUTPUTDIR}/tss/TSS_StatusCodes.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_SystemSetupVal.h" "${OUTPUTDIR}/tss/TSS_SystemSetupVal.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/shared/TSS_Timer.h" "${OUTPUTDIR}/tss/TSS_Timer.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hwtimer/hwtimer.h" "${OUTPUTDIR}/hwtimer.h"
cp -f "${MQXROOTDIR}/mqx/source/io/hwtimer/hwtimer_pit.h" "${OUTPUTDIR}/hwtimer_pit.h"
cp -f "${MQXROOTDIR}/mqx/source/io/i2c/i2c.h" "${OUTPUTDIR}/i2c.h"
cp -f "${MQXROOTDIR}/mqx/source/io/i2c/i2c_ki2c.h" "${OUTPUTDIR}/i2c_ki2c.h"
cp -f "${MQXROOTDIR}/mqx/source/io/i2s/i2s.h" "${OUTPUTDIR}/i2s.h"
cp -f "${MQXROOTDIR}/mqx/source/io/i2s/i2s_audio.h" "${OUTPUTDIR}/i2s_audio.h"
cp -f "${MQXROOTDIR}/mqx/source/io/i2s/i2s_ki2s.h" "${OUTPUTDIR}/i2s_ki2s.h"
cp -f "${MQXROOTDIR}/mqx/source/io/io_dun/io_dun.h" "${OUTPUTDIR}/io_dun.h"
cp -f "${MQXROOTDIR}/mqx/source/io/io_mem/io_mem.h" "${OUTPUTDIR}/io_mem.h"
cp -f "${MQXROOTDIR}/mqx/source/io/io_null/io_null.h" "${OUTPUTDIR}/io_null.h"
cp -f "${MQXROOTDIR}/mqx/source/io/lpm/lpm.h" "${OUTPUTDIR}/lpm.h"
cp -f "${MQXROOTDIR}/mqx/source/io/lpm/lpm_kinetis.h" "${OUTPUTDIR}/lpm_kinetis.h"
cp -f "${MQXROOTDIR}/mqx/source/io/lwgpio/lwgpio.h" "${OUTPUTDIR}/lwgpio.h"
cp -f "${MQXROOTDIR}/mqx/source/io/lwgpio/lwgpio_kgpio.h" "${OUTPUTDIR}/lwgpio_kgpio.h"
cp -f "${MQXROOTDIR}/mqx/source/io/pcb/io_pcb.h" "${OUTPUTDIR}/io_pcb.h"
cp -f "${MQXROOTDIR}/mqx/source/io/pcb/mqxa/pcb_mqxa.h" "${OUTPUTDIR}/pcb_mqxa.h"
cp -f "${MQXROOTDIR}/mqx/source/io/pcb/mqxa/pcbmqxav.h" "${OUTPUTDIR}/pcbmqxav.h"
cp -f "${MQXROOTDIR}/mqx/source/io/pccard/apccard.h" "${OUTPUTDIR}/apccard.h"
cp -f "${MQXROOTDIR}/mqx/source/io/pccard/pccardflexbus.h" "${OUTPUTDIR}/pccardflexbus.h"
cp -f "${MQXROOTDIR}/mqx/source/io/pcflash/apcflshpr.h" "${OUTPUTDIR}/apcflshpr.h"
cp -f "${MQXROOTDIR}/mqx/source/io/pcflash/ata.h" "${OUTPUTDIR}/ata.h"
cp -f "${MQXROOTDIR}/mqx/source/io/pcflash/pcflash.h" "${OUTPUTDIR}/pcflash.h"
cp -f "${MQXROOTDIR}/mqx/source/io/pipe/io_pipe.h" "${OUTPUTDIR}/io_pipe.h"
cp -f "${MQXROOTDIR}/mqx/source/io/rtc/krtc.h" "${OUTPUTDIR}/krtc.h"
cp -f "${MQXROOTDIR}/mqx/source/io/rtc/rtc.h" "${OUTPUTDIR}/rtc.h"
cp -f "${MQXROOTDIR}/mqx/source/io/sdcard/sdcard.h" "${OUTPUTDIR}/sdcard.h"
cp -f "${MQXROOTDIR}/mqx/source/io/sdcard/sdcard_esdhc/sdcard_esdhc.h" "${OUTPUTDIR}/sdcard_esdhc.h"
cp -f "${MQXROOTDIR}/mqx/source/io/sdcard/sdcard_spi/sdcard_spi.h" "${OUTPUTDIR}/sdcard_spi.h"
cp -f "${MQXROOTDIR}/mqx/source/io/serial/serial.h" "${OUTPUTDIR}/serial.h"
cp -f "${MQXROOTDIR}/mqx/source/io/serial/serl_kuart.h" "${OUTPUTDIR}/serl_kuart.h"
cp -f "${MQXROOTDIR}/mqx/source/io/spi/spi.h" "${OUTPUTDIR}/spi.h"
cp -f "${MQXROOTDIR}/mqx/source/io/spi/spi_dspi.h" "${OUTPUTDIR}/spi_dspi.h"
cp -f "${MQXROOTDIR}/mqx/source/io/tchres/tchres.h" "${OUTPUTDIR}/tchres.h"
cp -f "${MQXROOTDIR}/mqx/source/io/tfs/tfs.h" "${OUTPUTDIR}/tfs.h"
cp -f "${MQXROOTDIR}/mqx/source/io/timer/qpit.h" "${OUTPUTDIR}/qpit.h"
cp -f "${MQXROOTDIR}/mqx/source/io/timer/timer_lpt.h" "${OUTPUTDIR}/timer_lpt.h"
cp -f "${MQXROOTDIR}/mqx/source/io/timer/timer_qpit.h" "${OUTPUTDIR}/timer_qpit.h"
cp -f "${MQXROOTDIR}/mqx/source/io/usb/if_dev_ehci.h" "${OUTPUTDIR}/if_dev_ehci.h"
cp -f "${MQXROOTDIR}/mqx/source/io/usb/if_dev_khci.h" "${OUTPUTDIR}/if_dev_khci.h"
cp -f "${MQXROOTDIR}/mqx/source/io/usb/if_host_ehci.h" "${OUTPUTDIR}/if_host_ehci.h"
cp -f "${MQXROOTDIR}/mqx/source/io/usb/if_host_khci.h" "${OUTPUTDIR}/if_host_khci.h"
cp -f "${MQXROOTDIR}/mqx/source/io/usb/usb_bsp.h" "${OUTPUTDIR}/usb_bsp.h"


# cw10 files
if [ "${TOOL}" = "cw10" ]; then
mkdir -p "${OUTPUTDIR}/../../dbg"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/cw/dbg/init_kinetis.tcl" "${OUTPUTDIR}/../../dbg/init_kinetis.tcl"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/cw/dbg/mass_erase_kinetis.tcl" "${OUTPUTDIR}/../../dbg/mass_erase_kinetis.tcl"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/cw/dbg/twrk60n512.mem" "${OUTPUTDIR}/../../dbg/twrk60n512.mem"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/cw/extmram.lcf" "${OUTPUTDIR}/extmram.lcf"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/cw/intflash.lcf" "${OUTPUTDIR}/intflash.lcf"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/cw/intram.lcf" "${OUTPUTDIR}/intram.lcf"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/lib_cw/TSS_KXX_M4.a" "${OUTPUTDIR}/tss.a"
fi
# iar files
if [ "${TOOL}" = "iar" ]; then
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/iar/intflash.icf" "${OUTPUTDIR}/intflash.icf"
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/iar/ram.icf" "${OUTPUTDIR}/ram.icf"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/lib_iar/TSS_KXX_M4.a" "${OUTPUTDIR}/tss.a"
fi
# cw10gcc files
if [ "${TOOL}" = "cw10gcc" ]; then
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/gcc_cw/intflash.ld" "${OUTPUTDIR}/intflash.ld"
fi
# uv4 files
if [ "${TOOL}" = "uv4" ]; then
cp -f "${MQXROOTDIR}/mqx/source/bsp/twrk60n512/uv4/intflash.scf" "${OUTPUTDIR}/intflash.scf"
cp -f "${MQXROOTDIR}/mqx/source/io/hmi/TSS/lib_uv4/TSS_KXX_M4.lib" "${OUTPUTDIR}/tss.lib"
fi

