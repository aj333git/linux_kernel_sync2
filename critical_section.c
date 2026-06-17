#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/spinlock.h>

static int shared_counter = 0;
static spinlock_t counter_lock;

static int __init cs_init(void)
{
    spin_lock(&counter_lock);      // Enter critical section

    shared_counter++;

    printk(KERN_INFO "counter=%d\n", shared_counter);

    spin_unlock(&counter_lock);    // Exit critical section

    return 0;
}

static void __exit cs_exit(void)
{
    printk(KERN_INFO "module exit\n");
}

module_init(cs_init);
module_exit(cs_exit);

MODULE_LICENSE("GPL");
