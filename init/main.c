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
const unsigned char attr = ATTR;
void put_char(char c, unsigned char x, unsigned char y)
{
	unsigned long pos;

	pos = SCREEN_START + ((y * COLUMNS + x) << 1);
	__asm__("movb attr,%%ah\n\t"
			"movw %%ax,%1\n\t"
			::"a" (c), "m" (*(short *)pos));
}

int main(void)
{
	put_char('A', 0, 0);

	return 0;
}
