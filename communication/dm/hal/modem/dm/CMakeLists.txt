
fp_open_library()

fp_library_include_directories(
    "${FP_BASE}/hal/modem/dm/inc"
)

fp_open_library_sources(
  src/cJSON.c
  src/aes.c
  src/dm_base64.c
  src/dm_main.c
  src/telecom_dm.c
  src/cmcc_dm.c
  src/unicom_dm.c
)
