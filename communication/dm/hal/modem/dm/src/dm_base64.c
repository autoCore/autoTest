#include <string.h>

#ifndef NULL
#define NULL	0
#endif

// ȫ�ֳ�������
static const char *base64char =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
static const char padding_char = '=';

/*�������
* const unsigned char * sourcedata�� Դ����
* char * base64 �����ֱ���
*/
int dm_base64_encode(const unsigned char *sourcedata, int source_size,
		     char *base64)
{
	int i = 0, j = 0;
	unsigned char trans_index = 0;	// ������8λ�����Ǹ���λ��Ϊ0
	for (; i < source_size; i += 3) {
		// ÿ����һ�飬���б���
		// Ҫ��������ֵĵ�һ��
		trans_index = ((sourcedata[i] >> 2) & 0x3f);
		base64[j++] = base64char[(int)trans_index];
		// �ڶ���
		trans_index = ((sourcedata[i] << 4) & 0x30);
		if (i + 1 < source_size) {
			trans_index |= ((sourcedata[i + 1] >> 4) & 0x0f);
			base64[j++] = base64char[(int)trans_index];
		} else {
			base64[j++] = base64char[(int)trans_index];

			base64[j++] = padding_char;

			base64[j++] = padding_char;

			break;	// �����ܳ��ȣ�����ֱ��break
		}
		// ������
		trans_index = ((sourcedata[i + 1] << 2) & 0x3c);
		if (i + 2 < source_size) {	// �еĻ���Ҫ����2��
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

/* ����
* const char * base64 ����
* unsigned char * dedata�� ����ָ�������
*/
int dm_base64_decode(const char *base64, unsigned char *dedata)
{
	int i = 0, j = 0;
	int trans[4] = { 0, 0, 0, 0 };
	for (; base64[i] != '\0'; i += 4) {
		// ÿ�ĸ�һ�飬����������ַ�
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

	printf("���룺%s\n", base64);

	char dedata[128];

	base64_decode(base64, (unsigned char *)dedata);

	printf("���룺%s", dedata);

	getchar();
	getchar();
	return 0;
}
#endif
