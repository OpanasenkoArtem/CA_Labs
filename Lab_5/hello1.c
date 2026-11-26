#include <linux/module.h>
#include <linux/slab.h>
#include <linux/list.h>
#include <linux/ktime.h>
#include "hello.h"

MODULE_LICENSE("Dual BSD/GPL");

struct item {
	struct list_head list;
	ktime_t t1, t2;
};

static LIST_HEAD(head);

void print_hello(void)
{
	struct item *p = kmalloc(sizeof(*p), GFP_KERNEL);
	if (!p) {
		pr_err("kmalloc failed\n");
		return;
	}

	p->t1 = ktime_get();
	pr_info("Hello, world!\n");
	p->t2 = ktime_get();

	list_add_tail(&p->list, &head);
}
EXPORT_SYMBOL(print_hello);

static void __exit hello1_exit(void)
{
	struct item *p, *tmp;

	list_for_each_entry_safe(p, tmp, &head, list) {
		pr_info("Time: %lld ns\n", ktime_to_ns(ktime_sub(p->t2, p->t1)));
		list_del(&p->list);
		kfree(p);
	}
}

module_exit(hello1_exit);