#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/ktime.h>

MODULE_AUTHOR("Artem Opanasenko");
MODULE_DESCRIPTION("Lab 4");
MODULE_LICENSE("Dual BSD/GPL");

static uint count = 1;
module_param(count, uint, 0644);
MODULE_PARM_DESC(count, "Print count");

struct event {
	struct list_head list;
	ktime_t time;
};

static LIST_HEAD(events);

static int __init hello_init(void)
{
	uint i;
	struct event *ptr;

	if (count > 10) {
		pr_err("count > 10\n");
		return -EINVAL;
	}

	if (count == 0 || count >= 5)
		pr_warn("count is %u\n", count);

	for (i = 0; i < count; i++) {
		ptr = kmalloc(sizeof(*ptr), GFP_KERNEL);
		ptr->time = ktime_get();
		list_add_tail(&ptr->list, &events);
		pr_info("Hello, world!\n");
	}

	return 0;
}

static void __exit hello_exit(void)
{
	struct event *ptr, *tmp;

	list_for_each_entry_safe(ptr, tmp, &events, list) {
		pr_info("Time: %lld ns\n", ktime_to_ns(ptr->time));
		list_del(&ptr->list);
		kfree(ptr);
	}
}

module_init(hello_init);
module_exit(hello_exit);
