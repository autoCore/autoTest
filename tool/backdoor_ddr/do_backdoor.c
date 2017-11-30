//@for the current algorithm, opposite direction for input/output file is ok.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define 	DEBUG	0

#define MAXLEN (1024*1)
static unsigned char m_buf[MAXLEN];	//speedup rate

#define BIN_MAX_SIZE	(64*1024*1024)
static unsigned char bin_buf[BIN_MAX_SIZE];
static unsigned char ddr_model[BIN_MAX_SIZE];

#define BIT_(__n)       (1<<(__n))
static int do_exchange(const char *bin_buf, char *ddr_model,
		       const long _bytes_cnt, int start_address)
{
	int num = 0;
	int offset = -1;	/*if dst real start address < start_address , for example 0x107f800 -> 0x1079800 */
	int k;
	int dst = 0;
	int max_len = 0;

	while (num < _bytes_cnt) {
		int src_bit =((start_address + num) & (BIT_(12) | BIT_(13) | BIT_(14))) >> 12;
		int address_without_bank = (start_address + num) & ~(BIT_(12) | BIT_(13) | BIT_(14));
		int bit12_bit13_bit14 = ((start_address + num) & (BIT_(12) | BIT_(13) | BIT_(14))) >> 12;
		int bit15_bit16_bit17 = ((start_address + num) & (BIT_(15) | BIT_(16) | BIT_(17))) >> 15;
		int bit18_bit19_bit20 = ((start_address + num) & (BIT_(18) | BIT_(19) | BIT_(20))) >> 18;
		int dst_bit = bit12_bit13_bit14 ^ bit15_bit16_bit17 ^ bit18_bit19_bit20;

		dst = address_without_bank | (dst_bit << 12);
#if DEBUG
		printf("HASH:src_bit = 0x%x, dst_bit=0x%x, copy from src[0x%x] to dst[0x%x]\n",
		     src_bit, dst_bit, (start_address + num), dst);
#endif
		if (offset == -1) {	//Only for first char, align to zero of dst array
			offset = start_address - dst;
			printf("src begin[0x%x] mapping to dst begin[0x%x]\n\r", start_address, dst);
			if (start_address > dst)
				printf("dst start addr < source start addr, You should adjust loader addr for directly backdoor load!\n\r");
		}
		k = dst - start_address + offset;
		if (k >= BIN_MAX_SIZE) {
			printf("ERROR: the dst buffer is not enough\n\r");
			exit(1);
		}
		ddr_model[k] = bin_buf[num];
		if (k > max_len)
			max_len = k;
		num += 1;
	}
	return max_len + 1;
}

char *test_file = "default.binary";
static void gen_test_file(int bytes_cnt)
{
	int i = 0;
	FILE *outfile = fopen(test_file, "wb");
	bytes_cnt = bytes_cnt / 4;
	while (bytes_cnt--) {
		int c = 0;
		c = i * 4;	//address
		fwrite(&c, sizeof(unsigned int), 1, outfile);
		i++;
	}
	fclose(outfile);
}

int main(int argc, char *argv[])
{
	FILE *outfile = NULL, *infile = NULL;
	long bytes_cnt = 0;
	int ddr_start_addr = 0;
	int out_size = 0;

	if (argc < 2 || argc > 4) {
ERR:
		printf("usages: %s %s\n\r", argv[0],
		       "in_file_name out_file_name option_ddr_start_address_default_0x0");
		printf
		    ("Testing mode: Using address patter for input file, usages: %s %s\n\r",
		     argv[0], "out_file_name");
		exit(1);
	}
	if (argc == 2) {
		gen_test_file(1024 * 1024 * 1);
		infile = fopen(argv[1], "rb");
		outfile = fopen(test_file, "wb");
	} else if (argc >= 3) {
		infile = fopen(argv[1], "rb");
		outfile = fopen(argv[2], "wb");
	}
	if (argc == 4)
		ddr_start_addr = strtol(argv[3], NULL, 16);

	if (outfile == NULL || infile == NULL) {
		printf("%s or %s %s", argv[1], argv[2], "not exit\n");
		exit(1);
	}
	int rc;
	while ((rc = fread(m_buf, sizeof(unsigned char), MAXLEN, infile)) != 0) {
		int i = 0;
		while (rc--) {
			bin_buf[bytes_cnt++] = m_buf[i];
			i++;
		}
	}
	fclose(infile);

	out_size = do_exchange(bin_buf, ddr_model, bytes_cnt, ddr_start_addr);
	fwrite(ddr_model, sizeof(unsigned char), out_size, outfile);
	fclose(outfile);

	return 0;
}
