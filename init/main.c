#define PAGE_SIZE	4096

long user_stack[PAGE_SIZE >> 2];
struct {
	long *a;
	short b;
} stack_start = {
	&user_stack[PAGE_SIZE >> 2],
	0x10
};

int main(void)
{
	volatile unsigned int foo;

	while (1) {
		foo = 0xbeefcafe;
	}

	return 0;
}
