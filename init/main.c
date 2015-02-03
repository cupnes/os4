#define PAGE_SIZE	4096

long user_stack[PAGE_SIZE >> 2];
struct {
	long *a;
	short b;
} stack_start = {
	&user_stack[PAGE_SIZE >> 2],
	0x10
};

#define SCREEN_START	0xb8000
#define COLUMNS	80
#define ATTR	0x07
#define NOW_Y	11
#define NOW_X	0
#define NOW_CHAR	'A'
const unsigned char attr = ATTR;
int main(void)
{
	unsigned long pos;

	pos = SCREEN_START + ((NOW_Y * COLUMNS + NOW_X) << 1);
	__asm__("movb attr,%%ah\n\t"
			"movw %%ax,%1\n\t"
			::"a" (NOW_CHAR), "m" (*(short *)pos));

	return 0;
}
