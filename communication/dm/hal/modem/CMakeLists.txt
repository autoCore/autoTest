add_subdirectory(at)
add_subdirectory(asr-ril)
add_subdirectory_ifdef(CONFIG_HAL_SUPPORT_DM_REGISTER dm)
fp_include_directories(
    asr-ril
    asr-ril/libasr-ril
    include/telephony
)

fp_sources(
  call.c
  nw.c
  sms.c
  ss.c
  asr_sim.c
  factory_modem.c
  ui_sysbm.c
  ui_hal_data.c
)

if (DEFINED CONFIG_HAL_SUPPORT_DM_REGISTER)
 fp_sources(
   dm_interface.c
 )
endif()
