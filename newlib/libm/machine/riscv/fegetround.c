/*
  (c) Copyright 2017 Michael R. Neilly
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

  * Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.

  * Neither the names of the copyright holders nor the names of their
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.
*/

#include <math.h>
#include <fenv.h>

/* This implementation is intended to comply with the following
 * specification:
 *
 * http://pubs.opengroup.org/onlinepubs/009695399/functions/fegetround.html
 * Referred to as 'fegetround.html below.
 *
 * "The fegetround() function shall get the current rounding direction."
 */

#if __RISCV_HARD_FLOAT
int fegetround(void)
{

  /* Get current rounding mode */

  fenv_t frm;
  __asm__ volatile("frrm %0" : "=r"(frm));

  /* Per 'fegetround.html:
   *
   * "The fegetround() function shall return the value of the rounding
   * direction macro representing the current rounding direction or a
   * negative value if there is no such rounding direction macro or
   * the current rounding direction is not determinable."
   */

  /* Return the rounding mode */

  return frm;

}
#else
#include "../../fenv/fegetround.c"
#endif

