#requirement
INCLUDE(${PLAT_DIR}/macro.cmake)

#list source file using this function "include_sources"
include_sources(SCHED_DRV_SOURCE
		sched.c
		semaphore.c
		thread_id.s
)

add_library_case(sched_lib "" "" ${SCHED_DRV_SOURCE})

