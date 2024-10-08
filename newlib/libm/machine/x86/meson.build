#
# SPDX-License-Identifier: BSD-3-Clause
#
# Copyright © 2019 Keith Packard
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
# INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
# STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
# OF THE POSSIBILITY OF SUCH DAMAGE.
#
srcs_libm_machine_common = [
  'fenv.c',
  'feclearexcept.c',
  'fedisableexcept.c',
  'feenableexcept.c',
  'fegetenv.c',
  'fegetexcept.c',
  'fegetexceptflag.c',
  'fegetround.c',
  'feholdexcept.c',
  'feraiseexcept.c',
  'fesetenv.c',
  'fesetexceptflag.c',
  'fesetround.c',
  'fetestexcept.c',
  'feupdateenv.c',
]

srcs_libm_machine_32 = [
  'f_atan2f.S',
  'f_atan2.S',
  'f_exp.c',
  'f_expf.c',
  'f_frexpf.S',
  'f_frexp.S',
  'f_ldexpf.S',
  'f_ldexp.S',
  'f_llrint.c',
  'f_llrintf.c',
  'f_llrintl.c',
  'f_log10f.S',
  'f_log10.S',
  'f_logf.S',
  'f_log.S',
  'f_lrint.c',
  'f_lrintf.c',
  'f_lrintl.c',
  'f_math.h',
  'f_pow.c',
  'f_powf.c',
  'f_rint.c',
  'f_rintf.c',
  'f_rintl.c',
  'f_tanf.S',
  'f_tan.S',
]

srcs_libm_machine = srcs_libm_machine_common

src_libm_machine = []

foreach target : targets
  if target.startswith('32') or (target == '' and not is_x86_64)
    src_libm_machine_target = srcs_libm_machine_common + srcs_libm_machine_32
  else
    src_libm_machine_target = srcs_libm_machine_common
  endif
  set_variable('src_libm_machine' + target, files(src_libm_machine_target))
endforeach
