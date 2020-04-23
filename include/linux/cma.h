/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __CMA_H__
#define __CMA_H__

#include <linux/init.h>
#include <linux/types.h>
#include <linux/list.h>
#include <linux/mm_types.h>

/*
 * There is always at least global CMA area and a few optional
 * areas configured in kernel .config.
 */
#ifdef CONFIG_CMA_AREAS
#define MAX_CMA_AREAS	(1 + CONFIG_CMA_AREAS)

#else
#define MAX_CMA_AREAS	(0)

#endif
struct cma;

extern int continuous_ptable_enable;
extern long min_continuous_ptable;
extern long max_continuous_ptable;

extern int continuous_ptable_size;
extern long min_continuous_ptable_size;
extern long max_continuous_ptable_size;

struct ctl_table;
int continuous_ptable_size_handler(struct ctl_table *table, int write,
			     void __user *buffer, size_t *lenp,
			     loff_t *ppos); 

int continuous_ptable_enable_handler(struct ctl_table *table, int write,
			     void __user *buffer, size_t *lenp,
			     loff_t *ppos);
#define MAX_PROCESSES (10)

extern struct cma_pte_pool *register_continuous_ptable(pid_t pid);
extern void release_continuous_ptable(struct cma_pte_pool *ptable);
extern struct page *cma_pte_alloc(struct mm_struct *mm, size_t count, unsigned int order);


extern unsigned long totalcma_pages;
extern phys_addr_t cma_get_base(const struct cma *cma);
extern unsigned long cma_get_size(const struct cma *cma);
extern const char *cma_get_name(const struct cma *cma);

extern int __init cma_declare_contiguous(phys_addr_t base,
			phys_addr_t size, phys_addr_t limit,
			phys_addr_t alignment, unsigned int order_per_bit,
			bool fixed, const char *name, struct cma **res_cma);
extern int cma_init_reserved_mem(phys_addr_t base, phys_addr_t size,
					unsigned int order_per_bit,
					const char *name,
					struct cma **res_cma);
extern struct page *cma_alloc(struct cma *cma, size_t count, unsigned int align,
			      bool no_warn);
extern bool cma_release(struct cma *cma, const struct page *pages, unsigned int count);

extern int cma_for_each_area(int (*it)(struct cma *cma, void *data), void *data);
#endif
