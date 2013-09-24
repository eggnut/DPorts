--- libstdc++-v3/config/os/bsd/dragonfly/ctype_noninline.h.orig	2013-09-24 12:45:38.152815000 +0000
+++ libstdc++-v3/config/os/bsd/dragonfly/ctype_noninline.h
@@ -0,0 +1,98 @@
+// Locale support -*- C++ -*-
+
+// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2009, 2010
+//  Free Software Foundation, Inc.
+//
+// This file is part of the GNU ISO C++ Library.  This library is free
+// software; you can redistribute it and/or modify it under the
+// terms of the GNU General Public License as published by the
+// Free Software Foundation; either version 3, or (at your option)
+// any later version.
+
+// This library is distributed in the hope that it will be useful,
+// but WITHOUT ANY WARRANTY; without even the implied warranty of
+// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+// GNU General Public License for more details.
+
+// Under Section 7 of GPL version 3, you are granted additional
+// permissions described in the GCC Runtime Library Exception, version
+// 3.1, as published by the Free Software Foundation.
+
+// You should have received a copy of the GNU General Public License and
+// a copy of the GCC Runtime Library Exception along with this program;
+// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
+// <http://www.gnu.org/licenses/>.
+
+/** @file bits/ctype_noninline.h
+ *  This is an internal header file, included by other library headers.
+ *  Do not attempt to use it directly. @headername{locale}
+ */
+
+//
+// ISO C++ 14882: 22.1  Locales
+//
+
+// Information as gleaned from /usr/include/ctype.h
+
+#ifdef _CTYPE_S
+  extern "C" const unsigned long __libc_C_ctype_[];
+#else
+  extern "C" const __uint16_t __libc_C_ctype_[];
+#endif
+
+  const ctype_base::mask*
+  ctype<char>::classic_table() throw()
+  { return __libc_C_ctype_ + 1; }
+
+  ctype<char>::ctype(__c_locale, const mask* __table, bool __del,
+		     size_t __refs)
+  : facet(__refs), _M_del(__table != 0 && __del),
+  _M_toupper(NULL), _M_tolower(NULL),
+  _M_table(__table ? __table : classic_table())
+  {
+    memset(_M_widen, 0, sizeof(_M_widen));
+    _M_widen_ok = 0;
+    memset(_M_narrow, 0, sizeof(_M_narrow));
+    _M_narrow_ok = 0;
+  }
+
+  ctype<char>::ctype(const mask* __table, bool __del, size_t __refs)
+  : facet(__refs), _M_del(__table != 0 && __del),
+  _M_toupper(NULL), _M_tolower(NULL),
+  _M_table(__table ? __table : classic_table())
+  {
+    memset(_M_widen, 0, sizeof(_M_widen));
+    _M_widen_ok = 0;
+    memset(_M_narrow, 0, sizeof(_M_narrow));
+    _M_narrow_ok = 0;
+  }
+
+  char
+  ctype<char>::do_toupper(char __c) const
+  { return ::toupper((int) __c); }
+
+  const char*
+  ctype<char>::do_toupper(char* __low, const char* __high) const
+  {
+    while (__low < __high)
+      {
+	*__low = ::toupper((int) *__low);
+	++__low;
+      }
+    return __high;
+  }
+
+  char
+  ctype<char>::do_tolower(char __c) const
+  { return ::tolower((int) __c); }
+
+  const char*
+  ctype<char>::do_tolower(char* __low, const char* __high) const
+  {
+    while (__low < __high)
+      {
+	*__low = ::tolower((int) *__low);
+	++__low;
+      }
+    return __high;
+  }
