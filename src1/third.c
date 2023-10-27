#include <linux/init.h> 
#include <linux/kernel.h> /* for ARRAY_SIZE() */ 
#include <linux/module.h> 
#include <linux/moduleparam.h> 
#include <linux/printk.h> 
#include <linux/stat.h> 
 
MODULE_LICENSE("GPL"); 
 
static int myage = 420; 
static char *myname = "blah"; 
static int mybirthday[2] = { 420, 420 }; 
static int arr_argc = 0; 
 

module_param(myage, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
module_param(myname, charp, 0000);  
module_param_array(mybirthday, int, &arr_argc, 0000); 

 
static int __init proc_init(void) 
{ 
    
    printk(KERN_INFO "Hellow, World\n");
    pr_info("my age is : %d\n", myage); 
    pr_info("my name is : %s\n", myname); 
    pr_info("my birthday is : %d/%d\n ", mybirthday[0], mybirthday[1]); 
 
    return 0; 
} 
 
static void __exit proc_exit(void) 
{ 
    
    printk(KERN_INFO "Goodbye, World\n");
} 
 
module_init(proc_init); 
module_exit(proc_exit);