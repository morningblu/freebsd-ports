--- src/gmpnumbers.cpp.orig	Tue Dec 10 01:30:35 2002
+++ src/gmpnumbers.cpp	Fri Apr 11 02:53:35 2003
@@ -6,6 +6,7 @@
  */
 
 #include <gmp.h>
+#include <math.h>
 // do not use math.h without necessity
 /*
 #ifdef HAVE_MATH_H
@@ -81,25 +82,19 @@
 
 void initGMPNumber(GMPNumber& x, GMPNumber& y)
 {
-  mpz_t man;
-  mpz_init_set(man,y.man);
-  x.man = man;
+  mpz_init_set(x.man,y.man);
   x.exp = y.exp;
 }
 
 void initGMPNumber(GMPNumber& x, long y)
 {
-  mpz_t man;
-  mpz_init_set_ui(man,y);
-  x.man = man;
+  mpz_init_set_ui(x.man,y);
   x.exp = 0;
 }
 
 void initGMPNumber(GMPNumber& x, mpz_t mpz)
 {
-  mpz_t man;
-  mpz_init_set(man,mpz);
-  x.man = man;
+  mpz_init_set(x.man,mpz);
   x.exp = 0;
 }
 
@@ -148,11 +143,9 @@
     exp++;
   }
   if (!*man) {*man='0';*(man+1)='\0';neg=0;exp=0;}
-  mpz_t ma;
-  mpz_init_set_str(ma,man,10);
+  mpz_init_set_str(x.man,man,10);
   free(man);
-  if(neg)mpz_neg(ma,ma);
-  x.man=ma;
+  if(neg)mpz_neg(x.man,x.man);
   x.exp=exp;
 }
 
@@ -169,7 +162,7 @@
   free(str);
 }
 
-char* getstrGMPNumber(GMPNumber& x, long prec=0)
+char* getstrGMPNumber(GMPNumber& x, long prec)
 {
   long rawsize = mpz_sizeinbase(x.man,10);
   size_t size;
@@ -240,7 +233,7 @@
 }
 
 static LispStringPtr GMPNumberToString(GMPNumber& x, LispHashTable& h, 
-                                       LispInt prec=0)
+                                       LispInt prec)
 {
   char* result = getstrGMPNumber(x, prec);
   LispStringPtr toreturn = h.LookUp(result);
