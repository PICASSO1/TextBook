
/**
 * File Name: example.c
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011519
 *
 * Date: 2019 / 01 / 15
 *
 * Description: 
 * 0. 這是一系列atomic_*()函式的範例；至於什麼是atomic可以參考課本上的說明。
 * 
 * 1. static inline void atomic_add(int i, atomic_t *v); 
 *     把(atomic_t *v)的值增加(int i)。
 *
 * 2. static inline int atomic_add_negative(int i, atomic_t *v); 
 *     把(atomic_t *v)的值增加(int i)，再判斷(atomic_t *v)的值是否為負數；負數回傳1，否則回傳0。
 * 
 * 3. static inline int atomic_add_return(int i, atomic_t *v);
 *     把(atomic_t *v)的值增加(int i)回傳。
 * 
 * 4. static inline int atomic_add_unless(atomic_t *v, int a, int u); 
 *     若(atomic_t *v)的值"不等於"(int u)時，將(int a)加上(atomic_t *v)；若(atomic_t *v)的值"等於"(int u)時，則無動作。
 *     若(atomic_t *v)的值"等於"(int u)時，回傳0；否則回傳非0值。
 * 
 * 5. #define atomic_cmpxchg(v, old, new) (cmpxchg(&((v)->counter), (old), (new)))
 *      首先將old與v所在的記憶體中的值相比較，如果相等，將new存到v所表示的位址單元中；否則不做任何動作。
 * 
 * 6. static inline void atomic_dec(atomic_t *v); 
 *     將(atomic_t *v)的值「減1」。
 * 
 * 7. static inline int atomic_dec_and_test(atomic_t *v); 
 *     將(atomic_t *v)的值「減1」，並判斷(atomic_t *v)的值是否為0；是0回傳1，否則回傳0。
 * 
 * 8. static inline void atomic_inc(atomic_t *v); 
 *      將(atomic_t *v)的值「加1」。
 * 
 * 9. static inline int atomic_inc_and_test(atomic_t *v); 
 *      將(atomic_t *v)的值「加1」，並判斷(atomic_t *v)的值是否為0；是0回傳1，否則回傳0。
 * 
 * a) #define atomic_read(v) ((v)->counter)
 *     讀取v的值。
 * 
 * b) #define atomic_set(v, i) (((v)->counter) = (i))
 *      把v的值設定為i。
 * 
 * c) static inline void atomic_sub(int i, atomic_t *v); 
 *     把(atomic_t *v)的值減少(int i)。
 * 
 * d) static inline int atomic_sub_and_test(int i, atomic_t *v); 
 *     把(atomic_t *v)的值減少(int i)，並判斷(atomic_t *v)的值是否為0；是0回傳1，否則回傳0。
 * 
 * e) static inline int atomic_sub_return(int i, atomic_t *v); 
 *     把(atomic_t *v)的值減少(int i)回傳。
 * 
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Pablo Picasso G. ");
MODULE_DESCRIPTION("ATOMIC_INIT() serial function samples. ");
MODULE_VERSION("1.0.0.build011519");

atomic_t example = ATOMIC_INIT(0);

static int hello_init(void)
{
	int n = 0, old = 3, new = 2;

	printk(KERN_INFO "example driver (ATOMIC_INIT) installed. \n");

	printk(KERN_INFO "atomic_t example = ATOMIC_INIT(0); \n");

	printk(KERN_INFO "atomic_read(&example);                 example = %d \n", atomic_read(&example));

	atomic_inc(&example);
	printk(KERN_INFO "atomic_inc(&example);                  example = %d \n", atomic_read(&example));

	n = atomic_inc_and_test(&example);
	printk(KERN_INFO "atomic_inc_and_test(&example) = %d;     example = %d \n", n, atomic_read(&example));

	atomic_dec(&example);
	printk(KERN_INFO "atomic_dec(&example);                  example = %d \n", atomic_read(&example));

	n = atomic_dec_and_test(&example);
	printk(KERN_INFO "atomic_dec_and_test(&example) = %d;     example = %d \n", n, atomic_read(&example));

	atomic_add(2, &example);
	printk(KERN_INFO "atomic_add(2, &example);               example = %d \n", atomic_read(&example));

	n = atomic_add_return(2, &example); 
	printk(KERN_INFO "atomic_add_return(2, &example) = %d;    example = %d \n", n, atomic_read(&example));

	atomic_sub(2, &example); 
	printk(KERN_INFO "atomic_sub(2, &example);               example = %d \n", atomic_read(&example));
	
	n = atomic_sub_return(2, &example); 
	printk(KERN_INFO "atomic_sub_return(2, &example) = %d;    example = %d \n", n, atomic_read(&example));

	n = atomic_sub_and_test(2, &example);
	printk(KERN_INFO "atomic_sub_and_test(2, &example) = %d;  example = %d \n", n, atomic_read(&example));
	
	n = atomic_add_unless(&example, 4, 2);
	printk(KERN_INFO "atomic_add_unless(&example, 4, 2) = %d; example = %d \n", n, atomic_read(&example));

	atomic_set(&example, 4);
	printk(KERN_INFO "atomic_set(example, 4);                example = %d \n", atomic_read(&example));

	n = atomic_add_negative(2, &example);
	printk(KERN_INFO "atomic_add_negative(2, &example) = %d;  example = %d \n", n, atomic_read(&example));

	n = atomic_cmpxchg(&example, old, new);
	printk(KERN_INFO "atomic_cmpxchg(&example, 3, 2) = %d;    example = %d \n", n, atomic_read(&example));

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "example driver (ATOMIC_INIT) uninstalled. \n");

	return;
}

module_init(hello_init);
module_exit(hello_exit);
