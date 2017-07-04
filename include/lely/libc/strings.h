/*!\file
 * This header file is part of the C11 and POSIX compatibility library; it
 * includes `<strings.h>`, if it exists, and defines any missing functionality.
 *
 * \copyright 2017 Lely Industries N.V.
 *
 * \author J. S. Seldenthuis <jseldenthuis@lely.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LELY_LIBC_STRINGS_H
#define LELY_LIBC_STRINGS_H

#include <lely/libc/libc.h>

#ifndef LELY_HAVE_STRINGS_H
#if (_POSIX_C_SOURCE >= 200112L || defined(__NEWLIB__)) \
		 && __has_include(<strings.h>)
#define LELY_HAVE_STRINGS_H	1
#endif
#endif

#if LELY_HAVE_STRINGS_H
#include <strings.h>
#else

#include <stddef.h>

#ifndef LELY_LIBC_STRINGS_INLINE
#define LELY_LIBC_STRINGS_INLINE	inline
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * Finds the index of the first (least significant) bit set in \a i. Bits are
 * numbered counting from 1.
 *
 * \returns the index of the first bit set, or 0 if \a i is 0.
 */
#if (defined(__GNUC__) || __has_builtin(__builtin_ffs)) \
			&& !defined(__BSD_VISIBLE)
LELY_LIBC_STRINGS_INLINE int __cdecl ffs(int i) { return __builtin_ffs(i); }
#else
LELY_LIBC_EXTERN int __cdecl ffs(int i);
#endif

/*!
 * Compares the string at \a s1 to the string at \a s2, ignoring differences in
 * case.
 *
 * \returns an integer greater than, equal to, or less than 0 if the string at
 * \a s1 is greater than, equal to, or less than the string at \a s2.
 */
LELY_LIBC_EXTERN int __cdecl strcasecmp(const char *s1, const char *s2);

/*!
 * Compares at most \a n characters from the the string at \a s1 to the string
 * at \a s2, ignoring differences in case.
 *
 * \returns an integer greater than, equal to, or less than 0 if the string at
 * \a s1 is greater than, equal to, or less than the string at \a s2.
 */
LELY_LIBC_EXTERN int __cdecl strncasecmp(const char *s1, const char *s2,
		size_t n);

#ifdef __cplusplus
}
#endif

#endif // LELY_HAVE_STRINGS_H

#endif

