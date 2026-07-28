/*
 * hello-1.c - The simplest kernel module. 
 * This shouldnt work because this method is depricated
 */
#include <linux/module.h> /* Needed by all modules */
#include <linux/printk.h> /* Needed for pr_info() */

int init_module(void)
{
    pr_info("Hello world 1.\n");
    /* A nonzero return means init_module failed; module can't be loaded. */
                                                                  
    return 0;
}

void cleanup_module(void)
{
    pr_info("Goodbye world 1.\n");
}

