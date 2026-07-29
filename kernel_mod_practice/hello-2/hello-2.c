/*
 * hello-2.c - Demonstrating the module_init() and module exit()
 * macros. This is perferred over using init_module() and cleanup_module()
 */
#include <linux/module.h> /* Needed by all modules */
#include <linux/printk.h> /* Needed for pr_info() */
#include <linux/init.h> /* Needed for module_init/module_exit */

static int __init hello_2_init(void)
{
    pr_info("Hello world 2.\n");
    return 0;
}

static void __exit hello_2_exit(void)
{
    pr_info("Goodbye world 2.\n");
}

module_init(hello_2_init);
module_exit(hello_2_exit);

MODULE_DESCRIPTION("A more than simple hello world kernel module");
