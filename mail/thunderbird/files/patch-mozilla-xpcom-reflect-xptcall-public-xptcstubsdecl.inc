--- mozilla/xpcom/reflect/xptcall/public/xptcstubsdecl.inc.orig	Tue Mar 16 03:07:25 2004
+++ mozilla/xpcom/reflect/xptcall/public/xptcstubsdecl.inc	Tue Jun 15 12:52:36 2004
@@ -8,7 +8,7 @@
 *  1 is AddRef
 *  2 is Release
 */
-#if !defined(__ia64) || (!defined(__hpux) && !defined(__linux__))
+#if !defined(__ia64)
 NS_IMETHOD Stub3();
 NS_IMETHOD Stub4();
 NS_IMETHOD Stub5();
