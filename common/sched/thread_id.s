	.section .text, "x"
	.balign 4

	.global arm_read_thread_id
	.type arm_read_thread_id, %function
arm_read_thread_id:
	MRS x0, TPIDR_EL0
        ret

	.global arm_write_thread_id
	.type arm_write_thread_id, %function
arm_write_thread_id:
        MSR TPIDR_EL0, x0
        ret