/* SPDX-License-Identifier: GPL-2.0 */
/* Helpers the android-3.18 binder needs that kernel 3.14 doesn't have. */
#ifndef _BINDER_COMPAT_H
#define _BINDER_COMPAT_H
#include <linux/compiler.h>
#include <linux/sched/rt.h>

#ifndef READ_ONCE
#define READ_ONCE(x) ACCESS_ONCE(x)
#endif
#ifndef WRITE_ONCE
#define WRITE_ONCE(x, val) (ACCESS_ONCE(x) = (val))
#endif
#ifndef MAX_NICE
#define MAX_NICE 19
#define MIN_NICE -20
#endif
#ifndef NICE_TO_PRIO
#define NICE_TO_PRIO(nice) ((nice) + DEFAULT_PRIO)
#define PRIO_TO_NICE(prio) ((prio) - DEFAULT_PRIO)
#endif
static inline long rlimit_to_nice(long prio)
{
	return (MAX_NICE - prio + 1);
}
#endif
