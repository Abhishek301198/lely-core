/**@file
 * This header file is part of the I/O library; it contains the system signal
 * handler declarations.
 *
 * On POSIX platforms it is possible to monitor any defined signal except
 * SIGKILL and SIGSTOP, which cannot be caught. SIGABRT can only be caught if it
 * was raised explicitly with `raise()` or `pthread_kill()`. If raised by
 * `abort()`, the process will terminate once the (internal) signal handler
 * returns. Unless raised explicitly, monitoring SIGBUS, SIGFPE, SIGILL or
 * SIGSEGV can lead to undefined behavior, since wait operations are processed
 * asynchronously and do not allow the user to meaningfully respond to the error
 * that triggered the signal. Use `sigaction()` to handle those signals.
 *
 * @copyright 2018-2019 Lely Industries N.V.
 *
 * @author J. S. Seldenthuis <jseldenthuis@lely.com>
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

#ifndef LELY_IO2_SYS_SIGSET_H_
#define LELY_IO2_SYS_SIGSET_H_

#include <lely/io2/sigset.h>
#include <lely/io2/sys/io.h>

#ifdef __cplusplus
extern "C" {
#endif

void *io_sigset_alloc(void);
void io_sigset_free(void *ptr);
io_sigset_t *io_sigset_init(
		io_sigset_t *sigset, io_poll_t *poll, ev_exec_t *exec);
void io_sigset_fini(io_sigset_t *sigset);

/**
 * Creates a new system signal handler.
 *
 * @param poll a pointer to the I/O polling instance used to monitor signal
 *             events.
 * @param exec a pointer to the executor used to execute asynchronous tasks.
 *
 * @returns a pointer to a new signal handler, or NULL on error. In the latter
 * case, the error number can be obtained with get_errc().
 */
io_sigset_t *io_sigset_create(io_poll_t *poll, ev_exec_t *exec);

/// Destroys a system signal handler. @see io_sigset_create()
void io_sigset_destroy(io_sigset_t *sigset);

#ifdef __cplusplus
}
#endif

#endif // !LELY_IO2_SYS_SIGSET_H_
