#include <string.h>

#ifndef NULL
#define NULL	0
#endif

// 全局常量定义
static const char *base64char =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char padding_char = '=';

/*编码代码
* const unsigned char * sourcedata， 源数组
* char * base64 ，码字保存
*/
int dm_base64_encode(const unsigned char *sourcedata, int source_size,
		     char *base64)
{
	int i = 0, j = 0;
	unsigned char trans_index = 0;	// 索引是8位，但是高两位都为0
	for (; i < source_size; i += 3) {
		// 每三个一组，进行编码
		// 要编码的数字的第一个
		trans_index = ((sourcedata[i] >> 2) & 0x3f);
		base64[j++] = base64char[(int)trans_index];
		// 第二个
		trans_index = ((sourcedata[i] << 4) & 0x30);
		if (i + 1 < source_size) {
			trans_index |= ((sourcedata[i + 1] >> 4) & 0x0f);
			base64[j++] = base64char[(int)trans_index];
		} else {
			base64[j++] = base64char[(int)trans_index];

			base64[j++] = padding_char;

			base64[j++] = padding_char;

			break;	// 超出总长度，可以直接break
		}
		// 第三个
		trans_index = ((sourcedata[i + 1] << 2) & 0x3c);
		if (i + 2 < source_size) {	// 有的话需要编码2个
			trans_index |= ((sourcedata[i + 2] >> 6) & 0x03);
			base64[j++] = base64char[(int)trans_index];

			trans_index = sourcedata[i + 2] & 0x3f;
			base64[j++] = base64char[(int)trans_index];
		} else {
			base64[j++] = base64char[(int)trans_index];

			base64[j++] = padding_char;

			break;
		}
	}

	base64[j] = '\0';

	return 0;
}

static int num_strchr(const char *str, char c)
{
	char *pindex = strchr(str, c);
	if (NULL == pindex) {
		return -1;
	}
	return pindex - str;
}

/* 解码
* const char * base64 码字
* unsigned char * dedata， 解码恢复的数据
*/
int dm_base64_decode(const char *base64, unsigned char *dedata)
{
	int i = 0, j = 0;
	int trans[4] = { 0, 0, 0, 0 };
	for (; base64[i] != '\0'; i += 4) {
		// 每四个一组，译码成三个字符
		trans[0] = num_strchr(base64char, base64[i]);
		trans[1] = num_strchr(base64char, base64[i + 1]);
		// 1/3
		dedata[j++] =
		    ((trans[0] << 2) & 0xfc) | ((trans[1] >> 4) & 0x03);

		if (base64[i + 2] == '=') {
			continue;
		} else {
			trans[2] = num_strchr(base64char, base64[i + 2]);
		}
		// 2/3
		dedata[j++] =
		    ((trans[1] << 4) & 0xf0) | ((trans[2] >> 2) & 0x0f);

		if (base64[i + 3] == '=') {
			continue;
		} else {
			trans[3] = num_strchr(base64char, base64[i + 3]);
		}

		// 3/3
		dedata[j++] = ((trans[2] << 6) & 0xc0) | (trans[3] & 0x3f);
	}

	dedata[j] = '\0';

	return 0;
}

#if 0
int main()
{
	const unsigned char str[] = "a45rbcd";
	const unsigned char *sourcedata = str;
	char base64[128];
	base64_encode(sourcedata, base64);

	printf("编码：%s\n", base64);

	char dedata[128];

	base64_decode(base64, (unsigned char *)dedata);

	printf("译码：%s", dedata);

	getchar();
	getchar();
	return 0;
}
#endif
