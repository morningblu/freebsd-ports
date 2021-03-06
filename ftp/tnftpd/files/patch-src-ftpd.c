
Rewrite utmpx support.

--- src/ftpd.c.orig	2009-11-07 04:26:48.000000000 +0100
+++ src/ftpd.c	2009-11-07 04:26:48.000000000 +0100
@@ -504,9 +504,6 @@
 		confdir = _DEFAULT_CONFDIR;
 
 	if (dowtmp) {
-#ifdef SUPPORT_UTMPX
-		ftpd_initwtmpx();
-#endif
 #ifdef SUPPORT_UTMP
 		ftpd_initwtmp();
 #endif
@@ -1319,23 +1316,18 @@
 	(void)gettimeofday(&tv, NULL);
 #endif
 #ifdef SUPPORT_UTMPX
-	if (doutmp) {
+	if (doutmp || dowtmp) {
 		(void)memset(&utmpx, 0, sizeof(utmpx));
 		utmpx.ut_tv = tv;
 		utmpx.ut_pid = getpid();
-		utmpx.ut_id[0] = 'f';
-		utmpx.ut_id[1] = 't';
-		utmpx.ut_id[2] = 'p';
-		utmpx.ut_id[3] = '*';
+		snprintf(utmpx.ut_id, sizeof(utmpx.ut_id), "%xftp",
+		    utmpx.ut_pid);
 		utmpx.ut_type = USER_PROCESS;
-		(void)strncpy(utmpx.ut_name, name, sizeof(utmpx.ut_name));
+		(void)strncpy(utmpx.ut_user, name, sizeof(utmpx.ut_user));
 		(void)strncpy(utmpx.ut_line, line, sizeof(utmpx.ut_line));
 		(void)strncpy(utmpx.ut_host, host, sizeof(utmpx.ut_host));
-		(void)memcpy(&utmpx.ut_ss, &haddr->si_su, haddr->su_len);
-		ftpd_loginx(&utmpx);
+		(void)pututxline(&utmpx);
 	}
-	if (dowtmp)
-		ftpd_logwtmpx(line, name, host, haddr, 0, USER_PROCESS);
 #endif
 #ifdef SUPPORT_UTMP
 	if (doutmp) {
@@ -1355,17 +1347,23 @@
 logout_utmp(void)
 {
 #ifdef SUPPORT_UTMPX
-	int okwtmpx = dowtmp;
+	struct timeval tv;
+	(void)gettimeofday(&tv, NULL);
 #endif
 #ifdef SUPPORT_UTMP
 	int okwtmp = dowtmp;
 #endif
 	if (logged_in) {
 #ifdef SUPPORT_UTMPX
-		if (doutmp)
-			okwtmpx &= ftpd_logoutx(ttyline, 0, DEAD_PROCESS);
-		if (okwtmpx)
-			ftpd_logwtmpx(ttyline, "", "", NULL, 0, DEAD_PROCESS);
+		if (doutmp || dowtmp) {
+			(void)memset(&utmpx, 0, sizeof(utmpx));
+			utmpx.ut_tv = tv;
+			utmpx.ut_pid = getpid();
+			snprintf(utmpx.ut_id, sizeof(utmpx.ut_id), "%xftp",
+			    utmpx.ut_pid);
+			utmpx.ut_type = DEAD_PROCESS;
+			(void)pututxline(&utmpx);
+		}
 #endif
 #ifdef SUPPORT_UTMP
 		if (doutmp)
