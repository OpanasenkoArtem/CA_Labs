#include <linux/module.h>
#include <linux/moduleparam.h>
#include "hello.h"

MODULE_LICENSE("Dual BSD/GPL");

static uint count = 1;
module_param(count, uint, 0444);

static int __init hello2_init(void)
{
	uint i;

	if (count > 10) {
		pr_err("count > 10\n");
		return -EINVAL;
	}
	if (count == 0 || count >= 5)
		pr_warn("count is 0 or 5..10\n");

	for (i = 0; i < count; i++)
		print_hello();

	return 0;
}

static void __exit hello2_exit(void) {}

module_init(hello2_init);
module_exit(hello2_exit);