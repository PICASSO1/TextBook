#ifndef	_EXAMPLE_H_
#define	_EXAMPLE_H_

/**
 * File Name: example.c, example.h
 *
 * CopyLeft (C) 2018-2019, Picasso's Fantasy Notepad. All rights reserved.
 *
 * Author: Pablo Picasso G. (PabloPicasso.G@gmail.com)
 *
 * Version: 1.0.0.build011719
 *
 * Date: 2019 / 01 / 17
 *
 * Description: 
 * 1. 這一支Kernel Space的程序很簡單：當一支User Space的Process存取同一個模組 (同一個Major ID)，但不同的設備時 (Minor ID不一樣)，
 *     程式碼應該如何撰寫。同時也呈現了copy_to_user(), copy_from_user(), access_ok()和capable()這4個函式的用法。
 * 
 * 2. Make完之後，會產生4個Device設備檔：
 *     /dev/example0 c 250 6
 *     /dev/example1 c 250 7
 *     /dev/example2 c 250 8
 *     /dev/example3 c 250 9
 *     但是只能夠存取example1和example2；User Process執行./user (0~3) 就可以指定要執行那一個設備檔。
 * 
 * 3. 執行了之後，User Process會透過ioctl()和write()函式把"Hello!! World!! "寫給模組；然後再用ioctl()和read()函式再把資料從模組中讀回來
 *      ，以驗證程式是否正確。這些函式的用法和說明如下：
 * 
 * 4. int get_user(x, ptr); 
 *     #define get_user(x, ptr) \
 *     ({ \
 *         might_sleep(); \
 *         access_ok(VERIFY_READ, ptr, sizeof(*ptr))? __get_user(x, ptr): -EFAULT; \
 *     })
 *     「讀取1, 2, 4 Bytes的小資料」。讀取User Process的指標ptr所指的資料放到x變數內。成功的話會傳回0，失敗的話會傳回負數錯誤巨集「-EFAULT」。
 * 
 * 5. int put_user(x, ptr); 
 *     #define put_user(x, ptr) \
 *     ({ \
 *         might_sleep(); \
 *         access_ok(VERIFY_WRITE, ptr, sizeof(*ptr))? __put_user(x, ptr): -EFAULT; \
 *     })
 *     「寫入1, 2, 4 Bytes的小資料」。將x變數的資料寫入User Process指標ptr指向的位置。成功的話會傳回0，失敗的話會傳回負數錯誤巨集「-EFAULT」。
 * 
 * 6. int access_ok(int type, void *addr, unsigned long size); 
 *     檢查User Process的ptr指標指到，長度為size的記憶體空間是否可以讀寫。type引數可以忽視，指定驗證可否讀取的VERIFY_READ，或驗證
 *     可否寫入的VERIFY_WRITE。成功的話會傳回非0，失敗的話會傳回0。
 * 
 * 7. static inline long copy_from_user(void *to, const void __user * from, unsigned long n)
 *     {
 *         might_sleep();
 *         if (access_ok(VERIFY_READ, from, n))
 *             return __copy_from_user(to, from, n);
 *         else
 *             return n;
 *     }
 *     從User Process的from指標把長度n的資料複製到Kernel Space的to指標。成功的話會傳回非0，失敗的話會傳回無法複製的資料長度。
 * 
 * 8. static inline long copy_to_user(void __user *to, const void *from, unsigned long n)
 *     {
 *         might_sleep();
 *         if (access_ok(VERIFY_WRITE, to, n))
 *             return __copy_to_user(to, from, n);
 *         else
 *             return n;
 *     }
 *     從Kernel Space的from指標把長度n的資料複製到User Process的to指標。成功的話會傳回非0，失敗的話會傳回無法複製的資料長度。
 * 
 * 9. static inline __must_check unsigned long clear_user(void __user *to, unsigned long n)
 *     {
 *         might_sleep();
 *         if (!access_ok(VERIFY_WRITE, to, n))
 *             return n;
 * 
 *         return __clear_user(to, n);
 *     }
 *     從User Process的to指標指向的位置清除n個Byte。成功的話會傳回非0，失敗的話會傳回無法寫入0的長度。
 * 
 * 10. int capable(int cap);
 *     capable()是判斷User Process的執行權限。如CAP_SYS_ADMIN是判斷是否為"root"；至於還有哪些參考值可以用，請洽：
 *     /usr/src/kernels/2.6.33.3-85.fc13.i686.PAE/include/linux/capability.h
 * 
 * 11. 由上述可知，get_user()和put_user()可以讀寫的資料量太小，不切實際；現在多半以用copy_from_user()和copy_to_user()來取代；且在
 *     執行copy_from_user()和copy_to_user()時也同時包含了access_ok()函式。
 * 
 * 12. 此外，在早期的linux-2.4.x時期還有以下這4種函式：
 *     #define copy_to_user_ret(to, from, n, retval) ({if (copy_to_user(to,from,n)) return retval;})
 *     #define copy_from_user_ret(to, from, n, retval) ({if (copy_from_user(to,from,n)) return retval;})
 *     void get_user_ret(x, addr, ret); 
 *     void put_user_ret(x, addr, ret);
 *     *_ret()版本的函式與原本函式的差異在於：原本函式的回傳值，在*_ret()版本以Call by Reference的方式傳回。現在linux-2.6.x以後已經沒有
 *     了。
 * 
 * x. (To do something....)
 *
(*)?*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <asm/current.h>
#include <asm/uaccess.h>
#include <linux/ioctl.h>

struct example_data {
	unsigned char *val;
};

#define	IOC_MAGIC	'e'	// "'e'xample". 

struct ioctl_cmd {
	unsigned int reg;
	unsigned int offset;
	unsigned int val;
};

#define	IOCTL_VAL		_IO(IOC_MAGIC, 0)
#define	IOCTL_VALSET	_IOW(IOC_MAGIC, 1, struct ioctl_cmd)
#define	IOCTL_VALGET	_IOR(IOC_MAGIC, 2, struct ioctl_cmd)
#define	IOCTL_VALGETSET	_IOWR(IOC_MAGIC, 3, struct ioctl_cmd)

#endif
